
#ifndef B_TWI_H
#define B_TWI_H

void setup_twi();
void twi_stop(void);
uint8_t twi_blocking_start(uint8_t address);
uint8_t twi_blocking_write(uint8_t data);
uint8_t twi_blocking_read_ack(void);
uint8_t twi_blocking_read_nack(void);
uint8_t twi_blocking_write_addr(uint8_t regaddr, uint8_t* data, uint16_t length);
uint8_t twi_blocking_read_addr(uint8_t regaddr, uint8_t* data, uint16_t length);

#endif
