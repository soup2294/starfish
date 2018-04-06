
#ifndef B_GLOBALS_H
#define B_GLOBALS_H

#include <stdint.h>

#define BAUD 57600UL
#define MYUBRR ((F_CPU / BAUD / 16UL) - 1)

#define MYSCL 100000UL


extern uint8_t twi_address;
extern uint8_t twi_dir;
extern uint8_t twi_data_h;
extern uint8_t twi_data_l;
extern volatile uint8_t twi_finished;

void setup_uart(uint16_t);
void setup_twi();
void sout(const char*, ...);
void dout(const char*, ...);
uint16_t get_mpu();

extern uint8_t sinep[1024];
extern uint16_t pos;

#endif
