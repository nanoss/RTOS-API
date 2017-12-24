
#include "rapi/rapi_config.h"
#include "rapi/rapi_types.h"

#if OSAPI_PLATFORM == OSAPI_PLATFORM_WINDOWS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <windows.h>
#include <process.h>

#include "rapi/rapi_config.h"
#include "rapi/rapi_types.h"

INT32 RAPI_createTask(char * name, int priority, void(*entryPt) (void *), int stackSize)
{
	CreateThread(NULL, (DWORD) stackSize, (LPTHREAD_START_ROUTINE) entryPt, NULL, NULL, NULL);
	
	return 0;
}

void RAPI_taskDelay(int ms)
{
	Sleep(ms);
	
	return;
}


#endif

