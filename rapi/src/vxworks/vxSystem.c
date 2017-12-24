

#include "rapi/rapi_config.h"
#include "rapi/rapi_types.h"



#if RAPI_PLATFORM == RAPI_PLATFORM_VXWORKS
#include <vxWorks.h>
#include <taskLib.h>
#include <stdlib.h>
#include <limits.h>
#include <sysLib.h>
#include <tickLib.h>
#include <objLib.h>
#include <time.h>

#include "rapi/rapi_config.h"
#include "rapi/rapi_types.h"


void RAPI_Get_Time(UINT64* pSysTime)
{
	#if 1
    struct timespec clk_time;

	if(pSysTime == NULL)
	{
		return;
	}
    if (clock_gettime(CLOCK_REALTIME, &clk_time) == -1)
    {
        *pSysTime = 0;
    }

    *pSysTime =(UINT64)clk_time.tv_sec + clk_time.tv_nsec;
	#else
	 *pSysTime = (UINT64)tickGet() * 1000 * 1000 * 1000 / sysClkRateGet();
	#endif
	
    return;
}



#endif

