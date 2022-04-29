# Software Report
This report discusses the code used for both the vehicles and controllers for the project.

## Software Used
Used in: Arduino 1.8.16
The coding for the project has two main files which are all used through an Arduino. The two file codes are the controller file which is the transmitter.ino and the vehicle file which is the receiver.ino.

### TRANSMITTER.ino
The transmitter.ino file contains all the code for the controller to be able to control the cars per the user inputs. The only library that is needed to be installed for the code to work is LiquidCrystal_I2C. This makes it so the model attached to the lcd is converted from multiple pins to only 4 pins needed to connect to the controller. Important note for power is for a wireless controller, a power supply is given. The power supply needs to be connected to the Vin pin with the red wire and GND pin with the black wire.

### (Joysticks Section)
The left joystick code only reads the y position of the joystick, which then reads the position. Anything above the position of 500 will be considered a forward input to the vehicle and anything less than 500 will be considered backwards input.
