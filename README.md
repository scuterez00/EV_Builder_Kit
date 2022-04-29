# EV_Builder_Kit Engineering Addendum
Erbyn Bonilla, Henry Chong, Stephanie Cuterez, Linglong Le, Michelle Imogu

EC464 - Spring 2022

## Summary and Project Motivation
As countries and institutions start pushing to replace fossil fuel driven vehicles with zero emission vehicles such as electric cars, there will inevitably be skepticism and doubt expressed towards this change. These doubts have a variety of sources, whether it be a lack of familiarity with how electric vehicles work, or a belief that electric vehicles cannot operate as well as gas powered vehicles. To combat these sources of doubt, this project will create a small-scale model of a transportation grid completely powered by electric vehicles. There will be multiple small vehicles that users can drive around and link with provided charging stations for recharging. These vehicles will transmit mileage and battery charge remaining in the model car to the users. A set of controllers will also be provided for user interaction with the model, allowing people to come up and drive the vehicles around.  Charging stations utilizing a variety of methods, ranging from solar panels to outlet power, will be provided for recharging the vehicles. And everything will be integrated into a set of roads and decorations to create a semi-realistic transportation system. This will create an electric vehicle kit that will show the operation cycle of electric vehicles. In the process of using the kit, users will be provided with a clear demonstration of the process of charging, driving, and recharging the vehicles. 

## Main Features of this Repository
As of now, the repository contains all the schematics needed for the replication of the casing and circuitry of two items: the electric vehicles and the controllers for these electric vehicles. Associated datasheets and schematics for this portion of the project can be accessed using [README_HARDWARE.md](README_HARDWARE.md). Additionally, this repository also contains the code that must be uploaded to the microcontrollers on the cars and controllers for the communications between the two to begin. For a brief summary of the code please view [README_SOFTWARE.md](README_SOFTWARE.md).

## Current State of the Project
### Cars
The information in this repo corresponds to a set of working electric vehicles that can drive forwards, backwards, and turn in response to a users inputs on an associated controller. The car is capable of sending relevant battery data to the controller via the transceiver, and displays the current state of control using LEDs. When the power is switched off the car is still capable of charging via a DC jack connected to either a solar panel or a DC adapter, or a USB-C cable.

The method the cars use to drive around is via differential drive, meaning that the two back wheels can rotate independently of each other, while the front wheels are left to be free spinning. This was done to reduce the amount of motor drivers required as compared to four wheel drive, and reduce the complexity of the mechanical system required to create front wheels for facilitating turning.

One thing to note is that no PCB was utilized for any of the electronics, and as a result there are no PCB files available for creating the circuitry outlined in the hardware report. Similarly no CAD was utilized for the creation of the car bodies, so no files are available for quickly reproducing the bodies via machining.


### Controllers
The information in this repo corresponds to a working controller that can communicate with the cars, and display relevant details about the car onto the attached LCD. Using the joysticks, the user will be able to control the vehicle, while the toggle switches are used to switch which vehicle is being controlled. The controller provided here uses 3 switches to toggle between 3 possible cars for control. The controller is powered using 4 AA batteries, and as a result requires new batteries to be provided upon running out of charge.

The current set-up of the controller is so that the left joystick is pushed vertically to control the car's forward/reverse motion, while the right joystick is pushed horizontally to cause the car to turn. To know which car the controller is controlling, flip the switches to toggle between vehicles, and look for the vehicle with a lit up LED. The LED corresponds to having an open reading pipeline to receive controller data.

### Track and Surrounding Model
Tracks and auxiliary models such as grass, trees and buildings were also used in the project, but have not been included in this repository. This is because the models were purchased and not designed, thus their CAD files and designs cannot be placed into this repository. As for the track, this track simply consists of adhesive black tape laid out onto flat boards to denote roadway, and as a result not included in this repository either.

## Things to look out for
- Depending on the type of microcontroller you are using, specific drivers will be required. In our case we were not using official Arduino Nano microcontrollers for our project, thus we had to use the CH340 drivers. If you are using official microcontrollers these drivers will not be needed.
- The nRF24L01 transceivers have only a single pipeline for communication, which means that they cannot transmit and receive at the same time. To circumvent this our code uses cycles to switch between transmission and reception mode on the transceivers of the controllers and the cars. The controller's transceiver first sends out a specific message while swapping to receiving. This message will cause the transceiver on the car to close the pipeline, and then switch from receiving to transmitting, before transmitting a message. Once the controller transceiver receives this message, they send out another signal which will return the controller's transceiver to transmission mode and the car's transceiver to reception mode.
- Due to the use of differential drive, the center of gravity of the the vehicle, along with the traction of the wheels are critical for the cars to handle properly. This means that the center of gravity should be shifted towards the central axis of the differnetial drive.

## Known Bugs
- Occasionally the cars will become completely unresponsive to the controller, and switching the power button will not be able to solve this. To fix this issue unplug the battery from the car, then flip the power switch 5 times. After this you can replug the battery and the system should work again.
