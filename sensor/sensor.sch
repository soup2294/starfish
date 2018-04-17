EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
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
LIBS:kmz60
LIBS:sensor-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L KMZ60 U1
U 1 1 5ACEDB73
P 5700 3400
F 0 "U1" H 5900 3750 60  0000 C CNN
F 1 "KMZ60" H 5550 3750 60  0000 C CNN
F 2 "Housings_SOIC:SO-8_5.3x6.2mm_Pitch1.27mm" H 5700 3400 60  0001 C CNN
F 3 "" H 5700 3400 60  0001 C CNN
	1    5700 3400
	1    0    0    -1  
$EndComp
$Comp
L Conn_02x04_Counter_Clockwise J1
U 1 1 5ACEDBCE
P 5650 2600
F 0 "J1" H 5700 2800 50  0000 C CNN
F 1 "Conn_02x04_Counter_Clockwise" H 5700 2300 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04_Pitch2.54mm" H 5650 2600 50  0001 C CNN
F 3 "" H 5650 2600 50  0001 C CNN
	1    5650 2600
	1    0    0    1   
$EndComp
Wire Wire Line
	5150 2700 5150 3250
Wire Wire Line
	5150 2700 5450 2700
Wire Wire Line
	5100 2600 5100 4250
Wire Wire Line
	5100 2600 5450 2600
Wire Wire Line
	5150 3450 5050 3450
Wire Wire Line
	5050 3450 5050 2500
Wire Wire Line
	5050 2500 5450 2500
Wire Wire Line
	5150 3550 5000 3550
Wire Wire Line
	5000 3550 5000 2400
Wire Wire Line
	5000 2400 5450 2400
Wire Wire Line
	6250 3250 6250 2700
Wire Wire Line
	6250 2700 5950 2700
Wire Wire Line
	6300 3350 6300 2600
Wire Wire Line
	6300 2600 5950 2600
Wire Wire Line
	6350 3450 6350 2500
Wire Wire Line
	6350 2500 5950 2500
Wire Wire Line
	6250 3550 6400 3550
Wire Wire Line
	6400 3550 6400 2400
Wire Wire Line
	6400 2400 5950 2400
Connection ~ 6250 3350
Connection ~ 6250 3450
Connection ~ 5150 3350
Connection ~ 5150 3100
$Comp
L Conn_02x03_Counter_Clockwise J2
U 1 1 5AD54106
P 5850 4250
F 0 "J2" H 5900 4450 50  0000 C CNN
F 1 "Conn_02x03_Counter_Clockwise" H 5900 4050 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x03_Pitch2.54mm" H 5850 4250 50  0001 C CNN
F 3 "" H 5850 4250 50  0001 C CNN
	1    5850 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 3350 6250 3350
Connection ~ 6300 3100
Wire Wire Line
	5150 3100 6550 3100
Wire Wire Line
	6500 3450 6500 4150
Wire Wire Line
	6500 4150 6150 4150
Connection ~ 6350 3450
Wire Wire Line
	6500 3800 5500 3800
Wire Wire Line
	5500 3800 5500 4350
Wire Wire Line
	5500 4350 5650 4350
Connection ~ 6500 3800
Wire Wire Line
	5100 3350 5150 3350
Wire Wire Line
	6250 3450 6500 3450
Wire Wire Line
	6550 3100 6550 4350
Wire Wire Line
	6550 4350 6150 4350
Wire Wire Line
	5650 4150 5600 4150
Wire Wire Line
	5600 4150 5600 3850
Wire Wire Line
	5600 3850 6550 3850
Connection ~ 6550 3850
Wire Wire Line
	5100 4250 5650 4250
Connection ~ 5100 3350
Wire Wire Line
	5050 3550 5050 4000
Wire Wire Line
	5050 4000 6200 4000
Wire Wire Line
	6200 4000 6200 4250
Wire Wire Line
	6200 4250 6150 4250
Connection ~ 5050 3550
$EndSCHEMATC
