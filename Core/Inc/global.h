/*
 * global.h
 *
 *  Created on: Nov 30, 2024
 *      Author: ASUS
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#define INIT	1
#define GREEN_RED	2
#define AMBER_RED	3
#define RED_GREEN	4
#define RED_AMBER	5

#define MAN_GREEN_RED	12
#define MAN_AMBER_RED	13
#define MAN_RED_GREEN	14
#define MAN_RED_AMBER	15

#define SETTING_RED		22
#define SETTING_GREEN   23
#define SETTING_AMBER   24

#define N0_OF_BUTTONS	3


#include "main.h"
#include "button.h"
#include "software_timer.h"

extern int r; //red_time count_down
extern int g;// green_time count_down
extern int a;//amber_time count_down
extern int status;


#endif /* INC_GLOBAL_H_ */
