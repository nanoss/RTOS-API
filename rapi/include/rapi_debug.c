

#include "rapi/rapi_types.h"


UINT8 rapiCtrlLogStat[RAPI_MAX_PRN_INFO] = {1, 1, 0};

/*
flag: 0=colse; 1=open; 2=closeGroup; 3=openGroup
arg=0 :clean all
*/
void rlogen(UINT32 arg, UINT8 printFlag)
{
	UINT16 i;

	if(arg >= RAPI_MAX_PRN_INFO)
	{
		return;
	}

	if(printFlag == 2)
	{
		for(i = (arg / 10) * 10; i <= arg; i++)
		{
			rapiCtrlLogStat[arg] = 1;
		}
	}
	else if((printFlag == 0) && (arg == 0))
	{
		memset(rapiCtrlLogStat, 0, sizeof(rapiCtrlLogStat));
	}
	else
	{
		rapiCtrlLogStat[arg] = printFlag;
	}
}


