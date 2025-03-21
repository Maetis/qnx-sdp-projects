#include <stdio.h>
#include <stdlib.h>
#include <sys/neutrino.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

#define GPIO_BASE_ADDR 0xFE200000

#define BLOCK_SIZE (4*1024)

#define GPFSEL1 1
#define GPFSEL2 2

#define GPSET0 7
#define GPCLR0 10

#define GPLEV0 13
#define GPLEV1 14
#define GPIO_PUP_PDN_CNTRL_REG1 58

void dot(volatile uint32_t *gpio_base) {
    gpio_base[GPSET0] = 1 << 11;
    delay(100);
    gpio_base[GPCLR0] = 1 << 11;
    delay(100);
}

void dash(volatile uint32_t *gpio_base) {
    gpio_base[GPSET0] = 1 << 11;
    delay(300);
    gpio_base[GPCLR0] = 1 << 11;
    delay(100);
}

void letter_space() {
    delay(200);
}

void word_space() {
    delay(600);
}

void morse_s(volatile uint32_t *gpio_base) {
    dot(gpio_base);
    dot(gpio_base);
    dot(gpio_base);
}

void morse_o(volatile uint32_t *gpio_base) {
    dash(gpio_base);
    dash(gpio_base);
    dash(gpio_base);
}

int main() {
    volatile uint32_t *gpio_base;

    gpio_base = mmap_device_memory(0, BLOCK_SIZE, PROT_READ | PROT_WRITE | PROT_NOCACHE, 0, GPIO_BASE_ADDR);
    if (gpio_base == MAP_FAILED) {
        perror("mmap_device_memory");
        return EXIT_FAILURE;
    }

    // Set GPIO pin 11 as output
    gpio_base[GPFSEL1] |= (1 << 3); // GPIO 11
    
    // Prompt the user for input
    printf("How many times would you like SOS to loop? \n");
    int loop_count;
    scanf("%d", &loop_count);
    
    for (int i = 0; i < loop_count; i++) {
        morse_s(gpio_base);
        letter_space();
        morse_o(gpio_base);
        letter_space();
        morse_s(gpio_base);
        word_space();
    }

    return EXIT_SUCCESS;
}