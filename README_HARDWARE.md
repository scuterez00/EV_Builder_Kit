# Hardware Report
This is a report which covers the fundamentals of the hardware, including both the circuitry and the casing/bodies made to house the products.

## Cars
This section will deal with the circuitry and casing for the electric cars.

### Car Bodies
**Car Front:**
![Car Front](/Images/Car/Car_Front.JPG)

**Car Side:**
![Car Side](/Images/Car/Car_Side.JPG)

**Car Back:**
![Car Back](/Images/Car/Car_Back.JPG)

**Car Bottom:**
![Car Bottom](/Images/Car/Car_Bottom.JPG)
  Shown here are 4 views of one of the fully assembled cars. The car in question here is a Light Duty Vehicle(LDV) Equivalent. The car body was made using 1/8" thick Medium-Density Fiberboard(MDF) and 2" by 1" wood planks. The MDF board is used to house the circuit tower and mount the motors and weight, while the wood plank is used to hold the front wheels in place, using nails. Holes were drilled into the MDF board for the purpose of screwing in the circuitry components. A large hole was drilled into the bottom of the 2" by 1" plank so that screws could be attached to hold the entire circuit tower in place.

### Car Circuitry
**Circuit Tower Bottom:**
![Circuit Tower Bottom](/Images/Car/Circuit_Bottom.JPG)
  The circuitry from the car is soldered onto two breadboards, and mounted one on top of the other using PCB screws. The picture above shows three major components: the motor driver, the battery monitoring chip, and the voltage regulator. The motor driver is responsible for controlling motor speed and direction, while the battery monitoring chip provides data on the battery charge and state. The voltage regulator is used to convert the 3.7 Volts from the lithium polymer(LiPo) battery to 5 Volts for the rest of the system. One thing to note is that the on-off switch attached to the vehicle is linked to the Enable(EN) pin of the voltage regulator. When the switch is turned off the EN pin is pulled to ground, disabling the 5 Volt output powering the car circuitry, while keeping the battery connected to the charging circuit.

**Circuit Tower Top:**
![Circuit Tower Top](/Images/Car/Circuit_Top.JPG)
  Shown here is the top of the circuitry tower, which contains the following: the NRF24L01 transceiver chip, the microcontroller (an Elegoo Nano), and the LiPo Charging chip. The transceiver is responsible for communication between the car and the controllers, while the microcontroller is responsible for performing all the computations and translations necessary to control each component of the car. The LiPo Charging chip is attached to provide a regulated method of charging the LiPo battery, utilizing either a 3.5 mm DC jack, or a USB type C Cable. Also shown here are LEDs attached to provide the user feedback on control and charging.

