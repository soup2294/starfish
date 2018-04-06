
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <avr/io.h>

void setup_uart(uint16_t ubrr)
{

	UBRR0H = ubrr >> 8;
	UBRR0L = ubrr;

	UCSR0B = (1<<TXEN0) | (1<<RXEN0);
	UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);

}

void serial_send_string(uint8_t* str)
{
	uint8_t* c = str;
	while (*c != '\0')
	{
		if (*c == '\n')
		{
			while ( !(UCSR0A & (1<<UDRE0)) );
			UDR0 = '\r';
		}
		while ( !(UCSR0A & (1<<UDRE0)) );
		UDR0 = *c;
		c++;
	}
}

void _sout(const char* fmt, va_list args)
{
	uint8_t buf[64];
	vsnprintf(buf, 64, fmt, args);
	serial_send_string(buf);
}

void sout(const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	_sout(fmt, args);
	va_end(args);
}

void dout(const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	_sout(fmt, args);
	va_end(args);
}
