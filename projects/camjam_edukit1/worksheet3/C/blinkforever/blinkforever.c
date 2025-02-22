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

int main() {
    volatile uint32_t *gpio_base;

    gpio_base = mmap_device_memory(0, BLOCK_SIZE, PROT_READ | PROT_WRITE | PROT_NOCACHE, 0, GPIO_BASE_ADDR);
    if (gpio_base == MAP_FAILED) {
        perror("mmap_device_memory");
        return EXIT_FAILURE;
    }

    // Set GPIO pins as output
    gpio_base[GPFSEL1] |= (1 << 24); // GPIO 18
    gpio_base[GPFSEL2] |= (1 << 9);  // GPIO 23
    gpio_base[GPFSEL2] |= (1 << 12); // GPIO 24

    do {
        // Set GPIO pins to high
        gpio_base[GPSET0] = (1 << 18) | (1 << 23) | (1 << 24);

        // Wait for 1 second
        printf("Waiting for one second\n");
        sleep(1);

        // Set GPIO pins to low
        gpio_base[GPCLR0] = (1 << 18) | (1 << 23) | (1 << 24);

        // Wait for 1 second
        printf("Waiting for one second\n");
        sleep(1);
    } while (1);

    // Clean up
    //munmap(gpio_base, BLOCK_SIZE);
    return EXIT_SUCCESS;
}