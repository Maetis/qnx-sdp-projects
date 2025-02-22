# CamJam EduKit 1 - Basics
# Worksheet 3 - Blinking LEDs

# Import Libraries
import rpi_gpio as GPIO
import time # A collection of time related commands

# Set pins 18, 23 and 24 to be output
GPIO.setup(18, GPIO.OUT)
GPIO.setup(23, GPIO.OUT)
GPIO.setup(24, GPIO.OUT)

while True:
    # Turn the LEDs on
    GPIO.output(18, GPIO.HIGH)
    GPIO.output(23, GPIO.HIGH)
    GPIO.output(24, GPIO.HIGH)

    # Wait for one second
    time.sleep(1)

    # Turn the LEDs off
    GPIO.output(18, GPIO.LOW)
    GPIO.output(23, GPIO.LOW)
    GPIO.output(24, GPIO.LOW)

    # Wait for one second
    time.sleep(1)
