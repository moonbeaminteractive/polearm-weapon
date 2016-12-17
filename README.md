# polearm-weapon
pole rod staff based weapon for short range area events

##Software: 
Statistic.h 
Adafruit_DotStar.h

Statistic.h: calculates the swing variance of the gyro sensor 
Adafruit_DotStar.h: controls the RGB lighting on the led strip 


##Hardware: 
1 x gyro sensor 
1 x magnetic buzzer
1 x dotstar led strip
1 x arduino mini
3 x push button
1 x USB-B

Gyro sensor: detects if the rod is activated or not. Player will swing the rod to activate the weapon.
Magnetic buzzer: sends sound signal to receivers installed on vests
Dotstar led strip: displays which spell just casted by the player (r, g, b)
Push button: each color of the push button (r, g, b) will send a different kind of spells
USB-B: receives serial information from the vest for shorter spell recharge delay

##Circuit and PCB Design Process: 
We started with a very simple board – an Arduino Uno, an infrared emitter, a push button and a led strip. Then we improved it by adding more components and functionalities to the board – we added a tilt sensor switch for activation, a 6 degree of freedom sensor, a Piezo buzzer for casting different spells, a nrf24l01 for Bluetooth communication, and replaced the Arduino Uno with Arduino Pro Mini. In the next phase, we replaced the 6 degree of freedom sensor with a gyro sensor and removed the tilt switch as we decided to only use swing behavior to activate the wand, which could be achieved by just using the gyro sensor. We also added three kinds of buttons, imaging the player can perform different kinds of combinations of buttons for different spells. Then we moved on to the communication with the other parts. We realized that it would work the best if we communicated with the vest directly using serial via TX/RX pins instead of Bluetooth. Finally, the design we have right now has a USB-B for serial communication with the vest, removing the Bluetooth module. 
In order to fit the PCB into the wand, we wanted to limit its width to around 3.5 cm. We decided to put the gyro sensor and buzzer at the top of the wand for more accurate measurement. The initial PCB design was just about 3.6 cm. Matt helped us to produce the final design, which used the small resistor and a more compact layout to reduce the width to 3.4 cm. It also added two transistors for 5.0 V power supply. These tiny resistors and transistors saved lots of space for PCB design.



###Circuit
![Circuit](https://github.com/moonbeaminteractive/polearm-weapon/blob/master/hardware/circuit.PNG)  


###PCB
![PCB](https://github.com/moonbeaminteractive/polearm-weapon/blob/master/hardware/PCB.PNG)  

