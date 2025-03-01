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

int main() {
    volatile uint32_t *gpio_base;

    gpio_base = mmap_device_memory(0, BLOCK_SIZE, PROT_READ | PROT_WRITE | PROT_NOCACHE, 0, GPIO_BASE_ADDR);
    if (gpio_base == MAP_FAILED) {
        perror("mmap_device_memory");
        return EXIT_FAILURE;
    }

    // Set GPIO pin 25 as a pull-up input
    gpio_base[GPFSEL2] &= ~(7 << 15);
    gpio_base[GPIO_PUP_PDN_CNTRL_REG1] &= ~(3 << 18);
    gpio_base[GPIO_PUP_PDN_CNTRL_REG1] |= (1 << 18);


    printf("-------------\n"); 
    printf("Button + GPIO\n");
    printf("-------------\n");
    
    // The commands indented after this ‘while’ will be repeated 
    // forever or until ‘Ctrl+c’ is pressed. 

    printf("Waiting for you to press the button\n"); 
    while (1) {
        // Read the value of GPIO pin 25
        uint32_t value = gpio_base[GPLEV0] & (1 << 25);
        if (!value) {
            printf("Button pressed\n");
            sleep(1);
        } 
        //delay(1000);
        sleep(.5);
    }

    return EXIT_SUCCESS;
}