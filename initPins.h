#ifndef _INITPINS_
#define _INITPINS_
#include "TinyTimber.h"

typedef struct{
	Object super;
}pins;

#define initPins(){initObject()};
	
void initAll();
	
#endif