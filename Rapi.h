

#ifndef _RAPI_H_
#define _RAPI_H_

#include "Rapios.h"


#ifdef APP_VxWorks5_5
typedef SEM_ID RAPI_SEM_ID;
typedef MSG_Q_ID RAPI_MSG_Q_ID;

#endif

#ifdef APP_VxWorks653
typedef SEM_ID RAPI_SEM_ID;
typedef MSG_Q_ID RAPI_MSG_Q_ID;

#endif

#ifdef APP_WIN32
typedef HANDLE RAPI_SEM_ID;
typedef void * RAPI_MSG_Q_ID;

#endif

#pragma pack(1) 				

/*日期时间定义*/
typedef struct 
{
UINT32	year;
UINT32	month;
UINT32	day;
UINT32	hour;
UINT32	minute;
UINT32	second;
UINT32	msecond;
} RAPI_DATE_TIME_ST;

#pragma pack()		

INT32 RAPI_CreateTask(char * name, int priority, void(*entryPt) (void *), int stackSize);
INT32 RAPI_TaskDelay(int ms);
RAPI_SEM_ID RAPI_SemMCreate(void);
RAPI_SEM_ID RAPI_SemBCreate(void);
INT32 RAPI_SemTake(RAPI_SEM_ID semId, int timeout);
void RAPI_SemGive(RAPI_SEM_ID semId);
RAPI_MSG_Q_ID RAPI_MsgQCreate(int maxQueLen, int maxMsgLen);
INT32 RAPI_MsgQSend(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 nBytes, int timeout);
INT32 RAPI_MsgQReceive(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 maxNBytes, int timeout);
UINT64 RAPI_RtcGet(); /*ns*/
UINT64 RAPI_GetSystemTimeTag();

#endif

