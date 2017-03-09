#include "GUI.h"
#include <asf.h>
#include <avr/io.h>
#include <avr/interrupt.h>


uint16_t digitASCII[] = {
	0x1551,       //0
	0x0110,       //1
	0x1E11,       //2
	0x1B11,       //3
	0x0B50,       //4
	0x1B41,       //5
	0x1F41,       //6
	0x0111,       //7
	0x1F51,       //8
	0x1B51        //9
};

void writeChar(char ch, int pos){
	
	
	uint16_t newCharacter = digitASCII[(int)ch-48]; //ensure correct formatting
	
	switch (pos){
		case 0:
		LCDDR0 &= 0xF0;
		LCDDR5 &= 0xF0;
		LCDDR10 &= 0xF0;
		LCDDR15 &= 0xF0;
		LCDDR0 |= (newCharacter&0x000f);
		LCDDR5 |= ((newCharacter&0x00f0)>>4);
		LCDDR10 |= ((newCharacter&0x0f00)>>8);
		LCDDR15 |= ((newCharacter&0xf000)>>12);
		break;
		case 1:
		LCDDR0 &= 0x0F;
		LCDDR5 &= 0x0F;
		LCDDR10 &= 0x0F;
		LCDDR15 &= 0x0F;
		LCDDR0 |= (newCharacter&0x000f) << 4;
		LCDDR5 |= ((newCharacter&0x00f0)>>4)<<4;
		LCDDR10 |= ((newCharacter&0x0f00)>>8)<<4;
		LCDDR15 |= ((newCharacter&0xf000)>>12)<<4;
		break;
		case 2:
		LCDDR1 &= 0xF0;
		LCDDR6 &= 0xF0;
		LCDDR11 &= 0xF0;
		LCDDR16 &= 0xF0;
		LCDDR1 |= (newCharacter&0x000f);
		LCDDR6 |= ((newCharacter&0x00f0)>>4);
		LCDDR11 |= ((newCharacter&0x0f00)>>8);
		LCDDR16 |= ((newCharacter&0xf000)>>12);
		break;
		case 3:
		LCDDR1 &= 0x0F;
		LCDDR6 &= 0x0F;
		LCDDR11 &= 0x0F;
		LCDDR16 &= 0x0F;
		LCDDR1 |= (newCharacter&0x000f)<<4;
		LCDDR6 |= ((newCharacter&0x00f0)>>4)<<4;
		LCDDR11 |= ((newCharacter&0x0f00)>>8)<<4;
		LCDDR16 |= ((newCharacter&0xf000)>>12)<<4;
		break;
		case 4:
		LCDDR2 &= 0xF0;
		LCDDR7 &= 0xF0;
		LCDDR12 &= 0xF0;
		LCDDR17 &= 0xF0;
		LCDDR2 |= (newCharacter&0x000f);
		LCDDR7 |= ((newCharacter&0x00f0)>>4);
		LCDDR12 |= ((newCharacter&0x0f00)>>8);
		LCDDR17 |= ((newCharacter&0xf000)>>12);
		break;
		case 5:
		LCDDR2 &= 0x0F;
		LCDDR7 &= 0x0F;
		LCDDR12 &= 0x0F;
		LCDDR17 &= 0x0F;
		LCDDR2 |= (newCharacter&0x000f) << 4;
		LCDDR7 |= ((newCharacter&0x00f0)>>4)<<4;
		LCDDR12 |= ((newCharacter&0x0f00)>>8)<<4;
		LCDDR17 |= ((newCharacter&0xf000)>>12)<<4;
		break;
		default:
		return 0;
		break;
	}
	
}

void printAt(g *self, int pulseRunning) {
	
	int num;
	int pp;	
	
	//Prints at position 0 and calculates from the rightmost digit.
	if(pulseRunning == 0)
	{
		num = self->p1->freq;
		pp = 0;
		num = (((num % 100) / 10));
		writeChar(self, pp, num);
		pp = 1;
		num = ((self->p1->freq % 10));
		writeChar(self, pp, num);
	}
	else
	{	//Prints at position 4.
		num = self->p2->freq;
		pp = 3;
		num = (((num % 100) / 10));
		writeChar(self, pp, num);
		pp = 4;
		num = ((self->p2->freq % 10));
		writeChar(self, pp, num);
	}

}

//show which pulsegen is running.
void switchGen(g *self, int x){
	
	if(self->pulseActive == 1){
		LCDDR18 = 0x1;
		LCDDR17 = 0x0;
		self->pulseActive = 0;
	}
	else if(self->pulseActive == 0){
		LCDDR18 = 0x0;
		LCDDR17 = 0x1;
		self->pulseActive = 1;
	}
	
}

void updateGui(g *self, int x){
	
	printAt(self, 0);
	printAt(self, 1);
}

