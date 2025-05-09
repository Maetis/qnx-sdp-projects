#include <stdio.h>
#include <stdlib.h>
#include <sys/neutrino.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

#define GPIO_BASE_ADDR 0xFE200000

#define BLOCK_SIZE (4*1024)

#define GPFSEL0 0
#define GPFSEL1 1
#define GPFSEL2 2

#define GPSET0 7
#define GPCLR0 10

#define GPLEV0 13
#define GPLEV1 14
#define GPIO_PUP_PDN_CNTRL_REG0 57
#define GPIO_PUP_PDN_CNTRL_REG1 58


// Initialise the GPIO pins
void init_gpio(volatile uint32_t *gpio_base)
{
    gpio_base[GPFSEL0] &= ~(7 << 6); // Set GPIO 2 as input
    gpio_base[GPFSEL1] |= (1 << 15); // Set GPIO 15 as output
    gpio_base[GPFSEL2] |= (1 << 15); // Set GPIO 25 as output
    gpio_base[GPFSEL0] |= (1 << 24); // Set GPIO 8 as output
    gpio_base[GPFSEL0] |= (1 << 21); // Set GPIO 7 as output
    gpio_base[GPIO_PUP_PDN_CNTRL_REG0] &= ~(3 << 4);
    // gpio_base[GPIO_PUP_PDN_CNTRL_REG0] |= (1 << 4);
}

// Define a function for the initial state
void start_green(volatile uint32_t *gpio_base) 
{
    printf("Green light\n");
    gpio_base[GPSET0] |= 1 << 7;
    gpio_base[GPCLR0] |= 1 << 8;
    gpio_base[GPCLR0] |= 1 << 25;
    gpio_base[GPCLR0] |= 1 << 15;
}

// Turn the green off and the amber on for 3 seconds
void steady_amber(volatile uint32_t *gpio_base)
{
    printf("Amber light\n");
    gpio_base[GPCLR0] = 1 << 7;
    gpio_base[GPSET0] = 1 << 8;
    gpio_base[GPCLR0] = 1 << 25;
    gpio_base[GPCLR0] = 1 << 15;
    delay(3000);
}

// Turn the amber off, and then the red on for 1 second
void steady_red(volatile uint32_t *gpio_base)
{
    printf("Red light\n");
    gpio_base[GPCLR0] = 1 << 7;
    gpio_base[GPCLR0] = 1 << 8;
    gpio_base[GPSET0] = 1 << 25;
    gpio_base[GPCLR0] = 1 << 15;
    delay(1000);
}

// Sound the buzzer for 4 seconds
void start_walking(volatile uint32_t *gpio_base)
{
    printf("Start walking\n");
    gpio_base[GPCLR0] = 1 << 7;
    gpio_base[GPCLR0] = 1 << 8;
    //gpio_base[GPCLR0] = 1 << 25;
    // Make the buzzer buzz on and off, half a second of
    // sound followed by half a second of silence
    for (int i = 0; i < 4; i++)
    {
        gpio_base[GPSET0] = 1 << 15;
        delay(500);  // 0.5 seconds
        gpio_base[GPCLR0] = 1 << 15;
        delay(500);  // 0.5 seconds
    }
    delay(500);  // 0.5 seconds
}

// Turn the buzzer off and wait for 2 seconds
void dont_walk(volatile uint32_t *gpio_base)
{
    printf("Don't walk\n");
    gpio_base[GPCLR0] = 1 << 15;
    delay(2000);
}

// Flash the amber and green lights for 6 seconds
void flashing_amber_green(volatile uint32_t *gpio_base)
{
    printf("Flashing amber and green\n");
    for (int i = 0; i < 6; i++)
    {
        gpio_base[GPSET0] = 1 << 8;
        delay(500);
        gpio_base[GPCLR0] = 1 << 8;
        delay(500);
    }
}

// Flash the amber for one more second
void flashing_amber(volatile uint32_t *gpio_base)
{
    printf("Flashing amber\n");
    gpio_base[GPSET0] = 1 << 8;
    delay(500);
    gpio_base[GPCLR0] = 1 << 8;
    delay(500);
}

// Go through the traffic light sequence by calling the functions above
void traffic_light_sequence(volatile uint32_t *gpio_base)
{
    printf("Traffic light sequence\n");
    steady_amber(gpio_base);
    steady_red(gpio_base);
    start_walking(gpio_base);
    dont_walk(gpio_base);
    flashing_amber_green(gpio_base);
    flashing_amber(gpio_base);
    start_green(gpio_base);
}

int main() {
    volatile uint32_t *gpio_base;
    int button_not_pressed = 1;

    gpio_base = mmap_device_memory(0, BLOCK_SIZE, PROT_READ | PROT_WRITE | PROT_NOCACHE, 0, GPIO_BASE_ADDR);
    if (gpio_base == MAP_FAILED) {
        perror("mmap_device_memory");
        return EXIT_FAILURE;
    }

    init_gpio(gpio_base);
    
    printf("Traffic Lights\n");

    start_green(gpio_base);
    
    while (1) {
        button_not_pressed = 1;
        // Record the current time
        time_t start_time = time(NULL);
        
        while (button_not_pressed)
        {
            delay(500);
            // Check if the button has been pressed
            if (!(gpio_base[GPLEV0] & (1 << 2))) {
                printf("Button pressed\n");
                button_not_pressed = 0;
                time_t now = time(NULL);
                if ((now - start_time) <= 20) {
                    delay(20000 - (now - start_time) * 100);
                    traffic_light_sequence(gpio_base);
                }
            }
        }
        
    }

    return EXIT_SUCCESS;
}