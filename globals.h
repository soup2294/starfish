
#ifndef B_GLOBALS_H
#define B_GLOBALS_H

#include <stdint.h>

#define BAUD 115200UL
#define MYUBRR ((F_CPU / BAUD / 16UL) - 1)

#define MYSCL 100000UL
#define MYTWBR ((((F_CPU / MYSCL) / 1) - 16) / 2)

void setup_uart(uint16_t);
void setup_twi();
void sout(const char*);
uint16_t get_mpu();

extern uint8_t sinep[1024];
extern uint16_t pos;

#endif
