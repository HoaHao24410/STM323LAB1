/*
 * software_timer.h
 *
 *  Created on: Oct 31, 2024
 *      Author: ASUS
 */
#include "main.h"
extern int timer1_flag;
extern int timer2_flag;
extern int index_led;
void setTimer1(int duration);
void setTimer2(int duration);
void timerRun();
