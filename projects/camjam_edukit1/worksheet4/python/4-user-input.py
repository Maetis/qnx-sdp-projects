# CamJam EduKit 1 - Basics
# Worksheet 4 - User Input

# Import Libraries
import time # A collection of time related commands
import os  # Allows you to interact with the operating system 
import rpi_gpio as GPIO

# Set pins 18, 23 and 24 to be output
GPIO.setup(18, GPIO.OUT)
GPIO.setup(23, GPIO.OUT)
GPIO.setup(24, GPIO.OUT)

os.system('clear') # Clear the terminal

print("Which LED would you like to blink?") 
print("1: Red?") 
print("2: Yellow?") 
print("3: Green?") 
led_choice = input("Choose your option: ") 
# Ensure that the led_choice variable is a whole number (integer) 
led_choice = int(led_choice) 
 
# Ask the user how many times they want the LED to blink 
count = input("How many times would you like it to blink?") 
# Ensure that the count variable is a whole number (integer) 
count = int(count) 
 
# Sets the variable 'LEDChoice' to be the LED choice 
if led_choice == 1: 
    print("You picked the Red LED") 
    LEDChoice = 18 
elif led_choice == 2: 
    print("You picked the Yellow LED") 
    LEDChoice = 23 
elif led_choice == 3: 
    print("You picked the Green LED") 
    LEDChoice = 24 

# If we have chosen a valid choice, flash the LED 
if led_choice > 0: 
    # While the count variable is greater than zero 
    while count > 0: 
        GPIO.output(LEDChoice, GPIO.HIGH)  # Turn the chosen LED on 
        time.sleep(1)  # Sleep for 1 second 
        GPIO.output(LEDChoice, GPIO.LOW)  # Turn the chosen LED off 
        time.sleep(2)  # Sleep for 2 seconds 
        count = count - 1  # Decrease the count by one