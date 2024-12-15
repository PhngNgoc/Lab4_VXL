/*
 * scheduler.h
 *
 *  Created on: Dec 6, 2024
 *      Author: tranm
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "main.h"
// MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCH_MAX_TASKS 			40
#define	NO_TASK_ID				0

#define RETURN_ERROR 0
#define RETURN_NORMAL 1

#define ERROR_SCH_CANNOT_DELETE_TASK 51
#define ERROR_SCH_TOO_MANY_TASKS 52
#define ERROR_SCH_WAITING_FOR_SLAVE_TO_ACK 53
#define ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER 54
#define ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START 55
#define ERROR_SCH_LOST_SLAVE 56
#define ERROR_SCH_CAN_BUS_ERROR 57
#define ERROR_I2C_WRITE_BYTE_AT24C64 58

extern unsigned char Error_code_G;

typedef struct {
    // Pointer to the task (must be a 'void (void)' function)
	void (*pTask)();
	// Delay (ticks) until the function will (next) be run
	uint32_t Delay;
	// Interval (ticks) between subsequent runs.
	uint32_t Period;
	// Incremented (by scheduler) when task is due to execute
	uint8_t RunMe;
	//This is a hint to solve the question below.
	uint32_t TaskID;
} sTask;

void SCH_Init();
void SCH_Update();
unsigned char SCH_Add_Task(void (* pFunction)(), unsigned int DELAY, unsigned int PERIOD);
void SCH_Dispatch_Tasks();
uint8_t SCH_Delete_Task( uint32_t taskID);


#endif /* INC_SCHEDULER_H_ */
