# Software Report
This report discusses the code used for both the vehicles and controllers for the project.

## Software Used
Used in: Arduino 1.8.16
The coding for the project has two main files which are all used through an Arduino. The two file codes are the controller file which is the transmitter.ino and the vehicle file which is the receiver.ino.

## TRANSMITTER.ino
The transmitter.ino file contains all the code for the controller to be able to control the cars per the user inputs. The only library that is needed to be installed for the code to work is LiquidCrystal_I2C. This library can be installed from https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library.  This makes it so the model attached to the LCD is converted from multiple pins to only 4 pins needed to connect to the controller. Important note for power is for a wireless controller, a power supply is given. The power supply needs to be connected to the Vin pin with the red wire and GND pin with the black wire. The transmitter code will have a block of switch cases that detect which switches are toggled. There are a total of 3 toggle switches where each one controls a specific car by having a unique 6-bit address. Within the switch cases, there is a code running that will decrease the miles of the choosen vehicle. Once the miles reaches zero, it will go into a if statement where it will print on the LCD a 'needs charging' label. This will make it so that the specific switch case will be stuck in a while loop and prevent any additional 3-bit message to be sent which in turn prevents the vehicle from moving. Only when the user truns off the specific switch on another will it then go out of the loop.

### (Joysticks Section)
The left joystick code only reads the y position of the joystick, which then reads the position. Anything above the position of 500 will be considered a forward input to the vehicle and anything less than 500 will be considered backwards input. There are 7 possible positions that the joysticks can register with each one sending a 3-bit message which includes moving forward, backwards, left, right, different speeds, or not move at all. All of these messages are attached to the coordinate positions of the joysticks.

### (switch_to_receiver function)
The function will first send a 3-bit message to the receiver to let it know to switch from reading to writing. After, the trasmitter will switch the radio from writing to reading. It will wait a couple of cycles with the while loop until it detects that a radio channel is available. Once the radio channel is available, it will obtain a string of the battery level, which then will be converted to a float. The float will be displayed on the LCD so that the user can see it.

### (LCD)
The first thing that is needed is to set the pins that will be used to setup the LCD are Vdd, GND, and two pins on the board to print onto the LCD. The function needed to use the LCD is LiguidCrystal_I2C which will set up the LCD. During the setup block, the LCD prints the name of vehicle that we EV are imitating and labeling miles and battery. During the loop block, the LCD will print battery and milage of the choosen vehicle every so often.

## RECEIVER.ino
The receiver.ino file contains all the code for the vehicle to read the inputs of the controller and adjust the motors. The libraries that must be installed for the code to work are: Adafruit's LC709203F library, and the nRF24L01 libraries. The LC709203F library is required for the I2C communication of battery data from the connected chip to the microcontroller, while the nRF24L01 libraries are necessary for the transceiver. No additional files are needed for the code to work successfully. The Arduino code can be uploaded directly to an Arduino Nano and should work properly. The code will always go through a while loop when the radio is available in that channel. If available, the code will obtain a 3-bit message sent from the controller and go through if statements to see which message was detected. There are 8 available 3-bit messages to send. 7 of those messages are to determine the action of the motors which includes moving forward, backwards, left, right, adjusting speeds, or to not move at all. In addition there is a single line of code where and LED will turn on if the radio is available so that the user has a visual representation of what vehicle they are using.

### (transmitter function)
The transmitter function will activate once the receiver obtains the 3-bit message to switch from reading to writing. If this is shown, it will go into the if statement and convert the float battery percentage to a string so that it can be sent through the transmitter. Once it sends the message, the transmitter will then switch from writing to reading so that it can obtain more 3-bit messages.

## Drivers Required
In the case that you are not using official Arduino Microcontrollers for this project, then it will be necessary to install certain drivers for the code to upload properly. In most cases this will be the CH340 drivers.
