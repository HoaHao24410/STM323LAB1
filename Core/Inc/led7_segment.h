/*
 * led7_segment.h
 *
 *  Created on: Nov 30, 2024
 *      Author: ASUS
 */

#ifndef INC_LED7_SEGMENT_H_
#define INC_LED7_SEGMENT_H_
#include "main.h"
#include "global.h"
extern int led_buffer[4];

void display7SEG(int num);
void update7SEG(int index);
void updateClockBuffer(int num1, int num2);


#endif /* INC_LED7_SEGMENT_H_ */
