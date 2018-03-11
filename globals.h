
#ifndef B_GLOBALS_H
#define B_GLOBALS_H

#define BAUD 115200
#define MYUBRR ((F_CPU / BAUD / 16UL) - 1)

void setup_uart(uint16_t);
void sout(const char*);

#endif
