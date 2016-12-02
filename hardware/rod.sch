EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:w_device
LIBS:rod-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Rod"
Date "2016-11-22"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_01X12 P2
U 1 1 58347303
P 2550 2100
F 0 "P2" H 2550 2750 50  0000 C CNN
F 1 "CONN_01X12" V 2650 2100 50  0000 C CNN
F 2 "" H 2550 2100 50  0001 C CNN
F 3 "" H 2550 2100 50  0000 C CNN
	1    2550 2100
	0    -1   -1   0   
$EndComp
$Comp
L CONN_01X12 P1
U 1 1 5834738F
P 2550 1550
F 0 "P1" H 2550 2200 50  0000 C CNN
F 1 "CONN_01X12" V 2650 1550 50  0000 C CNN
F 2 "" H 2550 1550 50  0001 C CNN
F 3 "" H 2550 1550 50  0000 C CNN
	1    2550 1550
	0    -1   1    0   
$EndComp
$Comp
L CONN_01X05 P3
U 1 1 5840678B
P 3700 1400
F 0 "P3" H 3700 1700 50  0000 C CNN
F 1 "GYRO" V 3800 1400 50  0000 C CNN
F 2 "" H 3700 1400 50  0001 C CNN
F 3 "" H 3700 1400 50  0000 C CNN
	1    3700 1400
	0    -1   -1   0   
$EndComp
Text GLabel 3500 1600 3    60   Input ~ 0
GND
Text GLabel 3900 1600 3    60   Input ~ 0
PWR
$Comp
L R R1
U 1 1 58406A0D
P 4050 2350
F 0 "R1" V 4130 2350 50  0000 C CNN
F 1 "R" V 4050 2350 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 3980 2350 50  0001 C CNN
F 3 "" H 4050 2350 50  0000 C CNN
	1    4050 2350
	-1   0    0    1   
$EndComp
$Comp
L SW_PUSH SW1
U 1 1 58406ACB
P 3750 2100
F 0 "SW1" H 3900 2210 50  0000 C CNN
F 1 "SW_PUSH_R" H 3750 2020 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_PUSH-12mm" H 3750 2100 50  0001 C CNN
F 3 "" H 3750 2100 50  0000 C CNN
	1    3750 2100
	1    0    0    -1  
$EndComp
Text GLabel 3450 2100 0    60   Input ~ 0
PWR
Text GLabel 4050 2500 3    60   Input ~ 0
GND
Wire Wire Line
	4050 2100 4050 2200
Wire Wire Line
	4050 2100 4150 2100
Text GLabel 4150 2100 2    60   Input ~ 0
4
$Comp
L R R2
U 1 1 58406D61
P 5200 2350
F 0 "R2" V 5280 2350 50  0000 C CNN
F 1 "R" V 5200 2350 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 5130 2350 50  0001 C CNN
F 3 "" H 5200 2350 50  0000 C CNN
	1    5200 2350
	-1   0    0    1   
$EndComp
$Comp
L SW_PUSH SW2
U 1 1 58406D67
P 4900 2100
F 0 "SW2" H 5050 2210 50  0000 C CNN
F 1 "SW_PUSH_G" H 4900 2020 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_PUSH-12mm" H 4900 2100 50  0001 C CNN
F 3 "" H 4900 2100 50  0000 C CNN
	1    4900 2100
	1    0    0    -1  
$EndComp
Text GLabel 4600 2100 0    60   Input ~ 0
PWR
Text GLabel 5200 2500 3    60   Input ~ 0
GND
Wire Wire Line
	5200 2100 5200 2200
Wire Wire Line
	5200 2100 5300 2100
Text GLabel 5300 2100 2    60   Input ~ 0
3
$Comp
L R R3
U 1 1 58406E3E
P 6350 2350
F 0 "R3" V 6430 2350 50  0000 C CNN
F 1 "R" V 6350 2350 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 6280 2350 50  0001 C CNN
F 3 "" H 6350 2350 50  0000 C CNN
	1    6350 2350
	-1   0    0    1   
$EndComp
$Comp
L SW_PUSH SW3
U 1 1 58406E44
P 6050 2100
F 0 "SW3" H 6200 2210 50  0000 C CNN
F 1 "SW_PUSH_B" H 6050 2020 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_PUSH-12mm" H 6050 2100 50  0001 C CNN
F 3 "" H 6050 2100 50  0000 C CNN
	1    6050 2100
	1    0    0    -1  
$EndComp
Text GLabel 5750 2100 0    60   Input ~ 0
PWR
Text GLabel 6350 2500 3    60   Input ~ 0
GND
Wire Wire Line
	6350 2100 6350 2200
Wire Wire Line
	6350 2100 6450 2100
Text GLabel 6450 2100 2    60   Input ~ 0
2
$Comp
L CONN_01X04 P4
U 1 1 5840776A
P 4450 1400
F 0 "P4" H 4450 1650 50  0000 C CNN
F 1 "DOTSTAR" V 4550 1400 50  0000 C CNN
F 2 "" H 4450 1400 50  0001 C CNN
F 3 "" H 4450 1400 50  0000 C CNN
	1    4450 1400
	0    -1   -1   0   
$EndComp
Text GLabel 4300 1600 3    60   Input ~ 0
GND
Text GLabel 4600 1600 3    60   Input ~ 0
PWR
Text GLabel 4400 1600 3    60   Input ~ 0
6
Text GLabel 4500 1600 3    60   Input ~ 0
7
$Comp
L buzzer BZ1
U 1 1 58408201
P 5000 1400
F 0 "BZ1" H 5075 1450 50  0000 L CNN
F 1 "buzzer" H 5075 1350 50  0000 L CNN
F 2 "Buzzers_Beepers:MagneticBuzzer_Kingstate_KCG0601" H 5000 1400 60  0001 C CNN
F 3 "" H 5000 1400 60  0000 C CNN
	1    5000 1400
	0    -1   -1   0   
$EndComp
Text GLabel 3800 1600 3    60   Input ~ 0
A1
Text GLabel 3700 1600 3    60   Input ~ 0
A2
Text GLabel 3600 1600 3    60   Input ~ 0
A3
Text GLabel 5050 1450 3    60   Input ~ 0
GND
Text GLabel 4950 1450 3    60   Input ~ 0
10
Text GLabel 2100 2300 3    60   Input ~ 0
2
Text GLabel 2200 2300 3    60   Input ~ 0
e
Text GLabel 2300 2300 3    60   Input ~ 0
4
$EndSCHEMATC