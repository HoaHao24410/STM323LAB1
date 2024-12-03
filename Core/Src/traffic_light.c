/*
 * traffic_light.c
 *
 *  Created on: Nov 30, 2024
 *      Author: ASUS
 */
#include "traffic_light.h"
void clearAll_led(){
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
	HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
	HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);

}
void led_green_red(){
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, SET);
	HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, SET);
}

void led_amber_red(){
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, SET);
	HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, SET);

}

void led_red_green(){
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);
	HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, SET);

}

void led_red_amber(){
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);

}
