# Hardware Report
This is a report which covers the fundamentals of the hardware, including both the circuitry and the casing/bodies made to house the products.

## Cars
This section will deal with the circuitry and hardware for the vehicles used
### Assembled Cars
![Circuit Tower Bottom](/Images/Car/Car_Top.jpg)

Shown here are 4 views of one of the fully assembled cars. The car in question here is a Light Duty Vehicle(LDV) Equivalent. The car body was made using 1/8" thick Medium-Density Fiberboard(MDF) and 2" by 1" wood planks. The MDF board is used to house the circuit tower and mount the motors and weight, while the wood plank is used to hold the front wheels in place, using nails. Holes were drilled into the MDF board for the purpose of screwing in the circuitry components. A large hole was drilled into the bottom of the 2" by 1" plank so that screws could be attached to hold the entire cirrcuit tower in place.

The circuitry from the car is soldered onto two solderable breadboards, and mounted one on top of the other using PCB screws. The picture captioned "Circuit Tower Bottom" holds three components: the motor driver, the battery monitoring chip, and the voltage regulator. The motor driver is responsible for controlling motor speed and direction, while the battery monitoring chip provides data on the battery charge and state. The voltage regulator is used to convert the 3.7 Volts from the lithium polymer(LiPo) battery to 5 Volts for the rest of the system. 

The picture captioned "Circuit Tower Top" holds the other 3 components: the NRF24L01 transciever chip, the microcontroller (an Elegoo Nano), and the LiPo Charging chip. The transciever is responsible for communication between the car and the controllers, while the microcontroller is responsible for performing all the computations and translations necessary to control each component of the car. The LiPo Charging chip is attached to provide a regulated method of charging the LiPo battery, utilizing either a 3.5 mm DC jack, or a USB type C Cable.

### Car Circuit Schematic
  Schematic+Explaination
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
