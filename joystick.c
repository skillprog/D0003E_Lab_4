#include "joystick.h"


void checkstatePB(joystick *self){
		
	
	self->p1->which == 0;
	
	
	//need check to see which pulse is in use.
	if(self->){
		
			//Down
			if((PINB >> 7) == 0) {
				
				ASYNC(self->p1, pulseDec, 0);
			}
			//Up
			else if((PINB >> 6) == 0){
				
				ASYNC(self->p1, pulseInc(), 0);
			}
		
		
	}
	
	if(self->p2){
		
		//Down
		if((PINB >> 7) == 0) {
			
			ASYNC(self->p1, pulseDec, 0);
		}
		//Up
		else if((PINB >> 6) == 0){
			
			ASYNC(self->p1, pulseInc(), 0);
		}
		
		
	}

}