/*
 * scheduler.c
 *
 *  Created on: Dec 5, 2024
 *      Author: ASUS
 */
#include "scheduler.h"
int counter;
sTask SCH_tasks_G[];
void SCH_Init(void){
	unsigned char i;
	for (i = 0; i < SCH_MAX_TASKS; i++) {
		SCH_Delete_Task(i);
	}
};
unsigned char SCH_Add_Task(void (* pFunction)() , unsigned int DELAY, unsigned int PERIOD){
	/*Array_O(n)*/
	unsigned char Index = 0;
	// First find a gap in the array (if there is one)
	while((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS)){
		Index++;
	}
	 // Have we reached the end of the list?
	if (Index >= SCH_MAX_TASKS || Index < 0){
		// Task list is full
		return SCH_MAX_TASKS;
	}
	// If we’re here, there is a space in the task array
	SCH_tasks_G[Index].pTask = pFunction;
	SCH_tasks_G[Index].Delay = DELAY;
	SCH_tasks_G[Index].Period = PERIOD;
	SCH_tasks_G[Index].RunMe = 0;
	// return position of task (to allow later deletion)
	return Index;
};
unsigned char SCH_Delete_Task(const int TASK_INDEX){
	if(TASK_INDEX < 0 || TASK_INDEX > counter-1 || counter == 0){
		return counter;
	}
	else{
		if(counter == 1){
			SCH_tasks_G[0].pTask = 0x0000;
			SCH_tasks_G[0].Delay = 0;
			SCH_tasks_G[0].Period = 0;
			SCH_tasks_G[0].RunMe = 0;
			counter = 0;
			return 1;
		}
		else{
			SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
			SCH_tasks_G[TASK_INDEX].Delay = 0;
			SCH_tasks_G[TASK_INDEX].Period = 0;
			SCH_tasks_G[TASK_INDEX].RunMe = 0;
			counter--;
			return 1;
		}
	}
};
void SCH_Update(void){
	unsigned char Index;
	//NOTE: calculations are in *TICKS* (not milliseconds)
	for(Index = 0; Index < SCH_MAX_TASKS; Index++){
		// Check if there is a task at this location
		if(SCH_tasks_G[Index].pTask){
			if(SCH_tasks_G[Index].Delay == 0){
				// The task is due to run
				// Inc. the ’RunMe’ flag
				SCH_tasks_G[Index].RunMe++;

				if(SCH_tasks_G[Index].Period){
					// Schedule periodic tasks to run again
					SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
				}
			}
			else{
				// Not yet ready to run: just decrement the delay
				SCH_tasks_G[Index].Delay--;
			}
		}
	}
};

void SCH_Dispatch_Tasks(void){
	/*Array_O(n)*/
	unsigned char Index;
	// Dispatches (runs) the next task (if one is ready)
	for(Index = 0; Index < SCH_MAX_TASKS; Index++){
		if(SCH_tasks_G[Index].RunMe > 0) {
			(*SCH_tasks_G[Index].pTask)(); // Run the task
			SCH_tasks_G[Index].RunMe--; // Reset / reduceRunMe flag
			// Periodic tasks will automatically run again
			// − if this is a ’one shot’ task, remove it from the array
			if (SCH_tasks_G[Index].Period == 0){
				SCH_Delete_Task(Index);
			}
			else{
				 sTask temp;
				 temp.Period = SCH_tasks_G[0].Period;
				 temp.pTask = SCH_tasks_G[0].pTask;
				 SCH_Delete_Task(0);
				 SCH_Add_Task(temp.pTask, temp.Period, temp.Period);
			}
		}
	}
};
