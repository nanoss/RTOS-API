
#include "Rapi.h"

#ifdef APP_VxWorks653


INT32 createTaskVX653(char * name, int priority, void(*entryPt) (void *), int stackSize)
{
    taskSpawn(name, priority, VX_FP_TASK, stackSize, (FUNCPTR) entryPt, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    return 0;
}

INT32 taskDelayVX653(int ms)
{
    taskDelay((UINT32) ((ms + 8.3) / 16.6));
    return 0;
}


RAPI_SEM_ID semMCreateVX653(void)
{
    return semMCreate(SEM_Q_PRIORITY | SEM_DELETE_SAFE | SEM_INVERSION_SAFE);
}


RAPI_SEM_ID semBCreateVX653(void)
{
    return semBCreate(SEM_Q_PRIORITY | SEM_DELETE_SAFE | SEM_INVERSION_SAFE, SEM_EMPTY);
}


INT32 semTakeVX653(RAPI_SEM_ID semId, int timeout)
{
    /*! 调用信号量等待函数，如果返回值为false 则return -1*/
    if(semTake(semId, (timeout / 1000 / 16.667)) == FALSE)
    {
        return - 1;
    }
    
    return 0;
}

void semGiveVX653(RAPI_SEM_ID semId)
{
    semGive(semId);
    return;
}

RAPI_MSG_Q_ID msgQCreateVX653(int maxQueLen, int maxMsgLen)
{
    return msgQCreate(maxQueLen, maxMsgLen, MSG_Q_FIFO);
}

INT32 msgQSendVX653(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 nBytes, int timeout)
{
    msgQSend(msgQId, buffer, nBytes, timeout, MSG_PRI_NORMAL);
    return 0;
}

INT32 msgQReceiveVX653(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 maxNBytes, int timeout)
{
    return msgQReceive(msgQId, buffer, maxNBytes, timeout);
}

UINT64 rtcGetVX653(void) /*ns*/
{
    return (UINT64)
    tickGet() * 16667 * 1000;
}
#endif

#ifdef APP_VxWorks5_5


INT32 createTaskVX55(char * name, int priority, void(*entryPt) (void *), int stackSize)
{
	taskSpawn(name, priority, VX_FP_TASK, stackSize, (FUNCPTR) entryPt, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return 0;
}

INT32 taskDelayVX55(int ms)
{
	taskDelay((UINT32) ((ms + 8.3) / 16.6));
	return 0;
}

RAPI_SEM_ID semMCreateVX55(void)
{
	return semMCreate(SEM_Q_PRIORITY | SEM_DELETE_SAFE | SEM_INVERSION_SAFE);
}

RAPI_SEM_ID semBCreateVX55(void)
{
	return semBCreate(SEM_Q_PRIORITY | SEM_DELETE_SAFE | SEM_INVERSION_SAFE, SEM_EMPTY);
}

INT32 semTakeVX55(RAPI_SEM_ID semId, int timeout)
{
	/*! 调用信号量等待函数，如果返回值为false 则return -1*/
	if(semTake(semId, (timeout / 1000 / 16.667)) == FALSE)
	{
		return - 1;
	}

	return 0;
}

void semGiveVX55(RAPI_SEM_ID semId)
{
	semGive(semId);
	return;
}

RAPI_MSG_Q_ID msgQCreateVX55(int maxQueLen, int maxMsgLen)
{
	return msgQCreate(maxQueLen, maxMsgLen, MSG_Q_FIFO);
}

INT32 msgQSendVX55(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 nBytes, int timeout)
{
	msgQSend(msgQId, buffer, nBytes, timeout, MSG_PRI_NORMAL);
	return 0;
}


INT32 msgQReceiveVX55(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 maxNBytes, int timeout)
{
	return msgQReceive(msgQId, buffer, maxNBytes, timeout);
}

UINT64 rtcGetVX55(void) /*ns*/
{
	return (UINT64)
	tickGet() * 16667 * 1000;
}

UINT64 getSystemTimeTagVX55(void)
{
	return (UINT64)
	tickGet() * 16667 * 1000;
}

#endif

#ifdef APP_WIN32

INT32 createTaskWIN32(char * name, int priority, void(*entryPt) (void *), int stackSize)
{
	CreateThread(NULL, (DWORD) stackSize, (LPTHREAD_START_ROUTINE) entryPt, NULL, NULL, NULL);
	return 0;
}

INT32 taskDelayWIN32(int ms)
{
	Sleep(ms);
	return 0;
}

RAPI_SEM_ID semMCreateWIN32(void)
{
	return CreateSemaphore(NULL, 1, 1, NULL);
}

RAPI_SEM_ID semBCreateWIN32(void)
{
	return CreateSemaphore(NULL, 0, 1, NULL);
}

INT32 semTakeWIN32(RAPI_SEM_ID semId, int timeout)
{
	if(timeout < 0)
	{
		return WaitForSingleObject(semId, INFINITE);
	}
	else
	{
		return WaitForSingleObject(semId, timeout);
	}
}

void semGiveWIN32(RAPI_SEM_ID semId)
{
	ReleaseSemaphore(semId, 1, NULL);
	return;
}

RAPI_MSG_Q_ID msgQCreateWIN32(int maxQueLen, int maxMsgLen)
{
	return 0;
}

INT32 msgQSendWIN32(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 nBytes, int timeout)
{
	return 0;
}

INT32 msgQReceiveWIN32(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 maxNBytes, int timeout)
{
	return 0;
}

UINT64 rtcGetWIN32(void) /*ns*/
{
	return (UINT64) (GetTickCount()) * 1000 * 1000;
}


#endif



INT32 RAPI_CreateTask(char * name, int priority, void(*entryPt) (void *), int stackSize)
{

#ifdef APP_VxWorks653
	return createTaskVX653(name, priority, entryPt, stackSize);

#endif

#ifdef APP_VxWorks5_5
	return createTaskVX55(name, priority, entryPt, stackSize);

#endif

#ifdef APP_WIN32
	return createTaskWIN32(name, priority, entryPt, stackSize);

#endif
}

INT32 RAPI_TaskDelay(int ms)
{

#ifdef APP_VxWorks653
	taskDelayVX653(ms);
#endif

#ifdef APP_VxWorks5_5
	taskDelayVX55(ms);
#endif

#ifdef APP_WIN32
	taskDelayWIN32(ms);
#endif

	return 0;
}

RAPI_SEM_ID RAPI_SemMCreate(void)
{

#ifdef APP_VxWorks653
	return semMCreateVX653();

#endif

#ifdef APP_VxWorks5_5
	return semMCreateVX55();

#endif

#ifdef APP_WIN32
	return semMCreateWIN32();

#endif
}


RAPI_SEM_ID RAPI_SemBCreate(void)
{

#ifdef APP_VxWorks653
	return semBCreateVX653();

#endif

#ifdef APP_VxWorks5_5
	return semBCreateVX55();

#endif

#ifdef APP_WIN32
	return semBCreateWIN32();

#endif
}


INT32 RAPI_SemTake(RAPI_SEM_ID semId, int timeout)
{
#ifdef APP_VxWorks653
	semTakeVX653(semId, timeout);
#endif

#ifdef APP_VxWorks5_5
	semTakeVX55(semId, timeout);
#endif

#ifdef APP_WIN32
	semTakeWIN32(semId, timeout);
#endif

	return 0;
}

void RAPI_SemGive(RAPI_SEM_ID semId)
{
#ifdef APP_VxWorks653
	semGiveVX653(semId);
#endif

#ifdef APP_VxWorks5_5
	semGiveVX55(semId);
#endif

#ifdef APP_WIN32
	semGiveWIN32(semId);
#endif

	return;
}

RAPI_MSG_Q_ID RAPI_MsgQCreate(int maxQueLen, int maxMsgLen)
{

#ifdef APP_VxWorks653
	return msgQCreateVX653(maxQueLen, maxMsgLen);

#endif

#ifdef APP_VxWorks5_5
	return msgQCreateVX55(maxQueLen, maxMsgLen);

#endif

#ifdef APP_WIN32
	return msgQCreateWIN32(maxQueLen, maxMsgLen);

#endif
}

INT32 RAPI_MsgQSend(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 nBytes, int timeout)
{
#ifdef APP_VxWorks653
	msgQSendVX653(msgQId, buffer, nBytes, timeout);
#endif

#ifdef APP_VxWorks5_5
	msgQSendVX55(msgQId, buffer, nBytes, timeout);
#endif

#ifdef APP_WIN32
	msgQSendWIN32(msgQId, buffer, nBytes, timeout);
#endif

	return 0;
}

INT32 RAPI_MsgQReceive(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 maxNBytes, int timeout)
{
#ifdef APP_VxWorks653
	return msgQReceiveVX653(msgQId, buffer, maxNBytes, timeout);

#endif

#ifdef APP_VxWorks5_5
	return msgQReceiveVX55(msgQId, buffer, maxNBytes, timeout);

#endif

#ifdef APP_WIN32
	return msgQReceiveWIN32(msgQId, buffer, maxNBytes, timeout);

#endif

	return 0;
}

UINT64 RAPI_RtcGet(void) /*ns*/
{
#ifdef APP_VxWorks653
	return rtcGetVX653();

#endif

#ifdef APP_VxWorks5_5
	return rtcGetVX55();

#endif

#ifdef APP_WIN32
	return rtcGetWIN32();

#endif
}

