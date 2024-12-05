/*
 * button.h
 *
 *  Created on: Nov 30, 2024
 *      Author: ASUS
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_


#include "main.h"
#include "global.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int button1_flag;

void getKeyInput();
int isButtonPressed(int index);


#endif /* INC_BUTTON_H_ */
