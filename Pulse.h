#ifndef _PULSE_H

#define _PULSE_H

typedef struct{
	Object super;
	int freq;
	int prevFreq;
	int which;
	}Pulse; 
	
	#define initPulse(freq, prevFreq, which){initObject(), freq, prevFreq, which};
		
	void pulseInc(Pulse *self);
	void pulseDec(Pulse *self);
	void pulseStopStart(Pulse *self);

#endif