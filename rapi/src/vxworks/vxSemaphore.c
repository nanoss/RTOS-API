
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


RAPI_SEM_ID RAPI_semMCreate(void)
{
	return semMCreate(SEM_Q_PRIORITY | SEM_DELETE_SAFE | SEM_INVERSION_SAFE);
}

RAPI_SEM_ID RAPI_semBCreate(void)
{
	return semBCreate(SEM_Q_PRIORITY | SEM_DELETE_SAFE | SEM_INVERSION_SAFE, SEM_EMPTY);
}

INT32 RAPI_semTake(RAPI_SEM_ID semId, int timeout)
{
	if(semTake(semId, ((UINT32) ((sysClkRateGet() * ms + 999) / 1000))) == FALSE)
	{
		return - 1;
	}

	return 0;
}

void RAPI_semGive(RAPI_SEM_ID semId)
{
	semGive(semId);
	return;
}


#endif

