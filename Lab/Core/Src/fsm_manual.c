/*
 * fsm_manul.c
 *
 *  Created on: Oct 29, 2024
 *      Author: tranm
 */

#include "fsm_manual.h"

void turn_off(){
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
}

void fsm_manual(){
	switch(status){
		case INIT:
			if (isButton1Pressed() == 1){
				status = MODE1;
				turn_off();
			}
			status1 = INIT;
			status2 = INIT;
			break;
		case MODE1:
			 fsm_automatic();
			 if (isButton1Pressed() == 1){
				 status = MODE2;
				 turn_off();
				 time_red = 0;
			 }
			break;
		case MODE2:
			HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
			HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
			 if(isButton2Pressed() == 1) time_red++;
			 display7SEG2(2);
			 display7SEG1(0);
			 displayled_3and4(time_red/10, time_red%10);
			 if (isButton1Pressed() == 1){
				 status = MODE3;
				 turn_off();
				 time_yellow = 0;
			 }
			break;
		case MODE3:
			HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
			HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
			 if(isButton2Pressed() == 1) time_yellow++;
			 display7SEG2(3);
			 display7SEG1(0);
			 displayled_3and4(time_yellow/10, time_yellow%10);
			 if (isButton1Pressed() == 1){
				 status = MODE4;
				 turn_off();
				 time_green = 0;
			 }
			break;
		case MODE4:
			HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
			HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
			if(isButton2Pressed() == 1) time_green++;
			display7SEG2(4);
			display7SEG1(0);
			displayled_3and4(time_green/10, time_green%10);
			 if (isButton1Pressed() == 1){
				 status = MODE1;
				 turn_off();
			 }
			 status1 = INIT;
			 status2 = INIT;
			break;
		default:
			break;
	}
}
