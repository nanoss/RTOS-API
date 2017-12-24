

#ifndef _RAPITHREAD_H_
#define _RAPITHREAD_H_
		
#include "rapi/rapi_config.h"
#include "rapi/rapi_types.h"

#ifdef __cplusplus
extern "C"
{
#endif


extern INT32 RAPI_createTask(char * name, int priority, void(*entryPt) (void *), int stackSize);
extern void RAPI_taskDelay(int ms);


#ifdef __cplusplus
} /* extern "C" */
#endif




#endif /*.h*/

