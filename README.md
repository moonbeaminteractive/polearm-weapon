# polearm-weapon
pole rod staff based weapon for short range area events

##Concept: 
Wand/rod is a weapon which can cast three different kinds of spells by sending sound signals to the vest. The kind of spell is visualized by the led strip on the wand. There will be deplay between each spell, and the delay time can be shortened by one of the pickups. In order to cast a spell, the player has to both swing the rod to activate it and push one of the three buttons to cast a specific type of spell. 

##Software: 
Statistic.h  <br/>
Adafruit_DotStar.h <br/>

Statistic.h: calculates the swing variance of the gyro sensor  <br/>
Adafruit_DotStar.h: controls the RGB lighting on the led strip  <br/>


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
![Design](https://github.com/moonbeaminteractive/polearm-weapon/blob/master/Design/model.png)

###Paper Prototype:
![Paper](https://github.com/moonbeaminteractive/polearm-weapon/blob/master/Design/paperprototype.jpg)  

###Final Wand: 
![Wand](https://github.com/moonbeaminteractive/polearm-weapon/blob/master/Design/final.jpg)

