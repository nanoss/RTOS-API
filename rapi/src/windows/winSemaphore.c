
#include "rapi/rapi_config.h"
#include "rapi/rapi_types.h"


#if OSAPI_PLATFORM == OSAPI_PLATFORM_WINDOWS

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <windows.h>


#include "rapi/rapi_config.h"
#include "rapi/rapi_types.h"


RAPI_SEM_ID RAPI_semMCreate(void)
{
	return CreateSemaphore(NULL, 1, 1, NULL);
}

RAPI_SEM_ID RAPI_semBCreate(void)
{
	return CreateSemaphore(NULL, 0, 1, NULL);
}

INT32 RAPI_semTake(RAPI_SEM_ID semId, int timeout)
{
	if(timeout == -1)
	{
		return WaitForSingleObject(semId, INFINITE);
	}
	else
	{
		return WaitForSingleObject(semId, timeout);
	}
}


void RAPI_semGive(RAPI_SEM_ID semId)
{
	ReleaseSemaphore(semId, 1, NULL);
	return;
}


#endif

