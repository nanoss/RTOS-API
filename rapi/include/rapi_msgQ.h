

#ifndef _RAPIMSGQ_H_
#define _RAPIMSGQ_H_
		
#include "rapi/rapi_config.h"
#include "rapi/rapi_types.h"

#ifdef __cplusplus
extern "C"
{
#endif


extern RAPI_MSG_Q_ID RAPI_msgQCreate(int maxQueLen, int maxMsgLen);
extern INT32 RAPI_msgQSend(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 nBytes, int timeout);
extern INT32 RAPI_msgQReceive(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 maxNBytes, int timeout);


#ifdef __cplusplus
} /* extern "C" */
#endif




#endif /*.h*/

