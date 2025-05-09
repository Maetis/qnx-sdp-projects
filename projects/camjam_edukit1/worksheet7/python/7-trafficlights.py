# CamJam EduKit 1 - Basics
# Worksheet 7 - Traffic Lights Template

# Import Libraries
import os
import time  # Proves time related commands
import rpi_gpio as GPIO  # The GPIO functions

# Set up variables for the LED, Buzzer and switch pins
red = 25
amber = 8
green = 7
button = 2
buzzer = 15
# Set up the GPIO pins
GPIO.setup(red, GPIO.OUT)
GPIO.setup(amber, GPIO.OUT)
GPIO.setup(green, GPIO.OUT)
GPIO.setup(button, GPIO.IN, GPIO.PUD_UP)
GPIO.setup(buzzer, GPIO.OUT)

# Set up variables to hold the current state of the LEDs
GPIO.output(green, GPIO.LOW)
GPIO.output(amber, GPIO.LOW)
GPIO.output(red, GPIO.LOW)
GPIO.output(buzzer, GPIO.LOW)

# Define a function for the initial state (Green LED on, rest off)
def startgreen():
    GPIO.output(green, GPIO.HIGH)
    GPIO.output(amber, GPIO.LOW)
    GPIO.output(red, GPIO.LOW)
    GPIO.output(buzzer, GPIO.LOW)

# Turn the green off and the amber on for 3 seconds
def steadyamber():
    GPIO.output(green, GPIO.LOW)
    GPIO.output(amber, GPIO.HIGH)
    GPIO.output(red, GPIO.LOW)
    time.sleep(3)

# Turn the amber off, and then the red on for 1 second
def steadyred():
    GPIO.output(green, GPIO.LOW)
    GPIO.output(amber, GPIO.LOW)
    GPIO.output(red, GPIO.HIGH)
    time.sleep(1)

# Sound the buzzer for 4 seconds
def startwalking():
    for i in range(4):
        GPIO.output(buzzer, GPIO.HIGH)
        time.sleep(0.5)
        GPIO.output(buzzer, GPIO.LOW)
        time.sleep(0.5)
    time.sleep(0.5)

# Turn the buzzer off and wait for 2 seconds
def dontwalk():
    GPIO.output(buzzer, GPIO.LOW)
    time.sleep(2)

# Flash the amber an and of for 6 seconds
def flashingambergreen():
    for i in range(6):
        GPIO.output(amber, GPIO.HIGH)
        time.sleep(0.5)
        GPIO.output(amber, GPIO.LOW)
        time.sleep(0.5)

# Flash the amber for one more second
def flashingamber():
    GPIO.output(amber, GPIO.HIGH)
    time.sleep(0.5)
    GPIO.output(amber, GPIO.LOW)
    time.sleep(0.5)

# Go through the traffic light sequence by calling each function
# one after the other.
def trafficlightsequence():
    steadyamber()
    steadyred()
    startwalking()
    dontwalk()
    flashingambergreen()
    flashingamber()
    startgreen()

os.system('clear')
print("Traffic Lights")
startgreen()

# Here is the loop that will waits at least 20 seconds before
# stopping the cars if the button has been pressed.

while True:
    buttonnotpressed = True
    start = time.time()
    while buttonnotpressed:
        time.sleep(0.1)
        if GPIO.input(button) == GPIO.LOW:
            now = time.time()
            buttonnotpressed = False
            if (now - start) <= 20:
               time.sleep(20 - (now - start))
               trafficlightsequence()