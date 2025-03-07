# Worksheet 6 - Buzzer

The objective is to generate morse code SOS using a buzzer.

Download the instructions [here](https://github.com/CamJam-EduKit/EduKit1/raw/master/CamJam%20EduKit%201%20-%20GPIO%20Zero/CamJam%20EduKit%201%20%20-%20Worksheet%206%20(Pico)%20-%20Buzzer.pdf).

## Python

The code provided in the worksheet wasn't destined to work on QNX 8.0. It uses functions and libraries that are not available in QNX 8.0, like the ```gpiozero``` library.

To make the code work on QNX 8.0, we need to use the ```rpi_gpio``` library provided in the Raspberry Pi 4 QNX 8.0 Quick Start Target Image.

## C

Since the worksheet 3 we will use directly the GPIO registers.