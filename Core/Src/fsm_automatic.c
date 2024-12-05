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
			//updateClockBuffer(r, g);
			setTimer1(jump1);
			setTimer2(1);
			setTimer3(1);
			break;
		case GREEN_RED:
			led_green_red();
			if(timer2_flag == 1){
				setTimer2(5);
				update7SEG(index_led);
				index_led ++;
				if(index_led > 3){
					index_led = 0;
				}
			}
			if(timer3_flag == 1){
				setTimer3(100);
				updateClockBuffer(r, g);
				r--;
				g--;
				if(g == 0){
					g = max_g;
				}
				if(r == 0){
					r = max_r;
				}
				//updateClockBuffer(r, g);
			}
			if(timer1_flag == 1){
				status = AMBER_RED;
				updateClockBuffer(r, a);
				setTimer1(jump2);
				clearAll_led();
			}

			if(isButtonPressed(0) == 1){
				status = SETTING_RED;
				setTimer1(1);
				setTimer2(1);
				clearAll_led();
			}
			if(isButtonPressed(2) == 1){
				status = MAN_GREEN_RED;
				clearAll_led();
			}

			break;
		case AMBER_RED:
			led_amber_red();
			if(timer2_flag == 1){
				setTimer2(5);
				update7SEG(index_led);
				index_led ++;
				if(index_led > 3){
					index_led = 0;
				}
			}
			if(timer3_flag == 1){
				setTimer3(100);
				updateClockBuffer(r, a);
				r--;
				a--;

				if(a == 0){
					a = max_a;
				}
				if(r == 0){
					r = max_r;
				}
			}

			if(timer1_flag == 1){
				status = RED_GREEN;
				updateClockBuffer(g, r);
				setTimer1(jump1);
				clearAll_led();
			}
			break;
		case RED_GREEN:
			led_red_green();
			if(timer2_flag == 1){
				setTimer2(5);
				update7SEG(index_led);
				index_led ++;
				if(index_led > 3){
					index_led = 0;
				}
			}
			if(timer3_flag == 1){
				setTimer3(100);
				updateClockBuffer(g, r);
				r--;
				g--;

				if(g == 0){
					g = max_g;
				}
				if(r == 0){
					r = max_r;
				}

			}

			if(timer1_flag == 1){
				status = RED_AMBER;
				updateClockBuffer(a, r);
				setTimer1(jump2);
				clearAll_led();
			}

			if(isButtonPressed(0) == 1){
				status = SETTING_RED;
				setTimer1(1);
				setTimer2(1);
				clearAll_led();
			}
			if(isButtonPressed(2) == 1){
				status = MAN_GREEN_RED;
				clearAll_led();
			}
			break;
		case RED_AMBER:
			led_red_amber();
			if(timer2_flag == 1){
				setTimer2(5);
				update7SEG(index_led);
				index_led ++;
				if(index_led > 3){
					index_led = 0;
				}
			}
			if(timer3_flag == 1){
				setTimer3(100);
				updateClockBuffer(r, a);
				r--;
				a--;

				if(a == 0){
					a = max_a;
				}
				if(r == 0){
					r = max_r;
				}
			}

			if(timer1_flag == 1){
				status = INIT;
			}
			if(isButtonPressed(0) == 1){
				status = SETTING_RED;
				setTimer1(1);
				setTimer2(1);
				clearAll_led();
			}
			if(isButtonPressed(2) == 1){
				status = MAN_GREEN_RED;
				clearAll_led();
			}
			break;
		default:
			break;
	}
}


