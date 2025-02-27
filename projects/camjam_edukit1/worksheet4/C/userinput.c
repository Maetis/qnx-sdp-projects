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

    // Ask the user which colour LED to blink 
    printf("Which colour LED would you like to blink? (red, yellow, green):\n");
    printf("1. Red\n");
    printf("2. Yellow\n");
    printf("3. Green\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    // Ask the user how many times they want the LED to blink
    printf("How many times would you like the LED to blink?\n");
    int times;
    scanf("%d", &times);

    // Sets the variable 'LEDChoice' to be the LED choice 
    int LEDChoice;
    if (choice == 1) {
        printf("You chose Red\n");
        LEDChoice = 18;
    } else if (choice == 2) {
        printf("You chose Yellow\n");
        LEDChoice = 23;
    } else if (choice == 3) {
        printf("You chose Green\n");    
        LEDChoice = 24;
    }

    // Blink the LED the number of times the user specified
    for (int i = 0; i < times; i++) {
        // Set GPIO pin to high
        gpio_base[GPSET0] = (1 << LEDChoice);

        // Wait for 1 second
        sleep(1);

        // Set GPIO pin to low
        gpio_base[GPCLR0] = (1 << LEDChoice);

        // Wait for 1 second
        sleep(1);
    }
    
    return EXIT_SUCCESS;
}