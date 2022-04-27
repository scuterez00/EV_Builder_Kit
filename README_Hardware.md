# Hardware Report
This is a report which covers the fundamentals of the hardware, including both the circuitry and the casing/bodies made to house the products.

## Cars
This section will deal with the circuitry and hardware for the vehicles used

### Car Bodies
**Car Front:**
![Car Front](/Images/Car/Car_Front.JPG)

**Car Side:**
![Car Side](/Images/Car/Car_Side.JPG)

**Car Back:**
![Car Back](/Images/Car/Car_Back.JPG)

**Car Bottom:**
![Car Bottom](/Images/Car/Car_Bottom.JPG)
  Shown here are 4 views of one of the fully assembled cars. The car in question here is a Light Duty Vehicle(LDV) Equivalent. The car body was made using 1/8" thick Medium-Density Fiberboard(MDF) and 2" by 1" wood planks. The MDF board is used to house the circuit tower and mount the motors and weight, while the wood plank is used to hold the front wheels in place, using nails. Holes were drilled into the MDF board for the purpose of screwing in the circuitry components. A large hole was drilled into the bottom of the 2" by 1" plank so that screws could be attached to hold the entire cirrcuit tower in place.

### Car Circuitry
**Circuit Tower Bottom:**
![Circuit Tower Bottom](/Images/Car/Circuit_Bottom.JPG)
  The circuitry from the car is soldered onto two solderable breadboards, and mounted one on top of the other using PCB screws. The picture above shows three major components: the motor driver, the battery monitoring chip, and the voltage regulator. The motor driver is responsible for controlling motor speed and direction, while the battery monitoring chip provides data on the battery charge and state. The voltage regulator is used to convert the 3.7 Volts from the lithium polymer(LiPo) battery to 5 Volts for the rest of the system. One thing to note is that the on-off switch attached to the vehicle is linked to the Enable(EN) pin of the voltage regulator. When the switch is turned off the EN pin is pulled to ground, disabling the 5 Volt output powering the car circuitry, while keeping the battery connected to the charging circuit.

**Circuit Tower Top:**
![Circuit Tower Top](/Images/Car/Circuit_Top.JPG)
  Shown here is the top of the circuitry tower, which contains the following: the NRF24L01 transciever chip, the microcontroller (an Elegoo Nano), and the LiPo Charging chip. The transciever is responsible for communication between the car and the controllers, while the microcontroller is responsible for performing all the computations and translations necessary to control each component of the car. The LiPo Charging chip is attached to provide a regulated method of charging the LiPo battery, utilizing either a 3.5 mm DC jack, or a USB type C Cable. Also shown here are LEDs attached to provide the user feedback on control and charging.

### Car Circuit Schematic
![image](https://user-images.githubusercontent.com/74795368/165640042-de89219c-cf17-487c-97ad-1129df1fb366.png)
![image](https://user-images.githubusercontent.com/74795368/165640060-bbe30a24-28e5-4a18-b645-b129249c1591.png)
  Shown here is a circuit diagram and an associated abstraction. Essentially the circuit can be split up into two different components, the battery circuit and the operational circuit. The operational circuit operates on 5 volts and consists of: the microcontroller, voltage regulator, motor driver, motors, and transciever. This circuit is what drives radio communication and driving of the car. The battery circuit on the other hand consists of the LiPo Fuel Gauge and the LiPo Charging Chip, and serves to monitor and recharge the battery. The output of the battery circuit is fed to the voltage regulator to actually power the rest of the operational circuit. Thus by turning off the voltage regulator using a switch, we are able to maintain the ability to charge the battery while cutting power off from the car.

### Car Body Schematic
  Schematic+Explaination
### Bill of Materials
  Table with Vendor names and Links, and amounts. Links to datasheet sections/asset
### Datasheets
  List significant Datasheets

## Controllers
### Assembled Controller
  Pictures of actual Controller
### Controller Circuit Schematic
  Schematic+Explaination
### Circuit Body Schematic
  Schematic+Explaination
### Bill of Materials
  Table with Vendor names and Links, and amounts. Link relevant datasheets here as well
### Datasheets
  List significant Datasheets
