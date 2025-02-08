# CamJam EduKit 1 - Basics
# Worksheet 2 - LEDs

# Import Libraries
import time # A collection of time related commands
import rpi_gpio as GPIO

# Set pins 18, 23 and 24 to be output
GPIO.setup(18, GPIO.OUT)
GPIO.setup(23, GPIO.OUT)
GPIO.setup(24, GPIO.OUT)

print("LEDs on")
GPIO.output(18, GPIO.HIGH)
GPIO.output(23, GPIO.HIGH)
GPIO.output(24, GPIO.HIGH)

print("Waiting for one second")
time.sleep(1)

print("LEDs off")
GPIO.output(18, GPIO.LOW)
GPIO.output(23, GPIO.LOW)
GPIO.output(24, GPIO.LOW)