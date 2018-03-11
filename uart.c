
#include <stdint.h>
#include <avr/io.h>

void setup_uart(uint16_t ubrr)
{

	UBRR0H = ubrr >> 8;
	UBRR0L = ubrr;

	UCSR0B = (1<<TXEN0) | (1<<RXEN0);
	UCSR0C = (3<<UCSZ00);

}

void uart_send_char(uint8_t c)
{
	while ( !(UCSR0A & (1<<UDRE0)) )
		;

	UDR0 = c;
}

void sout(const char* str)
{
	uint8_t* c = (uint8_t*)str;
	while (*c != '\0')
	{
		uart_send_char(*c);
		c++;
	}
}