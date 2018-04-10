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
LIBS:starfish-cache
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
L kmz60 U1
U 1 1 5ACC2B76
P 5100 2750
F 0 "U1" H 4900 3050 60  0000 C CNN
F 1 "kmz60" H 5150 3050 60  0000 C CNN
F 2 "Housings_SOIC:SO-8_5.3x6.2mm_Pitch1.27mm" H 5150 2750 60  0001 C CNN
F 3 "" H 5150 2750 60  0001 C CNN
	1    5100 2750
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x04 J2
U 1 1 5ACCDD93
P 6850 3950
F 0 "J2" H 6850 4150 50  0000 C CNN
F 1 "Conn_01x04" H 6850 3650 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 6850 3950 50  0001 C CNN
F 3 "" H 6850 3950 50  0001 C CNN
	1    6850 3950
	1    0    0    -1  
$EndComp
$Comp
L Conn_02x04_Counter_Clockwise J1
U 1 1 5ACCDDC6
P 5650 3950
F 0 "J1" H 5700 4150 50  0000 C CNN
F 1 "Conn_02x04_Counter_Clockwise" H 5700 3650 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04_Pitch2.54mm" H 5650 3950 50  0001 C CNN
F 3 "" H 5650 3950 50  0001 C CNN
	1    5650 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 2600 4400 2600
Wire Wire Line
	4400 2600 4400 3450
Wire Wire Line
	4400 3450 5150 3450
Wire Wire Line
	5150 3450 5150 3850
Wire Wire Line
	5150 3850 5450 3850
Wire Wire Line
	4600 2700 4450 2700
Wire Wire Line
	4450 2700 4450 3500
Wire Wire Line
	4450 3500 6400 3500
Wire Wire Line
	5250 3500 5250 3950
Wire Wire Line
	5250 3950 5450 3950
Wire Wire Line
	4600 2800 4500 2800
Wire Wire Line
	4500 2800 4500 3550
Wire Wire Line
	4500 3550 6150 3550
Wire Wire Line
	5300 3550 5300 4050
Wire Wire Line
	5300 4050 5450 4050
Wire Wire Line
	4600 2900 4550 2900
Wire Wire Line
	4550 2900 4550 3600
Wire Wire Line
	4550 3600 5350 3600
Wire Wire Line
	5350 3600 5350 4150
Wire Wire Line
	5350 4150 5450 4150
Wire Wire Line
	5650 2600 6050 2600
Wire Wire Line
	6050 2600 6050 3850
Wire Wire Line
	6050 3850 5950 3850
Wire Wire Line
	5650 2700 6100 2700
Wire Wire Line
	6100 2700 6100 3950
Wire Wire Line
	5950 3950 6650 3950
Wire Wire Line
	5650 2800 6150 2800
Wire Wire Line
	6150 2800 6150 4050
Wire Wire Line
	5950 4050 6400 4050
Wire Wire Line
	5650 2900 6200 2900
Wire Wire Line
	6200 2900 6200 4150
Wire Wire Line
	6200 4150 5950 4150
Connection ~ 6100 3950
Wire Wire Line
	6400 4050 6400 4150
Wire Wire Line
	6400 4150 6650 4150
Connection ~ 6150 4050
Wire Wire Line
	6400 3500 6400 3850
Wire Wire Line
	6400 3850 6650 3850
Connection ~ 5250 3500
Wire Wire Line
	5350 3700 6500 3700
Wire Wire Line
	6500 3700 6500 4050
Wire Wire Line
	6500 4050 6650 4050
Connection ~ 5350 3700
Connection ~ 6150 3550
Connection ~ 5300 3550
$EndSCHEMATC
