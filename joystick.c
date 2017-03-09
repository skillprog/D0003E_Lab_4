#include "joystick.h"

void checkstatePB(joystick *self){
	
	
	//need check to see which pulse is in use.
	if()
	
	
	//Down
	if((PINB >> 7) == 0) {
		
		ASYNC(self->p1, pulseDec, 0);
	}
	//Up
	else if((PINB >> 6) == 0){
		
		ASYNC(self->p1, pulseInc(), 0);
	}
	
}