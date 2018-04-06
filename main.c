
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include "globals.h"

#define PWM0A OCR0A
#define PWM0B OCR0B
#define PWM0C OCR2B
#define PWM1A OCR2A
#define PWM1B OCR1B
#define PWM1C OCR1A

uint16_t pos = 0;

uint8_t pwma = 0;
uint8_t pwmb = 0;
uint8_t pwmc = 0;

void setup_timers()
{
	TCCR0A = 0;
	TCCR0B = 0;
	TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM00);
	TCCR0B = _BV(CS00);
	TCCR1A = 0;
	TCCR1B = 0;
	TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(WGM10);
	TCCR1B = _BV(CS10);
	TCCR2A = 0;
	TCCR2B = 0;
	TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM20);
	TCCR2B = _BV(CS20);

	OCR0A = 0;
	OCR0B = 0;
	OCR1A = 0;
	OCR1B = 0;
	OCR2A = 0;
	OCR2B = 0;
}

void setup_adc()
{
	ADMUX = _BV(REFS0) | _BV(MUX0);
	ADCSRA = _BV(ADEN) | _BV(ADATE) | _BV(ADSC) | 7;
}

uint16_t get_pot()
{
	uint16_t result = 0;
	cli();
	result = ADCL;
	result |= ADCH << 8;
	sei();
	return result;
}

void advance(uint16_t* in)
{

}

void set_pos(uint16_t in)
{
	uint8_t a = sinep[in & 0x3FF];
	uint8_t b = sinep[(in+341)&0x3FF];
	uint8_t c = sinep[(in+683)&0x3FF];
	cli();
	PWM1A = a;
	PWM1B = b;
	PWM1C = c;
	sei();
}

int main()
{
	DDRD = _BV(4);

	// All output compare pins
	DDRD |= _BV(5) | _BV(6) | _BV(3);
	DDRB = _BV(1) | _BV(2) | _BV(3);

	setup_uart(MYUBRR);
	sout("begin\n");

	setup_timers();
	setup_adc();
	setup_twi();

	test_mpu();

	while (1)
	{
		uint8_t buf[64];
		//uint16_t pot = get_pot();
		//set_pos(pot<<3);
		//snprintf(buf, 64, "%x\n", MYUBRR);
		//sout(buf);
		PORTD ^= 1<<4;
		_delay_ms(100);
	}


	return 0;
}

