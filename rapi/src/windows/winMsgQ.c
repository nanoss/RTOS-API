
#include "rapi/rapi_config.h"
#include "rapi/rapi_types.h"


#if OSAPI_PLATFORM == OSAPI_PLATFORM_WINDOWS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <windows.h>

#include "rapi/rapi_config.h"
#include "rapi/rapi_types.h"

RAPI_MSG_Q_ID RAPI_msgQCreate(int maxQueLen, int maxMsgLen)
{
	//return msgQCreate(maxQueLen, maxMsgLen, MSG_Q_FIFO);
}

INT32 RAPI_msgQSend(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 nBytes, int timeout)
{
	//msgQSend(msgQId, buffer, nBytes, timeout, MSG_PRI_NORMAL);
	return 0;
}

INT32 RAPI_msgQReceive(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 maxNBytes, int timeout)
{
	//return msgQReceive(msgQId, buffer, maxNBytes, timeout);
}



#endif

