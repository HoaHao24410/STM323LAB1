/*
 * fsm_setting.c
 *
 *  Created on: Nov 30, 2024
 *      Author: ASUS
 */
#include "fsm_setting.h"
void fsm_setting_run(){
	switch(status){
		case SETTING_RED:
			updateClockBuffer(value, 2);

			if(timer2_flag == 1){
				setTimer2(25);
				update7SEG(index_led);
				index_led ++;
				if(index_led > 3){
					index_led = 0;
				}
			}

			if(timer1_flag == 1){
				setTimer1(50);
				led_red_blinking();
			}
			if(isButtonPressed(1) == 1){
				value++;

			}
			if(isButtonPressed(2) == 1){
				max_r = value;
				max_a = value*2/5;
				max_g = max_r - max_a;
				r = value;
				a = max_a;
				g = max_g;
				jump1 = g * 100;
				jump2 = a * 100;
				status = INIT;
			}

			if(isButtonPressed(0)== 1){
				status = SETTING_AMBER;
				clearAll_led();
			}
			break;
		case SETTING_AMBER:
			updateClockBuffer(value, 3);

			if(timer2_flag == 1){
				setTimer2(25);
				update7SEG(index_led);
				index_led ++;
				if(index_led > 3){
					index_led = 0;
				}
			}

			if(timer1_flag == 1){
				setTimer1(50);
				led_amber_blinking();
			}
			if(isButtonPressed(1) == 1){
				value++;

			}
			if(isButtonPressed(2) == 1){
				max_r = 5*value/2;
				max_a = value;
				max_g = max_r - max_a;
				r = max_r;
				a = value;
				g = max_g;
				jump1 = g * 100;
				jump2 = a * 100;
				status = INIT;
			}
			if(isButtonPressed(0)== 1){
				status = SETTING_GREEN;
				clearAll_led();
			}
			break;
		case SETTING_GREEN:
			updateClockBuffer(value, 4);

			if(timer2_flag == 1){
				setTimer2(25);
				update7SEG(index_led);
				index_led ++;
				if(index_led > 3){
					index_led = 0;
				}
			}

			if(timer1_flag == 1){
				setTimer1(50);
				led_green_blinking();
			}
			if(isButtonPressed(1) == 1){
				value++;

			}
			if(isButtonPressed(2) == 1){
				max_a = 2*value/3;
				max_g = value;
				max_r = max_a + max_g;
				r = max_r;
				a = max_a;
				g = value;
				jump1 = g * 100;
				jump2 = a * 100;
				status = INIT;
			}
			if(isButtonPressed(0)== 1){
				status = INIT;
				value = 1;
				clearAll_led();
			}
			break;
		default:
			break;
	}

}

