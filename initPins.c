#include "initPins.h"
#include <avr/io.h>
#include <avr/portpins.h>

void initAll(){
	//clock init
	CLKPR = 0x80;
	CLKPR = 0x00;
	//LCD init
	LCDCCR = (0 << LCDDC2) | (0 << LCDDC1) | (0 << LCDDC0) | (1 << LCDCC3) | (1 << LCDCC2) | (1 << LCDCC1) | (1 << LCDCC0);
	LCDCRB = (1 << LCDCS) | (0 << LCD2B) | (1 << LCDMUX1) | (1 << LCDMUX0) | (1 << LCDPM2) | (1 << LCDPM1) | (1 << LCDPM0);
	LCDFRR = (0 << LCDPS2) | (0 << LCDPS1) | (0 << LCDPS0) | (1 << LCDCD2) | (1 << LCDCD1) | (1 << LCDCD0);
	LCDCRA = (1 << LCDEN) | (1 << LCDAB) | (0 << LCDIE) | (0 << LCDBL);
	
	PCMSK0 = PCMSK0 | (1<<PCINT2) | (1<<PCINT3);
	PCMSK1 = PCMSK1 | (1<<PCINT15) | (1<<PCINT14) | (1<<PCINT12);
	
	EIMSK = EIMSK | (1<<PCIE1) | (1<<PCIE0);
	
	//Port init
	PORTB = (1 << PORTB7)|(1 << PORTB6)|(1 << PORTB4);
	PORTE = (1 << PORTE3)|(1 << PORTE2);


}