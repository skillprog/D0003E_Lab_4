#ifndef _JOYSTICK_H

#define _JOYSTICK_H


typedef struct{
	Object super;
	Pulse *p1;
	Pulse *p2;
}joystick;

#define initJoystick(p1, p2){initObject(), p1, p2};

void checkStatePB(joystick *self);
void checkStatePE(joystick *self);

#endif