# CamJam EduKit 1 - Basics
# Worksheet 5 - Button

# Import Libraries
import time # A collection of time related commands
import os  # Allows you to interact with the operating system 
import rpi_gpio as GPIO

# Set pin 25 as a button input 
GPIO.setup(25, GPIO.IN, GPIO.PUD_UP)

print("-------------") 
print("Button + GPIO") 
print("-------------")

# The commands indented after this ‘while’ will be repeated 
# forever or until ‘Ctrl+c’ is pressed. 
while True: 
    # If the button is pressed, button.is_pressed will be 'true' 
    if (GPIO.input(25) == GPIO.LOW): 
        print("Button pressed") 
        time.sleep(1) # Sleep for 1 second 
    else: 
        os.system("clear") # Clears the screen 
        print("Waiting for you to press the button") 
    time.sleep(0.5) # Sleep for 0.5 seconds

