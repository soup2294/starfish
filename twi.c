
#include <avr/io.h>
#include <util/twi.h>

#include "globals.h"

#define TWI_DEVICE (0x68)
#define MYTWBR ((((F_CPU / MYSCL) / 1) - 16) / 2)

void twi_print_error(const char* in)
{
	sout("mpu error: ");
	sout(in);
	sout("\n");
}

void setup_twi()
{
	TWBR = (uint8_t)MYTWBR;
	TWCR = _BV(TWIE);
}

void twi_stop(void)
{
	TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWSTO);
}

uint8_t twi_blocking_start(uint8_t address_and_dir)
{
	TWCR = 0;
	TWCR = _BV(TWINT) | _BV(TWSTA) | _BV(TWEN);
	while( !(TWCR & _BV(TWINT)) );
	
	if((TWSR & 0xF8) != TW_START) twi_print_error("1");
	
	TWDR = address_and_dir;
	TWCR = _BV(TWINT) | _BV(TWEN);
	while( !(TWCR & _BV(TWINT)) );
	
	uint8_t twst = TW_STATUS & 0xF8;
	if ( (twst != TW_MT_SLA_ACK) && (twst != TW_MR_SLA_ACK) ) twi_print_error("1");
	
	return 0;
}

uint8_t twi_blocking_write(uint8_t data)
{
	TWDR = data;
	TWCR = _BV(TWINT) | _BV(TWEN);
	while( !(TWCR & _BV(TWINT)) );
	
	if( (TWSR & 0xF8) != TW_MT_DATA_ACK ) twi_print_error("1");
	return 0;
}

uint8_t twi_blocking_read_ack(void)
{
	
	TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWEA); 
	while( !(TWCR & _BV(TWINT)) );
	return TWDR;
}

uint8_t twi_blocking_read_nack(void)
{
	TWCR = _BV(TWINT) | _BV(TWEN);
	while( !(TWCR & _BV(TWINT)) );
	return TWDR;
}

uint8_t twi_blocking_write_addr(uint8_t regaddr, uint8_t* data, uint16_t length)
{
	if (twi_blocking_start(TWI_DEVICE<<1 | 0x00)) twi_print_error("1");

	twi_blocking_write(regaddr);

	for (uint16_t i = 0; i < length; i++)
	{
		if (twi_blocking_write(data[i])) twi_print_error("1");
	}

	twi_stop();

	return 0;
}

uint8_t twi_blocking_read_addr(uint8_t regaddr, uint8_t* data, uint16_t length)
{
	if (twi_blocking_start(TWI_DEVICE<<1 | 0x00)) twi_print_error("1");

	twi_blocking_write(regaddr);

	if (twi_blocking_start(TWI_DEVICE<<1 | 0x01)) twi_print_error("1");

	for (uint16_t i = 0; i < (length-1); i++)
	{
		data[i] = twi_blocking_read_ack();
	}
	data[(length-1)] = twi_blocking_read_nack();

	twi_stop();

	return 0;
}
