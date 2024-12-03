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
			updateClockBuffer(r, g);
			setTimer1(300);
			setTimer2(25);
			setTimer3(100);
			break;
		case GREEN_RED:
			led_green_red();
			if(timer2_flag == 1){
				setTimer2(25);
				update7SEG(index_led);
				index_led ++;
				if(index_led > 3){
					index_led = 0;
				}
			}
			if(timer3_flag == 1){
				setTimer3(100);
				r--;
				g--;
				updateClockBuffer(r, g);
				if(g == 0){
					g = 3;
				}
			}
			if(timer1_flag == 1){
				status = AMBER_RED;
				updateClockBuffer(r, a);
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
		default:
			break;
	}
}


