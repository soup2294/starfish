
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <util/twi.h>
#include <stdio.h>

#include "globals.h"
#include "twi.h"

#define MPU_ADDR_WRITE (0x68<<1)
#define MPU_ADDR_READ (0x68<<1 | 1)

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

#define TWI_WRITE 0x0
#define TWI_READ  0x1
#define TWI_LONG  0x2

#define FILTER_EXP 2
#define FILTER_NUM_ANGLES (2<<(FILTER_EXP-1))
int16_t previous_angles[FILTER_NUM_ANGLES + 1] = {0};
int16_t current_angle = 0;

void mpu_read(int16_t* accel_x, int16_t* accel_y, int16_t* gyro)
{
	int8_t gyro_h;
	int8_t gyro_l;
	int8_t accel_xh;
	int8_t accel_xl;
	int8_t accel_yh;
	int8_t accel_yl;
	twi_blocking_start(MPU_ADDR_WRITE);
	twi_blocking_write(ACCEL_XH);
	twi_blocking_start(MPU_ADDR_READ);
	accel_xh = twi_blocking_read_ack();
	accel_xl = twi_blocking_read_ack();
	accel_yh = twi_blocking_read_ack();
	accel_yl = twi_blocking_read_nack();
	twi_blocking_start(MPU_ADDR_WRITE);
	twi_blocking_write(GYRO_XH);
	twi_blocking_start(MPU_ADDR_READ);
	gyro_h = twi_blocking_read_ack();
	gyro_l = twi_blocking_read_nack();
	twi_stop();
	*accel_x = (accel_xh<<8 | accel_xl);
	*accel_y = (accel_yh<<8 | accel_yl);
	*gyro = (gyro_h<<8 | gyro_l);
}

int16_t push_angle(int16_t in)
{
	int32_t total;
	int i;
	for (i = 0; i < FILTER_NUM_ANGLES; i++)
	{
		previous_angles[i] = previous_angles[i + 1];
	}
	previous_angles[FILTER_NUM_ANGLES - 1] = in;
	for (i = 0; i < FILTER_NUM_ANGLES; i++)
	{
		total += previous_angles[i];
	}
	total = total >> FILTER_EXP;
	return (int16_t)total;
}

int16_t get_accel_angle(int16_t accel_x, int16_t accel_y)
{
	uint8_t negative = 0;
	if (accel_x < 0) negative = 1;
	if (accel_y == 0) return 0;

	float ratio = abs(accel_x / accel_y);
	atan
}

uint16_t update_angle()
{
	int16_t accel_x = 0;
	int16_t accel_y = 0;
	int16_t gyro = 0;
	mpu_read(&accel, &gyro);

	int16_t get_accel_angle(accel);

	int16_t new_angle = (int16_t)(.97 * (current_angle + gyro));
	new_angle += (.03 * accel_angle);
	current_angle = push_angle(new_angle);

}

uint8_t test_mpu()
{
	sout("entering test_mpu\n");
// 	twi_write(PWR_1, 0);
// 	twi_write(GYRO_CONFIG, GYRO_SCALE_1000);
// 	sout("write done\n");
// 	while (1)
// 	{
// 		int8_t val = 0;
// 		twi_read(GYRO_XH, &val);
// 		sout("read %d\n", val);
// 		// uint8_t buf[16];
// 		// snprintf(buf, 16, "%x\n", val);
// 		// sout(buf);
// 		_delay_ms(1);
// 		//sout("loop\n");
// 	}
}

// uint8_t twi_state = 0;
// uint8_t twi_device = 0;
// uint8_t twi_address = 0;
// uint8_t twi_dir = 0;
// uint8_t twi_data_h = 0;
// uint8_t twi_data_l = 0;
// volatile uint8_t twi_finished = 1;

// uint8_t twi_write(uint8_t address, uint8_t data)
// {
// 	if (!twi_finished)
// 		return 1;
// 	twi_data_l = data;
// 	twi_device = MPU_ADDR;
// 	twi_address = address;
// 	twi_dir = _BV(TWI_WRITE);
// 	twi_finished = 0;
// 	twi_start();
// 	while (!twi_finished);
// 	return 0;
// }

// uint8_t twi_read(uint8_t address, uint8_t* data)
// {
// 	if (!twi_finished)
// 		return 1;
// 	twi_device = MPU_ADDR;
// 	twi_address = address;
// 	twi_dir = _BV(TWI_READ);
// 	twi_finished = 0;
// 	twi_start();
// 	while (!twi_finished);
// 	*data = twi_data_l;
// 	return 0;
// }

// ISR(TWI_vect)
// {
// 	//sout("entering isr\n");
// 	if (twi_state == 0)
// 	{
// 		//sout("state 0\n");
// 		TWCR = _BV(TWINT);
// 	}
// 	else if (twi_state == 1) // send slave device address
// 	{
// 		//sout("state 1\n");
// 		//if ((TWSR & 0xF8) != TW_START)
// 			//sout("fail1\n");
// 		TWDR = twi_device;
// 		TWCR = _BV(TWINT) | _BV(TWEN)  | _BV(TWIE);
// 		twi_state++;
// 	}
// 	else if (twi_state == 2) // send slave register address
// 	{
// 		//sout("state 2\n");
// 		if ((TWSR & 0xF8) != TW_MT_SLA_ACK)
// 		{
// 			uint8_t buf[16];
// 			snprintf(buf, 16, "fail status %x\n", (TWSR & 0xF8));
// 			//sout(buf);
// 		}
// 		TWDR = twi_address;
// 		TWCR = _BV(TWINT) | _BV(TWEN)  | _BV(TWIE);
// 		if (twi_dir & _BV(TWI_READ))
// 			twi_state++;
// 		else
// 			twi_state += 3;
// 	}
// 	else if (twi_state == 3) // restart in read mode
// 	{
// 		//sout("state 3\n");
// 		//if ((TWSR & 0xF8) != TW_MT_DATA_ACK)
// 			//sout("fail2\n");
// 		TWCR = _BV(TWINT) | _BV(TWSTA) | _BV(TWEN)  | _BV(TWIE);
// 		twi_state++;
// 	}
// 	else if (twi_state == 4) // restart in read mode
// 	{
// 		//sout("state 4\n");
// 		//if ((TWSR & 0xF8) != TW_START)
// 			//sout("fail3\n");
// 		TWDR = twi_device | 0x1;
// 		TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWIE);
// 		twi_state++;
// 	}
// 	else if (twi_state == 5) // start get or send data packet
// 	{
// 		//sout("state 5\n");
// 		//if ((TWSR & 0xF8) != TW_MR_SLA_ACK)
// 			//sout("fail4\n");
// 		if (twi_dir & _BV(TWI_WRITE))
// 			TWDR = twi_data_l;

// 		if (twi_dir & _BV(TWI_LONG)) // long write broken
// 			TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWEA) | _BV(TWIE);
// 		else
// 			TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWIE);
// 		twi_state++;
// 	}
// 	else if (twi_state == 6) // finish get data packet and stop
// 	{
// 		//sout("state 6\n");
// 		if (twi_dir & _BV(TWI_LONG))
// 		{
// 			twi_data_h = TWDR;
// 			twi_dir &= ~(uint8_t)_BV(TWI_LONG);
// 			TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWIE);
// 		}
// 		else
// 		{
// 			twi_data_l = TWDR;
// 			TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWSTO);
// 			twi_state = 0;	
// 			twi_finished = 1;
// 		}
// 	}
// 	//sout("leaving isr\n");
// }