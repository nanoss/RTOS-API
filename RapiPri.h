

#ifndef _RAPIPRI_H_
#define _RAPIPRI_H_
#include "RapiPub.h"
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

#ifdef APP_VxWorks653
INT32 createTaskVX653(char * name, int priority, void(*entryPt) (void *), int stackSize);
INT32 taskDelayVX653(int ms);
RAPI_SEM_ID semMCreateVX653(void);
RAPI_SEM_ID semBCreateVX653(void);
INT32 semTakeVX653(RAPI_SEM_ID semId, int timeout);
void semGiveVX653(RAPI_SEM_ID semId);
RAPI_MSG_Q_ID msgQCreateVX653(int maxQueLen, int maxMsgLen);
INT32 msgQSendVX653(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 nBytes, int timeout);
INT32 msgQReceiveVX653(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 maxNBytes, int timeout);
UINT64 rtcGetVX653(void);
UINT64 getSystemTimeTagVX653(void);

#endif

#ifdef APP_VxWorks5_5
INT32 createTaskVX55(char * name, int priority, void(*entryPt) (void *), int stackSize);
INT32 taskDelayVX55(int ms);
RAPI_SEM_ID semMCreateVX55(void);
RAPI_SEM_ID semBCreateVX55(void);
INT32 semTakeVX55(RAPI_SEM_ID semId, int timeout);
void semGiveVX55(RAPI_SEM_ID semId);
RAPI_MSG_Q_ID msgQCreateVX55(int maxQueLen, int maxMsgLen);
INT32 msgQSendVX55(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 nBytes, int timeout);
INT32 msgQReceiveVX55(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 maxNBytes, int timeout);
UINT64 rtcGetVX55(void);
UINT64 getSystemTimeTagVX55(void);

#endif

#ifdef APP_WIN32
INT32 createTaskWIN32(char * name, int priority, void(*entryPt) (void *), int stackSize);
INT32 taskDelayWIN32(int ms);
RAPI_SEM_ID semMCreateWIN32(void);
RAPI_SEM_ID semBCreateWIN32(void);
INT32 semTakeWIN32(RAPI_SEM_ID semId, int timeout);
void semGiveWIN32(RAPI_SEM_ID semId);
RAPI_MSG_Q_ID msgQCreateWIN32(int maxQueLen, int maxMsgLen);
INT32 msgQSendWIN32(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 nBytes, int timeout);
INT32 msgQReceiveWIN32(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 maxNBytes, int timeout);
UINT64 rtcGetWIN32(void);
UINT64 getSystemTimeTagWIN32(void);

#endif

#endif

