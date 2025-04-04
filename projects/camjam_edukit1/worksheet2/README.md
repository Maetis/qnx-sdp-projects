# Worksheet 2 - LEDs

The objective is to light up three LEDs (red, yellow and green), wait for a second delay, and then turn them off.

Download the instructions [here](https://github.com/CamJam-EduKit/EduKit1/raw/master/CamJam%20EduKit%201%20-%20GPIO%20Zero/CamJam%20EduKit%201%20%20-%20Worksheet%202%20(GPIO%20Zero)%20-%20LEDs.pdf).

## Python

The code provided in the worksheet wasn't destined to work on QNX 8.0. It uses functions and libraries that are not available in QNX 8.0, like the ```gpiozero``` library.

To make the code work on QNX 8.0, we need to use the ```rpi_gpio``` library provided in the Raspberry Pi 4 QNX 8.0 Quick Start Target Image.

## C

As there is no library provided in the Raspberry Pi 4 QNX 8.0 Quick Start Target Image to interact with the GPIO, we will interact with it through ```/dev/gpio```.