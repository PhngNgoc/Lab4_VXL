/*
 * fsm_automatic.c
 *
 *  Created on: Oct 28, 2024
 *      Author: tranm
 */

#include "fsm_automatic.h"

int count1;
int count2;



void fsm_automatic(){
	displayled_3and4(count1/10, count1%10);
	display7SEG2(count2 % 10);
	display7SEG1(count2 / 10);
	switch (status1) {
			case INIT:
				HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
				status1 = AUTO_GREEN;
				count1 = time_green;
				break;
			case AUTO_RED:
				HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
				HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
				count1--;
				if ( count1 == 0 ){
					status1 = AUTO_GREEN;
					count1 = time_green;
				}
				break;
			case AUTO_GREEN:
				HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
				HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
				count1--;
				if ( count1 == 0 ){
					status1 = AUTO_YELLOW;
					count1 = time_yellow;
				}
				break;
			case AUTO_YELLOW:
				HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
				count1--;
				if ( count1 == 0 ){
					status1 = AUTO_RED;
					count1 = time_red;
				}
				break;
			default:
				break;
		}
	switch (status2) {
			case INIT:
				HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
				status2 = AUTO_RED;
				count2 = time_red;
				break;
			case AUTO_RED:
				HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
				HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
				count2--;
				if ( count2 == 0 ){
					status2 = AUTO_GREEN;
					count2 = time_green;
				}
				break;
			case AUTO_GREEN:
				HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, RESET);
				HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
				count2--;
				if ( count2 == 0 ){
					status2 = AUTO_YELLOW;
					count2 = time_yellow;
				}
				break;
			case AUTO_YELLOW:
				HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, RESET);
				count2--;
				if ( count2 == 0 ){
					status2 = AUTO_RED;
					count2 = time_red;
				}
				break;
			default:
				break;
		}

}

