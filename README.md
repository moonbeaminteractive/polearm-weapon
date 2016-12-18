# polearm-weapon
pole rod staff based weapon for short range area events

##Concept: 
Wand/rod is a weapon which can cast three different kinds of spells by sending sound signals to the vest. The kind of spell is visualized by the led strip on the wand. There will be deplay between each spell, and the delay time can be shortened by one of the pickups. In order to cast a spell, the player has to both swing the rod to activate it and push one of the three buttons to cast a specific type of spell. 

##Software: 

Prerequisite libraries:  <br/>
Statistic.h  <br/>
Adafruit_DotStar.h <br/>

Statistic.h: calculates the swing variance of the gyro sensor  <br/>
Adafruit_DotStar.h: controls the RGB lighting on the led strip  <br/>


The software continuously polls the 3 rod buttons (red, green, blue) to select a spell. <br/>
Also, it continuously logs ADXL accelerometer data in blocks of 100 values and calculates the variance of the samples. Using the variance instead of the raw values allows the tracking of rapid wand motions to cast a spell, no matter what the initial direction of the wand is. <br/>

When casting each spell, the DotStar LEDs light up with the respective color (blue for the blue button, red for the red button, green for the green button) to conveniently visualize which spell has been selected. Additional functionality is implemented to drive a buzzer with a frequency that depends on the spell that is casted. For the red spell, a buzzer tone with period of 100 ms is generated, for the green a tone with 200 ms period is generated, and for the blue a tone with 300 ms period is generated. <br/>

Time-sensitive functions of the code have been implemented with the millis() function to avoid blocking that the delay() function introduces. <br/>

##Usage Settings:
Current settings:<br/>
Default blockout - 30 seconds (slow recharge)<br/>
Blockout with pickup - 10 seconds (faster boosted recharge)<br/>

When a weapon booster pickup is correctly attached, the wand flashes 5 times to notify the user that it has detected and activated it. The wand glows a default yellow color when active, and whenever a spell is castable. If it is timed out, on blockout after casting a spell, all lights on the wand will switch off until it is recharged again. On casting a spell, the wand glows the same color as the spell.<br/>

To use, plug in a USB-A to USB-B connector between the wand and the vest.<br/>




##Hardware: 
1 x gyro sensor <br/>
1 x magnetic buzzer <br/>
1 x dotstar led strip <br/>
1 x arduino mini <br/>
3 x push button <br/>
1 x USB-B <br/>

Gyro sensor: detects if the rod is activated or not. Player will swing the rod to activate the weapon <br/>
Magnetic buzzer: sends sound signal to receivers installed on vests <br/>
Dotstar led strip: displays which spell just casted by the player (r, g, b) <br/>
Push button: each color of the push button (r, g, b) will send a different kind of spells <br/>
USB-B: receives serial information from the vest for shorter spell recharge delay <br/>

##Circuit and PCB Design Process: 
We started with a very simple board – an Arduino Uno, an infrared emitter, a push button and a led strip. Then we improved it by adding more components and functionalities to the board – we added a tilt sensor switch for activation, a 6 degree of freedom sensor, a Piezo buzzer for casting different spells, a nrf24l01 for Bluetooth communication, and replaced the Arduino Uno with Arduino Pro Mini. In the next phase, we replaced the 6 degree of freedom sensor with a gyro sensor and removed the tilt switch as we decided to only use swing behavior to activate the wand, which could be achieved by just using the gyro sensor. We also added three kinds of buttons, imaging the player can perform different kinds of combinations of buttons for different spells. Then we moved on to the communication with the other parts. We realized that it would work the best if we communicated with the vest directly using serial via TX/RX pins instead of Bluetooth. Finally, the design we have right now has a USB-B for serial communication with the vest, removing the Bluetooth module. 

In order to fit the PCB into the wand, we wanted to limit its width to around 3.5 cm. We decided to put the gyro sensor and buzzer at the top of the wand for more accurate measurement. The initial PCB design was just about 3.6 cm. Matt helped us to produce the final design, which used the small resistor and a more compact layout to reduce the width to 3.4 cm. It also added two transistors for 5.0 V power supply. These tiny resistors and transistors saved lots of space for PCB design.


###Circuit
![Circuit](https://github.com/moonbeaminteractive/polearm-weapon/blob/master/hardware/circuit.PNG)  

###PCB
![PCB](https://github.com/moonbeaminteractive/polearm-weapon/blob/master/hardware/PCB.PNG)  

###Fabrication Design: 
The design of weapon was in lowpoly style and we have a good rationale for the design.

The sytle of the design is futuristic overall and lowpoly design fits in the game.
Using lowpoly design, we are able to build three-dimensional objects by two dimensional materials like paper by folding them. In this way, we are able to put whatever electronics and PCB boards into it without destroying the idea of the weapon being a wand.
The design was generated by sketching, modelling and finally drawings. The tools used were Illustrator, Rhino and special thanks to Clement, whose tools helped with generating joints for the design.

As for the prototyping, We laser cut (using Epilog Mini Laser Cutter) the design using chipboard.

For the materials, we hesitated between plastic, yupo paper, chipboard as well as metal. Eventually, due to cost, the feasibility of laser cutting as well as the imagined final demonstration, we decided to have black chipboards serving as surfaces.

The output of laser film printer appears some errors because of mechanical manufacture and different settings of power and speed. The drawings were drawn in both AutoCAD and Illustrator. Dimensions in drawings were decided by both measurements and repetitive trail and error.

A challenge we encountered was to fit in the PCB boards and placing buttons, electronics at the right position, which wasted a lot of trails and time.

Deciding settings of power and speed was another challenge for us. Although each material corresponds to its suggested settings, materials produced by different manufacturers perform differently under the same setting. We kept adjusting the settings to cut through acrylic sheets but at the same time prevent it from melting and blackening. The final prototype was actually our fifth version of printing..
![Design](https://github.com/moonbeaminteractive/polearm-weapon/blob/master/Design/model.png)

###Paper Prototype:
![Paper](https://github.com/moonbeaminteractive/polearm-weapon/blob/master/Design/paperprototype.jpg)  

###Final Wand: 
![Wand](https://github.com/moonbeaminteractive/polearm-weapon/blob/master/Design/final.jpg)

