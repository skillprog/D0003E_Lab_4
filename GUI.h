#ifndef _GUI_H

#define _GUI_H

typedef struct{
	
	Object super;
	Pulse *p1;
	Pulse *p2;
	int pulseActive;
}g;


void writeChar(g *self, int pp, int frequency);
void printAt(g *self, int x);
void switchGen(g *self, int x);
void updateGui(g *self, int x);
#endif