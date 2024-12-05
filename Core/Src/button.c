/*
 * button.c
 *
 *  Created on: Nov 30, 2024
 *      Author: ASUS
 */
#include "button.h"
int KeyReg0[N0_OF_BUTTONS] = {NORMAL_STATE};
int KeyReg1[N0_OF_BUTTONS] = {NORMAL_STATE};
int KeyReg2[N0_OF_BUTTONS] = {NORMAL_STATE};
int KeyReg3[N0_OF_BUTTONS] = {NORMAL_STATE};

int TimeOutForKeyPress = 500;
int button_flag[N0_OF_BUTTONS] = {0};
int button_long_pressed[N0_OF_BUTTONS] = {0};

int isButtonPressed(int index){
	if(button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

int isButtonLongPressed(int index){
	if(button_long_pressed[index] == 1)
		return 1;
	return 0;
}

void subKeyProcess(){
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}
void getKeyInput(){
	for(int i = 0; i < N0_OF_BUTTONS; i++){
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
	}
	KeyReg0[0] = HAL_GPIO_ReadPin(BTN0_GPIO_Port, BTN0_Pin);
	KeyReg0[1] = HAL_GPIO_ReadPin(BTN1_GPIO_Port, BTN1_Pin);
	KeyReg0[2] = HAL_GPIO_ReadPin(BTN2_GPIO_Port, BTN2_Pin);

	for(int i = 0; i < N0_OF_BUTTONS; i++){
		if((KeyReg1[i] == KeyReg0[i]) && (KeyReg2[i] == KeyReg1[i])){
			if(KeyReg2[i] != KeyReg3[i]){
				KeyReg3[i] = KeyReg2[i];

				if(KeyReg3[i] == PRESSED_STATE){
					TimeOutForKeyPress = 500;
					button_flag[i] = 1;
				}
			}
			else{
				TimeOutForKeyPress--;
				if(TimeOutForKeyPress == 0){
					TimeOutForKeyPress = 500;

					if(KeyReg3[i] == PRESSED_STATE){
						button_flag[i] = 1;
					}
				}
			}
		}
	}
}


