# Software Report
This report discusses the code used for both the vehicles and controllers for the project.

## Software Used
Used in: Arduino 1.8.16
The coding for the project has two main files which are all used through an Arduino. The two file codes are the controller file which is the transmitter.ino and the vehicle file which is the receiver.ino.

### TRANSMITTER.ino
The transmitter.ino file contains all the code for the controller to be able to control the cars per the user inputs. The only library that is needed to be installed for the code to work is LiquidCrystal_I2C. This makes it so the model attached to the lcd is converted from multiple pins to only 4 pins needed to connect to the controller. Important note for power is for a wireless controller, a power supply is given. The power supply needs to be connected to the Vin pin with the red wire and GND pin with the black wire.

### (Joysticks Section)
The left joystick code only reads the y position of the joystick, which then reads the position. Anything above the position of 500 will be considered a forward input to the vehicle and anything less than 500 will be considered backwards input.

#### RECEIVER.ino
The receiver.ino file contains all the code for the vehicle to read the inputs of the controller and adjust the motors. No additional files are needed for the code to work successfully. The Arduino code can be uploaded directly to and Arduino nano and should work properly. The code will always go through a while loop when the radio is avaliable in that channel. If available, the code will obtain a 3-bit message sent from the controller and go through if statements to see which message was detected. There are 8 available 3-bit messages to send. 7 of those messages are to determine the action of the motors which include moving forward, backwards, left, right, or not move at all.
