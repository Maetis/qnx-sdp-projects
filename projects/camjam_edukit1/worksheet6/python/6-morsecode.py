# CamJam Edukit 1 – Basic
# Worksheet 6 – Morse Code

# Import Libraries
import time  # Proves time related commands
import rpi_gpio as GPIO  # The GPIO functions

# Set pin 11 as a output
GPIO.setup(11, GPIO.OUT)



# Define some 'user-defined functions'
def dot():  # A single Morse dot
    GPIO.output(11, GPIO.HIGH)
    time.sleep(0.1)
    GPIO.output(11, GPIO.LOW)
    time.sleep(0.1)


def dash():  # A single Morse dash
    GPIO.output(11, GPIO.HIGH)
    time.sleep(0.3)
    GPIO.output(11, GPIO.LOW)
    time.sleep(0.1)


def letterSpace():  # The space between letters
    time.sleep(0.2)


def wordSpace():  # The space between words
    time.sleep(0.6)


def morseS():  # The Morse for S, ...
    dot()
    dot()
    dot()


def morseO():  # The Morse for O, ---
    dash()
    dash()
    dash()


print("Morse Code")

# Prompt the user for input
loop_count = input("How many times would you like SOS to loop? ")
loop_count = int(loop_count)  # Convert text to an integer

while loop_count > 0:  # Loop around the chosen amount
    morseS()
    letterSpace()
    morseO()
    letterSpace()
    morseS()
    wordSpace()
    loop_count -= 1