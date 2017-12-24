
#include "rapi/rapi_config.h"
#include "rapi/rapi_types.h"


#if OSAPI_PLATFORM == OSAPI_PLATFORM_VXWORKS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <vxWorks.h>
#include <taskLib.h>
#include <taskVarLib.h>
#include <sysLib.h>
#include <tickLib.h>

#include "rapi/rapi_config.h"
#include "rapi/rapi_types.h"


INT32 RAPI_createTask(char * name, int priority, void(*entryPt) (void *), int stackSize)
{
	taskSpawn(name, priority, VX_FP_TASK, stackSize, (FUNCPTR) entryPt, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	
	return 0;
}

void RAPI_taskDelay(int ms)
{
	taskDelay((UINT32) ((sysClkRateGet() * ms + 999) / 1000));
	
	return;
}

#endif

