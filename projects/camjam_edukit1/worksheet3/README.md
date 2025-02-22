# Worksheet 3 - Blinking LEDs

The objective is to make the three LEDs (red, yellow, and green) blink.

Download the instructions [here](https://github.com/CamJam-EduKit/EduKit1/raw/master/CamJam%20EduKit%201%20-%20GPIO%20Zero/CamJam%20EduKit%201%20%20-%20Worksheet%203%20(GPIO%20Zero)%20-%20Blinking%20LEDs.pdf).

## Python

The code provided in the worksheet wasn't destined to work on QNX 8.0. It uses functions and libraries that are not available in QNX 8.0, like the ```gpiozero``` library.

To make the code work on QNX 8.0, we need to use the ```rpi_gpio``` library provided in the Raspberry Pi 4 QNX 8.0 Quick Start Target Image.

## C

Last time we interacted with the GPIO through ```/dev/gpio```. This time we will use the GPIO registers directly.

According to the [BCM2711 ARM Peripherals](https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2711/rpi_DATA_2711_1p0.pdf) manual, the GPIO registers are mapped to the address ```0x7E200000``` (32 bits mode). However, if you look at the code of the Raspberry Pi BSP, you will see that the GPIO registers are mapped to the address ```0xFE200000``` (Low Peripheral mode).

So, we will use the second address to access the GPIO registers.

As we will interact with the pins 18, 23 and 24, we will use the GPFSEL1 (pin 18) and the GPFSEL2 (pins 23 and 24) registers to configure the pins as output.

To set the pins to high or low, we will use the GPSET0 and GPCLR0 registers.