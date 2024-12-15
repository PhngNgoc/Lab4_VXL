/*
 * global.h
 *
 *  Created on: Oct 28, 2024
 *      Author: tranm
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "main.h"

#define INIT  1
#define AUTO_RED 2
#define AUTO_GREEN 3
#define AUTO_YELLOW 4


#define MODE1 20
#define MODE2 21
#define MODE3 22
#define MODE4 23

extern int status1;
extern int status2;
extern int status;

extern int time_red;
extern int time_yellow;
extern int time_green;


#endif /* INC_GLOBAL_H_ */
