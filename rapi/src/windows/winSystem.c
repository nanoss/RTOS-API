

#include "rapi/rapi_config.h"
#include "rapi/rapi_types.h"




#if OSAPI_PLATFORM ==  OSAPI_PLATFORM_WINDOWS

#include <stdlib.h>
#include <windows.h>


void RAPI_Get_Time(UINT64* pSysTime)
{
	*pSysTime = (UINT64) (GetTickCount()) * 1000 * 1000;
	
	return;
}

#endif

