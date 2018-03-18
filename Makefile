
F_CPU	=	16000000
MCU	=	atmega328p

OBJS	=	main uart util
OUTPUT	=	balancer

all: ${OUTPUT}.hex

${OUTPUT}.hex: ${OUTPUT}.elf
	avr-objcopy -O ihex ${OUTPUT}.elf ${OUTPUT}.hex

${OUTPUT}.elf: $(OBJS:=.o)
	avr-gcc -DF_CPU=${F_CPU} -mmcu=${MCU} -o ${OUTPUT}.elf $^

%.o: %.c
	avr-gcc -Os -DF_CPU=${F_CPU} -mmcu=${MCU} -c $<

flash:
	sudo avrdude -c arduino -p m328p -b 57600 -P /dev/ttyUSB0 -U flash:w:${OUTPUT}.hex

clean:
	rm -rf ./*.o ./*.elf ./*.hex

.PHONY: flash clean