### Car Circuit Schematic
![image](https://user-images.githubusercontent.com/74795368/165640060-bbe30a24-28e5-4a18-b645-b129249c1591.png)
[Link to PDF](/Circuit_Schematics/Car_Circuit_Abstraction.pdf)
![image](https://user-images.githubusercontent.com/74795368/165640042-de89219c-cf17-487c-97ad-1129df1fb366.png)
[Link to PDF](/Circuit_Schematics/Car_Circuit.pdf)
 
Shown here is a circuit diagram and an associated abstraction. Essentially the circuit can be split up into two different components, the battery circuit and the operational circuit. The operational circuit operates on 5 volts and consists of: the microcontroller, voltage regulator, motor driver, motors, and transceiver. This circuit is what drives radio communication and driving of the car. The battery circuit on the other hand consists of the LiPo Fuel Gauge and the LiPo Charging Chip, and serves to monitor and recharge the battery. The output of the battery circuit is fed to the voltage regulator to actually power the rest of the operational circuit. Thus by turning off the voltage regulator using a switch, we are able to maintain the ability to charge the battery while cutting power off from the car.

### Car Body Schematic
![image](https://user-images.githubusercontent.com/74795368/165643972-cb1862c7-8c90-45af-9fd8-f76641012f2d.png)
[Link to PDF](/Hardware_Schematics/Car_Schematic.pdf)

Shown here is the drawing used to create the body of the cars. This is the drawing for the LDV variant of the cars. The body is made up of two main components: the 1/8" thick MDF board and the 2" by 1" wood plank. The MDF board is drilled so that all the circuit components can be attached using screws, while the plank is super glued to the front of the MDF board, for mounting the wheels. Once all the circuitry has been attached and screwed in, steel weights are then added to the back of the vehicle, to improve the vehicle's handling by shifting the center of gravity towards the motored wheels. No CAD files were created as all components were made by hand.

### Bill of Materials
#### Light Duty Vehicle(LDV) variant Car

This bill of materials covers the material needed to create one LDV car, and does not include components such as nails, screws and wires.

| Item | Amount | Vendor | Datasheet Link |
| --------------- | :---------------: | :---------------: |:---------------: |
| Microcontroller | 1 | Amazon | [Link](/Data_Sheets/Nano_Pinouts.pdf)|
| Transciever | 1 | Amazon | [Link](/Data_Sheets/nRF24L01_Datasheet.pdf)|
| Battery Monitoring Chip| 1 | Adafruit  | [Link](/Data_Sheets/Battery_Monitor_Datasheet.pdf)|
| Battery Charging Chip | 1 | Adafruit | [Link](/Data_Sheets/Charger_Datasheet.pdf)|
| Battery | 1 | Adafruit |  [Link](/Data_Sheets/Battery_Datasheet.pdf)|
| Voltage Regulator| 1 | Pololu |  [Link](/Data_Sheets/Pololu_Regulator_Sheets/Chip_Datasheet.pdf)| 
| Motor Controller | 1 | Adafruit | [Link](/Data_Sheets/Motor_Driver_Datasheet.pdf)| 
| Plastic Motor | 2 | Pololu | [Link](/Data_Sheets/Plastic_Motor_Specifications.pdf)|  
| Motor Wheels | 2| Pololu | [Link](/Data_Sheets/Dimensions/Pololu_Wheel_Dimensions.pdf)|
| Plastic Motor Brackets | 2 | Pololu | [Link](/Data_Sheets/Dimensions/Plastic_Motor_Mounts_Dimensions.pdf) |
| Front Wheels | 2 | Amazon | [Link](https://www.amazon.com/gp/product/B073W18BP3) |
| Steel Weights | 10 | Amazon | [Link](https://www.amazon.com/gp/product/B06XDHXRT7)|
| Solderable Breadboard | 2 | Adafruit | [Link](https://www.adafruit.com/product/1609)|
| LEDs | 2 | Amazon | N/A |
| 1/8" MDF Board| 1 | Home Depot | N/A |
| 2" by 1" Plank | 1 | Home Depot | N/A |

#### Heavy Duty Vehicle(HDV) variant Car

This bill of materials covers the material needed to create one HDV car, and does not include components such as nails, screws and wires.

| Item | Amount | Vendor | Datasheet Link |
| --------------- | :---------------: | :---------------: |:---------------: |
| Microcontroller | 1 | Amazon | [Link](/Data_Sheets/Nano_Pinouts.pdf)|
| Transciever | 1 | Amazon | [Link](/Data_Sheets/nRF24L01_Datasheet.pdf)|
| Battery Monitoring Chip| 1 | Adafruit  | [Link](/Data_Sheets/Battery_Monitor_Datasheet.pdf)|
| Battery Charging Chip | 1 | Adafruit | [Link](/Data_Sheets/Charger_Datasheet.pdf)|
| Battery | 1 | Adafruit |  [Link](/Data_Sheets/Battery_Datasheet.pdf)|
| Voltage Regulator| 1 | Pololu |  [Link](/Data_Sheets/Pololu_Regulator_Sheets/Chip_Datasheet.pdf)| 
| Motor Controller | 1 | Adafruit | [Link](/Data_Sheets/Motor_Driver_Datasheet.pdf)| 
| Metal Motor | 2 | Pololu | [Link](/Data_Sheets/Metal_Motor_Datasheet.pdf)|  
| Motor Wheels | 2| Pololu | [Link](/Data_Sheets/Dimensions/Pololu_Wheel_Dimensions.pdf)|
| Metal Motor Brackets | 2 | Pololu | [Link](/Data_Sheets/Dimensions/Metal_Motor_Mount_Dimensions.jpg) |
| Front Wheels | 2 | Amazon | [Link](https://www.amazon.com/gp/product/B073W18BP3) |
| Steel Weights | 30 | Amazon | [Link](https://www.amazon.com/gp/product/B06XDHXRT7)|
| Solderable Breadboard | 2 | Adafruit | [Link](https://www.adafruit.com/product/1609)|
| LEDs | 2 | Amazon | N/A |
| 1/8" MDF Board| 1 | Home Depot | N/A |
| 2" by 1" Plank | 1 | Home Depot | N/A |

## Controllers
This section will deal with the circuitry and casing for the controllers.

### Assembled Controller

**Controller Top:**
![Controller Top](/Images/Controller/Controller_Top.JPG)
**Controller Side:**
![Controller Side](/Images/Controller/Controller_Side.JPG)
**Controller Bottom:**
![Controller Bottom](/Images/Controller/Controller_Bottom.JPG)
**Controller Held:**
![Controller Held](/Images/Controller/Controller_Held.JPG)

  Shown here are 4 views of one of the fully assembled controller. The controller body was made using 1/8" thick Medium-Density Fiberboard(MDF). Holes were drilled into the MDF board for the purpose of screwing in the joysticks, LCD, and toggle switches. Additional holes were also made for the purpose of routing wire from the bottom of the controller to the top, which has the breadboard attached. On the breadboard itself is simply a microcontroller and an attached NRF24l01 transciever. Taped to the back is the battery pack, which can be switched on or off to provide power to the controller.
  On the controller there are three toggle switches in the center, and LCD, and two joysticks. The joysticks are responsible for taking user input and converting that into motion on the cars. The left joystick is pushed forward/back to control the cars forward or reversing speed, while the right joystick is pushed horizontally to turn the car. The toggle switches are used to switch between cars, as each controller is capable of communicating with up to 3 cars. And the LCD is responsible for displaying the battery life and mileage remaining on each of the cars.
  
### Controller Circuit Schematic
![image](https://user-images.githubusercontent.com/74795368/165649225-096b2f3b-132b-4085-8893-0d432939a31c.png)
[Link to PDF](/Circuit_Schematics/Controller_Circuit_Abstraction.pdf)
![image](https://user-images.githubusercontent.com/74795368/165649187-36e824a3-b0b5-40b9-81e3-0d6510a1b7f7.png)
[Link to PDF](/Circuit_Schematics/Controller_Circuit.pdf)

As shown in the circuit diagram and abstraction, the controller circuit is only one circuit, which uses the microcontroller as the central hub. The battery pack routes power to the microcontroller, which then takes inputs from the various switches and joysticks on the controller. Once the inputs have been received, the microcontroller translates them into packets to be sent via the transceiver. However the transceiver also receives packets and sends these packets to the microcontroller, which then translates these packets into information, and displays this information onto the LCD.

### Controller Body Schematic
![image](https://user-images.githubusercontent.com/74795368/165649635-fd1e970c-26ed-44ff-a192-cf0d10c5edb6.png)
[Link to PDF](/Hardware_Schematics/Controller_Schematic.pdf)

This details the size of holes, and location of holes required to be drilled into a 1/8" thick MDF board for all the components to be properly screwed in. No CAD Files were created as all components were made by hand. 

### Bill of Materials

This bill of materials covers the material needed to create one controller, and does not include components such as nails, screws and wires.

| Item | Amount | Vendor | Datasheet Link |
| --------------- | :---------------: | :---------------: |:---------------: |
| Microcontroller | 1 | Amazon | [Link](/Data_Sheets/Nano_Pinouts.pdf)|
| Transciever | 1 | Amazon | [Link](/Data_Sheets/nRF24L01_Datasheet.pdf)|
| Breadboard | 1 | Adafruit | [Link](https://www.adafruit.com/product/4539)|
| Battery Pack | 1 | Adafruit |  [Link](/Data_Sheets/Battery_Pack_Datasheet.pdf)|
| Joystick | 2 | Amazon | [Link](https://www.amazon.com/ARCELI-Joystick-Controller-Dual-axis-Breakout/dp/B077Z8QN3S)| 
| Toggle Switch | 3 | Amazon | [Link](https://www.amazon.com/Gikfun-MTS102-Position-Toggle-Arduino/dp/B01BWL7Z44)|  
| LCD Display | 1 | Amazon | [Link](https://www.amazon.com/gp/product/B01GPUMP9C)|
| AA Batteries | 4 | Adafruit |  N/A | 
| 1/8" MDF Board| 1 | Home Depot | N/A |
