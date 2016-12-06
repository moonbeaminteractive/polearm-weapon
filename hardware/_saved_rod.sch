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
P 4650 2400
F 0 "P2" H 4650 3050 50  0000 C CNN
F 1 "CONN_01X12" V 4750 2400 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x12" H 4650 2400 50  0001 C CNN
F 3 "" H 4650 2400 50  0000 C CNN
	1    4650 2400
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X12 P1
U 1 1 5834738F
P 5200 2400
F 0 "P1" H 5200 3050 50  0000 C CNN
F 1 "CONN_01X12" V 5300 2400 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x12" H 5200 2400 50  0001 C CNN
F 3 "" H 5200 2400 50  0000 C CNN
	1    5200 2400
	-1   0    0    -1  
$EndComp
$Comp
L CONN_01X05 P3
U 1 1 5840678B
P 5350 3550
F 0 "P3" H 5350 3850 50  0000 C CNN
F 1 "GYRO" V 5450 3550 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05" H 5350 3550 50  0001 C CNN
F 3 "" H 5350 3550 50  0000 C CNN
	1    5350 3550
	1    0    0    -1  
$EndComp
Text GLabel 5150 3350 0    60   Input ~ 0
GND
Text GLabel 5150 3750 0    60   Input ~ 0
PWR
$Comp
L R R1
U 1 1 58406A0D
P 4400 3900
F 0 "R1" V 4480 3900 50  0000 C CNN
F 1 "R" V 4400 3900 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4330 3900 50  0001 C CNN
F 3 "" H 4400 3900 50  0000 C CNN
	1    4400 3900
	0    -1   -1   0   
$EndComp
$Comp
L SW_PUSH SW1
U 1 1 58406ACB
P 4650 3600
F 0 "SW1" H 4800 3710 50  0000 C CNN
F 1 "SW_PUSH_R" H 4650 3520 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_PUSH-12mm" H 4650 3600 50  0001 C CNN
F 3 "" H 4650 3600 50  0000 C CNN
	1    4650 3600
	0    1    1    0   
$EndComp
Text GLabel 4650 3300 1    60   Input ~ 0
PWR
Text GLabel 4250 3900 0    60   Input ~ 0
GND
Wire Wire Line
	4650 3900 4550 3900
Wire Wire Line
	4650 3900 4650 4000
Text GLabel 4650 4000 3    60   Input ~ 0
4
$Comp
L R R2
U 1 1 58406D61
P 4400 5050
F 0 "R2" V 4480 5050 50  0000 C CNN
F 1 "R" V 4400 5050 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4330 5050 50  0001 C CNN
F 3 "" H 4400 5050 50  0000 C CNN
	1    4400 5050
	0    -1   -1   0   
$EndComp
$Comp
L SW_PUSH SW2
U 1 1 58406D67
P 4650 4750
F 0 "SW2" H 4800 4860 50  0000 C CNN
F 1 "SW_PUSH_G" H 4650 4670 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_PUSH-12mm" H 4650 4750 50  0001 C CNN
F 3 "" H 4650 4750 50  0000 C CNN
	1    4650 4750
	0    1    1    0   
$EndComp
Text GLabel 4650 4450 1    60   Input ~ 0
PWR
Text GLabel 4250 5050 0    60   Input ~ 0
GND
Wire Wire Line
	4650 5050 4550 5050
Wire Wire Line
	4650 5050 4650 5150
Text GLabel 4650 5150 3    60   Input ~ 0
3
$Comp
L R R3
U 1 1 58406E3E
P 4400 6200
F 0 "R3" V 4480 6200 50  0000 C CNN
F 1 "R" V 4400 6200 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4330 6200 50  0001 C CNN
F 3 "" H 4400 6200 50  0000 C CNN
	1    4400 6200
	0    -1   -1   0   
$EndComp
$Comp
L SW_PUSH SW3
U 1 1 58406E44
P 4650 5900
F 0 "SW3" H 4800 6010 50  0000 C CNN
F 1 "SW_PUSH_B" H 4650 5820 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_PUSH-12mm" H 4650 5900 50  0001 C CNN
F 3 "" H 4650 5900 50  0000 C CNN
	1    4650 5900
	0    1    1    0   
$EndComp
Text GLabel 4650 5600 1    60   Input ~ 0
PWR
Text GLabel 4250 6200 0    60   Input ~ 0
GND
Wire Wire Line
	4650 6200 4550 6200
Wire Wire Line
	4650 6200 4650 6300
Text GLabel 4650 6300 3    60   Input ~ 0
2
$Comp
L CONN_01X04 P4
U 1 1 5840776A
P 5350 4300
F 0 "P4" H 5350 4550 50  0000 C CNN
F 1 "DOTSTAR" V 5450 4300 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04" H 5350 4300 50  0001 C CNN
F 3 "" H 5350 4300 50  0000 C CNN
	1    5350 4300
	1    0    0    -1  
$EndComp
Text GLabel 5150 4150 0    60   Input ~ 0
GND
Text GLabel 5150 4450 0    60   Input ~ 0
PWR
Text GLabel 5150 4250 0    60   Input ~ 0
6
Text GLabel 5150 4350 0    60   Input ~ 0
7
$Comp
L buzzer BZ1
U 1 1 58408201
P 5350 4850
F 0 "BZ1" H 5425 4900 50  0000 L CNN
F 1 "buzzer" H 5425 4800 50  0000 L CNN
F 2 "Buzzers_Beepers:MagneticBuzzer_Kingstate_KCG0601" H 5350 4850 60  0001 C CNN
F 3 "" H 5350 4850 60  0000 C CNN
	1    5350 4850
	1    0    0    -1  
$EndComp
Text GLabel 5150 3650 0    60   Input ~ 0
A1
Text GLabel 5150 3550 0    60   Input ~ 0
A2
Text GLabel 5150 3450 0    60   Input ~ 0
A3
Text GLabel 5300 4900 0    60   Input ~ 0
GND
Text GLabel 5300 4800 0    60   Input ~ 0
10
Text GLabel 4450 2250 0    60   Input ~ 0
2
Text GLabel 4450 2350 0    60   Input ~ 0
e
Text GLabel 4450 2450 0    60   Input ~ 0
4
Text GLabel 5400 2950 2    60   Input ~ 0
10
Text GLabel 5400 2850 2    60   Input ~ 0
11
Text GLabel 5400 2750 2    60   Input ~ 0
12
Text GLabel 5400 2650 2    60   Input ~ 0
13
Text GLabel 5400 2550 2    60   Input ~ 0
A0
Text GLabel 5400 2450 2    60   Input ~ 0
A1
Text GLabel 5400 2350 2    60   Input ~ 0
A2
Text GLabel 5400 1950 2    60   Input ~ 0
GND
Text GLabel 5400 2150 2    60   Input ~ 0
PWR
Text GLabel 4450 1850 0    60   Input ~ 0
TX
Text GLabel 4450 1950 0    60   Input ~ 0
RX
Text GLabel 4450 2150 0    60   Input ~ 0
GND
Text GLabel 4450 2550 0    60   Input ~ 0
5
Text GLabel 4450 2650 0    60   Input ~ 0
6
Text GLabel 4450 2750 0    60   Input ~ 0
7
Text GLabel 4450 2850 0    60   Input ~ 0
8
Text GLabel 4450 2950 0    60   Input ~ 0
9
$EndSCHEMATC
