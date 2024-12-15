/*
 * button.h
 *
 *  Created on: Oct 27, 2024
 *      Author: tranm
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int button1_flag;

int isButton1Pressed();
int isButton1LongPressed();
int isButton2Pressed();
int isButton2LongPressed();
int isButton3Pressed();
int isButton3LongPressed();
void subKeyProcess();
void getKey1Input();
void getKey2Input();
void getKey3Input();


#endif /* INC_BUTTON_H_ */
