#include "TinyTimber.h"
#include "Pulse.h"
#include "Helper.h"

Pulse p1 = initPulse(0, 0, 0);
Pulse p2 = initPulse(0, 0, 4);
joystick j = initJoystick(&p1, &p2);


int main() {
	initAll();
	
	INSTALL(&j, portB, IRQ_PCINT0)
	INSTALL(&j, portE, IRQ_PCINT1)
	
	
}