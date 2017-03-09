#include "Pulse.h"

void pulseInc(Pulse *self){
	if(self->freq < 99){
		self->freq++;
	}
}

void pulseDec(Pulse *self){
	if(self->freq > 0){
		self->freq--;
	}
}

void pulseStopStart(Pulse *self){
	if(self->freq != 0){
		self->prevFreq = self->freq;
		self->freq = 0; 
	}else{
		self->freq = self->prevFreq;
		self->prevFreq = 0;
	}
	
}