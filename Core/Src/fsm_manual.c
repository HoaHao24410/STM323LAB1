/*
 * fsm_manual.c
 *
 *  Created on: Nov 30, 2024
 *      Author: ASUS
 */
#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
		case MAN_GREEN_RED:
			led_green_red();
			if(isButtonPressed(2)== 1){
				status = MAN_AMBER_RED;
				clearAll_led();
			}
		break;
		case MAN_AMBER_RED:
			led_amber_red();
			if(isButtonPressed(2)== 1){
				status = MAN_RED_GREEN;
				clearAll_led();
			}
		break;
		case MAN_RED_GREEN:
			led_red_green();
			if(isButtonPressed(2)== 1){
				status = MAN_RED_AMBER;
				clearAll_led();
			}
		break;
		case MAN_RED_AMBER:
			led_red_amber();
			if(isButtonPressed(2)== 1){
				status = MAN_GREEN_RED;
				clearAll_led();
			}
		break;
	}
	if(isButtonPressed(0) == 1){
		status = INIT;
		clearAll_led();
	}

}
