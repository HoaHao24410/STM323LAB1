/*
 * fsm_automatic.c
 *
 *  Created on: Nov 30, 2024
 *      Author: ASUS
 */
#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status){
		case INIT:
			status = GREEN_RED;
			clearAll_led();
			setTimer1(300);
			setTimer2(1);
			break;
		case GREEN_RED:
			led_green_red();
			if(timer1_flag == 1){
				status = AMBER_RED;
				setTimer1(200);
			}
			break;
		case AMBER_RED:
			led_amber_red();
			if(timer1_flag == 1){
				status = RED_GREEN;
				setTimer1(300);
			}
			break;
		case RED_GREEN:
			led_red_green();
			if(timer1_flag == 1){
				status = RED_AMBER;
				setTimer1(200);
			}
			break;
		case RED_AMBER:
			led_red_amber();
			if(timer1_flag == 1){
				status = GREEN_RED;
				setTimer1(300);
			}
			break;
	}
}


