/*
 * display7seg.h
 *
 *  Created on: Oct 28, 2024
 *      Author: tranm
 */

#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_

#include "main.h"
#include "global.h"

uint8_t change_displaynumber(int num);
void display7SEG1(int num);
void display7SEG2(int num);
void displayled_3and4( int num3, int num4);



#endif /* INC_DISPLAY7SEG_H_ */
