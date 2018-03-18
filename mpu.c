
#include <avr/io.h>
#include "globals.h"

#define MPU_ADDR 0x68

#define PWR_1 0x6B
#define PWR_2 0x6C

#define ACCEL_CONFIG 	0x1C
#define GYRO_CONFIG 	0x1B

#define ACCEL_XH 		0x3B
#define ACCEL_XL 		0x3C
#define ACCEL_YH 		0x3D
#define ACCEL_YL 		0x3E
#define ACCEL_ZH 		0x3F
#define ACCEL_ZL 		0x40

#define ACCEL_SCALE_2 	0
#define ACCEL_SCALE_4 	1
#define ACCEL_SCALE_8 	2
#define ACCEL_SCALE_16 	3

#define GYRO_XH 		0x43
#define GYRO_XL 		0x44
#define GYRO_YH 		0x45
#define GYRO_YL 		0x46
#define GYRO_ZH 		0x47
#define GYRO_ZL 		0x48

#define GYRO_SCALE_250	0
#define GYRO_SCALE_500	1
#define GYRO_SCALE_1000	2
#define GYRO_SCALE_2000	3


void setup_twi(uint8_t address)
{
	TWBR = (uint8_t)MYTWBR;
}

uint8_t twi_start()
{
	TWCR = 0;
	TWCR = _BV(TWINT) | _BV(TWSTA) | _BV(TWEN);
	while ( !(TWCR & _BV(TWINT)) );

	if ((TWSR & 0xF8) != TW_START)	return 1;
	
	TWDR = address;
	TWCR = _BV(TWINT) | _BV(TWEN);
	while ( !(TWCR & _BV(TWINT)) );

	uint8_t status = TW_STATUS & 0xF8;
	if ( (status != TW_MT_SLA_ACK) && (status != TW_MR_SLA_ACK) ) return 2;

	return 0;
}

uint8_t twi_transmit(uint8_t data)
{
	TWDR = data;
	TWCR = _BV(TWINT) | _BV(TWEN);
}

uint16_t get_mpu()
{

}