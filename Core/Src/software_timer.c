/*
 * timer.c
 *
 *  Created on: Oct 23, 2024
 *      Author: ASUS
 */
#include <software_timer.h>
int timer1_counter = 0;
int timer1_flag = 0;
void setTimer1(int duration){
	timer1_counter = duration;
	timer1_flag = 0;

}
void timerRun(){
	if(timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter <= 0){
				timer1_flag = 1;
		}
	}


}
