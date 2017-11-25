


#include "AppHead.h"
#include "rapi.h"

/*!****************************************************************************
 创建任务
\author          nanoss
\date			 2017/10/30
\brief			 完成任务创建及启动
\param[in]		 name	 任务名称 输入任务名称
\param[in]		 priority	 优先级 输入任务的优先级
\param[in]		 entryPt		函数入口 任务函数入口
\param[in]		 stackSize	栈大小 任务栈空间
\return 		 INT32
*******************************************************************************/
INT32 RAPI_CreateTask(char * name, int priority, void(*entryPt) (void *), int stackSize)
{
#ifdef APP_ACoreOS653
	return createTaskA653(name, priority, entryPt, stackSize);

#endif

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

/*!****************************************************************************
 任务延时
\author 		 nanos
\date			 2017/10/30
\brief			 用于延迟当前任务指定时间
\param[in]		 ms	 延迟时间 延时的毫秒数
\return 		 INT32
*******************************************************************************/
INT32 RAPI_TaskDelay(int ms)
{
#ifdef APP_ACoreOS653
	taskDelayA653(ms);
#endif

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

/*!****************************************************************************
 创建互斥信号量
\author 		 nanoss
\date			 2017/10/30
\brief			 创建互斥信号量
\return 		 RAPI_SEM_ID
*******************************************************************************/
RAPI_SEM_ID RAPI_SemMCreate(void)
{
#ifdef APP_ACoreOS653
	return semMCreateA653();

#endif

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

/*!****************************************************************************
 创建通知信号量
\author 		 nanoss
\date			 2017/10/30
\brief			 创建通知信号量
\return 		 RAPI_SEM_ID
*******************************************************************************/
RAPI_SEM_ID RAPI_SemBCreate(void)
{
#ifdef APP_ACoreOS653
	return semBCreateA653();

#endif

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

/*!****************************************************************************
 信号量获取
\author 		 nanoss
\date			 2017/10/30
\brief			 获取信号量
\param[in]		 semId	信号量ID 用于输入信号量
\param[in]		 timeout		超时时间 用于输入超时间
\return 		 INT32
\attention 单位：微秒
*******************************************************************************/
INT32 RAPI_SemTake(RAPI_SEM_ID semId, int timeout)
{
#ifdef APP_ACoreOS653
	semTakeA653(semId, timeout);
#endif

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

/*!****************************************************************************
 信号量释放
\author 		 nanoss
\date			 2017/10/30
\brief			 释放信号量
\param[in]		 semId	信号量ID 用于输入信号量
\return 		 INT32
*******************************************************************************/
void RAPI_SemGive(RAPI_SEM_ID semId)
{
#ifdef APP_ACoreOS653
	semGiveA653(semId);
#endif

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

/*!****************************************************************************
 创建消息队列
\author 		 nanoss
\date			 2017/10/30
\brief			 创建消息队列
\param[in]		 maxQueLen	消息个数 队列中最大消息个数
\param[in]		 maxMsgLen	消息长度 单个消息内容长度
\return 		 RAPI_MSG_Q_ID
*******************************************************************************/
RAPI_MSG_Q_ID RAPI_MsgQCreate(int maxQueLen, int maxMsgLen)
{
#ifdef APP_ACoreOS653
	return msgQCreateA653(maxQueLen, maxMsgLen);

#endif

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

/*!****************************************************************************
 消息队列入队
\author 		 nanoss
\date			 2017/10/30
\brief			 将消息放入消息队列
\param[in]		 msgQId	 队列ID 标识消息队列
\param[in]		 buffer	 数据缓存 消息内容
\param[in]		 nBytes	 数据长度 数据内容长度
\param[in]		 timeout		等待时间 最长等待时间
\return 		 INT32
\attention timeout,等待时间(ms)
*******************************************************************************/
INT32 RAPI_MsgQSend(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 nBytes, int timeout)
{
#ifdef APP_ACoreOS653
	msgQSendA653(msgQId, buffer, nBytes, timeout);
#endif

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

/*!****************************************************************************
 消息队列出队
\author 		 nanoss
\date			 2017/10/30
\brief			 将消息取出消息队列
\param[in]		 msgQId	 队列ID 标识消息队列
\param[in]		 buffer	 数据缓存 消息内容
\param[in]		 maxNBytes	数据长度 数据内容长度
\param[in]		 timeout		等待时间 最长等待时间
\return 		 INT32
\attention timeout,等待时间(ms)
*******************************************************************************/
INT32 RAPI_MsgQReceive(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 maxNBytes, int timeout)
{
#ifdef APP_ACoreOS653
	return msgQReceiveA653(msgQId, buffer, maxNBytes, timeout);

#endif

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

/*!****************************************************************************
 系统RTC获取
\author 		 nanoss
\date			 2017/10/30
\brief			 系统RTC获取
\return 		 UINT64
\attention 系统RTC(ns)
*******************************************************************************/
UINT64 RAPI_RtcGet(void) /*ns*/
{
#ifdef APP_ACoreOS653
	return rtcGetA653();

#endif

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


#ifdef APP_VxWorks653

/*!****************************************************************************
 创建任务
\author 		 nanoss
\date			 2017/10/30
\brief			 完成任务创建及启动
\param[in]		 name	 任务名称 输入任务名称
\param[in]		 priority	 优先级 输入任务的优先级
\param[in]		 entryPt		函数入口 任务函数入口
\param[in]		 stackSize	栈大小 任务栈空间
\return 		 INT32
*******************************************************************************/
INT32 createTaskVX653(char * name, int priority, void(*entryPt) (void *), int stackSize)
{
	PROCESS_ATTRIBUTE_TYPE stProcessAttr;
	PROCESS_ID_TYPE processId = 0;
	RETURN_CODE_TYPE retCode = NO_ERROR;

	strcpy(stProcessAttr.NAME, name);
	stProcessAttr.ENTRY_POINT = entryPt;
	stProcessAttr.STACK_SIZE = stackSize;
	stProcessAttr.BASE_PRIORITY = priority;
	stProcessAttr.PERIOD = 25000000ll;
	stProcessAttr.TIME_CAPACITY = -1;
	stProcessAttr.DEADLINE = SOFT;
	CAPI_CREATE_PROCESS(&stProcessAttr, &processId, &retCode);
	CAPI_START(processId, &retCode);
	return 0;
}

/*!****************************************************************************
 任务延时
\author 		 nanoss
\date			 2017/10/30
\brief			 用于延迟当前任务指定时间
\param[in]		 ms	 延迟时间 延时的毫秒数
\return 		 INT32
*******************************************************************************/
INT32 taskDelayVX653(int ms)
{
	/*!var
	*\parblock
	*\param ret ':RETURN_CODE_TYPE:' 返回值 用于获取返回码
	*\endparblock
	*/
	RETURN_CODE_TYPE ret;

	/*! 调用系统的SUSPEND_SELF延迟指定毫秒数*/
	CAPI_SUSPEND_SELF(((UINT64) ms) * 1000000, &ret);
	return 0;
}

/*!****************************************************************************
 创建互斥信号量
\author 		 nanoss
\date			 2017/10/30
\brief			 创建互斥信号量
\return 		 RAPI_SEM_ID
*******************************************************************************/
RAPI_SEM_ID semMCreateVX653(void)
{
	/*!var
	*\parblock
	*\param mySemMCount ':static INT8:' 信号量计数 用于区别信号量
	*\param semNameBuf ':char:' 信号量名称缓存 用于生成信号量名称
	*\endparblock
	*/
	static INT8 mySemMCount = 0;
	char semNameBuf[20] = "semM";
	SEMAPHORE_ID_TYPE semId;
	RETURN_CODE_TYPE ret = 0;

	/*! 根据信号量计数生成信号量名称以区分信号量*/
	semNameBuf[4] = (mySemMCount / 10) + '0';
	semNameBuf[5] = (mySemMCount % 10) + '0';
	semNameBuf[6] = 0;

	/*! 信号量计数++*/
	mySemMCount++;

	/*! 调用创建信号量函数*/
	CAPI_CREATE_SEMAPHORE(semNameBuf, 1, 1, 0, &semId, &ret);
	return semId;
}

/*!****************************************************************************
 创建通知信号量
\author 		 nanoss
\date			 2017/10/30
\brief			 创建通知信号量
\return 		 RAPI_SEM_ID
*******************************************************************************/
RAPI_SEM_ID semBCreateVX653(void)
{
	/*!var
	*\parblock
	*\param mySemMCount ':static INT8:' 信号量计数 用于区别信号量
	*\param semNameBuf ':char:' 信号量名称缓存 用于生成信号量名称
	*\endparblock
	*/
	static INT8 mySemBCount = 0;
	char semNameBuf[20] = "semB";
	SEMAPHORE_ID_TYPE semId;
	RETURN_CODE_TYPE ret = 0;

	/*! 根据信号量计数生成信号量名称以区分信号量*/
	semNameBuf[4] = (mySemBCount / 10) + '0';
	semNameBuf[5] = (mySemBCount % 10) + '0';
	semNameBuf[6] = 0;

	/*! 信号量计数++*/
	mySemBCount++;

	/*! 调用任务工厂类的创建信号量函数*/
	CAPI_CREATE_SEMAPHORE(semNameBuf, 0, 1, 0, &semId, &ret);
	return semId;
}

/*!****************************************************************************
 信号量获取
\author 		 nanoss
\date			 2017/10/30
\brief			 获取信号量
\param[in]		 semId	信号量ID 用于输入信号量
\param[in]		 timeout		超时时间 用于输入超时间
\return 		 INT32
\attention 单位：微秒
*******************************************************************************/
INT32 semTakeVX653(RAPI_SEM_ID semId, int timeout)
{
	RETURN_CODE_TYPE ret = 0;

	/*! 调用信号量等待函数，如果返回值为false 则return -1*/
	CAPI_WAIT_SEMAPHORE(semId, timeout, &ret);

	if(ret != NO_ERROR)
	{
		return - 1;
	}

	return 0;
}

/*!****************************************************************************
 信号量释放
\author 		 nanoss
\date			 2017/10/30
\brief			 释放信号量
\param[in]		 semId	信号量ID 用于输入信号量
\return 		 INT32
*******************************************************************************/
void semGiveVX653(RAPI_SEM_ID semId)
{
	RETURN_CODE_TYPE ret = 0;

	/*! 调用信号量释放函数*/
	CAPI_SIGNAL_SEMAPHORE(semId, &ret);
	return;
}

/*!****************************************************************************
 创建消息队列
\author 		 nanoss
\date			 2017/10/30
\brief			 创建消息队列
\param[in]		 maxQueLen	消息个数 队列中最大消息个数
\param[in]		 maxMsgLen	消息长度 单个消息内容长度
\return 		 RAPI_MSG_Q_ID
*******************************************************************************/
RAPI_MSG_Q_ID msgQCreateVX653(int maxQueLen, int maxMsgLen)
{
	/*!var
	*\parblock
	*\param mySemMCount ':static INT8:' 计数 用于区别
	*\param semNameBuf ':char:' 名称缓存 用于生成名称
	*\endparblock
	*/
	static INT8 myMsgQCount = 0;
	char msgQNameBuf[20] = "semB";
	BUFFER_ID_TYPE bufId;
	RETURN_CODE_TYPE ret = 0;

	/*! 根据计数生成信号量名称以区分信号量*/
	msgQNameBuf[4] = (myMsgQCount / 10) + '0';
	msgQNameBuf[5] = (myMsgQCount % 10) + '0';
	msgQNameBuf[6] = 0;

	/*! 计数++*/
	myMsgQCount++;

	/*! 调用任务工厂类的创建函数*/
	CAPI_CREATE_BUFFER(msgQNameBuf, maxMsgLen, maxQueLen, 0, &bufId, &ret);
	return bufId;
}

/*!****************************************************************************
 消息队列入队
\author 		 nanoss
\date			 2017/10/30
\brief			 将消息放入消息队列
\param[in]		 msgQId	 队列ID 标识消息队列
\param[in]		 buffer	 数据缓存 消息内容
\param[in]		 nBytes	 数据长度 数据内容长度
\param[in]		 timeout		等待时间 最长等待时间
\return 		 INT32
\attention timeout,等待时间(ms)
*******************************************************************************/
INT32 msgQSendVX653(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 nBytes, int timeout)
{
	RETURN_CODE_TYPE ret = 0;

	/*! 调用系统的消息队列put函数，如果返回值为false则return -1*/
	CAPI_SEND_BUFFER(msgQId, (UINT8 *) buffer, (INT32) nBytes, timeout, &ret);

	if(ret != NO_ERROR)
	{
		return - 1;
	}

	return 0;
}

/*!****************************************************************************
 消息队列出队
\author 		 nanoss
\date			 2017/10/30
\brief			 将消息取出消息队列
\param[in]		 msgQId	 队列ID 标识消息队列
\param[in]		 buffer	 数据缓存 消息内容
\param[in]		 maxNBytes	数据长度 数据内容长度
\param[in]		 timeout		等待时间 最长等待时间
\return 		 INT32
\attention timeout,等待时间(ms)
*******************************************************************************/
INT32 msgQReceiveVX653(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 maxNBytes, int timeout)
{
	RETURN_CODE_TYPE ret = 0;
	long int recvMsgLen = 0;

	/*! 调用系统的消息队列put函数，如果返回值为false则return -1*/
	CAPI_RECEIVE_BUFFER(msgQId, timeout, (UINT8 *) buffer, &recvMsgLen, &ret);
	return (INT32)
	recvMsgLen;
}

/*!****************************************************************************
 系统RTC获取
\author 		 nanoss
\date			 2017/10/30
\brief			 系统RTC获取
\return 		 UINT64
\attention 系统RTC(ns)
*******************************************************************************/
UINT64 rtcGetVX653(void) /*ns*/
{
	SYSTEM_TIME_TYPE sysTime = 0;
	RETURN_CODE_TYPE ret = 0;

	CAPI_GET_ALT(&sysTime, &ret);
	return sysTime;
}
#endif

#ifdef APP_VxWorks5_5

/*!****************************************************************************
 创建任务
\author 		 nanoss
\date			 2017/10/30
\brief			 完成任务创建及启动
\param[in]		 name	 任务名称 输入任务名称
\param[in]		 priority	 优先级 输入任务的优先级
\param[in]		 entryPt		函数入口 任务函数入口
\param[in]		 stackSize	栈大小 任务栈空间
\return 		 INT32
*******************************************************************************/
INT32 createTaskVX55(char * name, int priority, void(*entryPt) (void *), int stackSize)
{
	taskSpawn(name, priority, VX_FP_TASK, stackSize, (FUNCPTR) entryPt, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return 0;
}

/*!****************************************************************************
 任务延时
\author 		 nanoss
\date			 2017/10/30
\brief			 用于延迟当前任务指定时间
\param[in]		 ms	 延迟时间 延时的毫秒数
\return 		 INT32
*******************************************************************************/
INT32 taskDelayVX55(int ms)
{
	taskDelay((UINT32) ((ms + 8.3) / 16.6));
	return 0;
}

/*!****************************************************************************
 创建互斥信号量
\author 		 nanoss
\date			 2017/10/30
\brief			 创建互斥信号量
\return 		 RAPI_SEM_ID
*******************************************************************************/
RAPI_SEM_ID semMCreateVX55(void)
{
	return semMCreate(SEM_Q_PRIORITY | SEM_DELETE_SAFE | SEM_INVERSION_SAFE);
}

/*!****************************************************************************
 创建通知信号量
\author 		 nanoss
\date			 2017/10/30
\brief			 创建通知信号量
\return 		 RAPI_SEM_ID
*******************************************************************************/
RAPI_SEM_ID semBCreateVX55(void)
{
	return semBCreate(SEM_Q_PRIORITY | SEM_DELETE_SAFE | SEM_INVERSION_SAFE, SEM_EMPTY);
}

/*!****************************************************************************
 信号量获取
\author 		 nanoss
\date			 2017/10/30
\brief			 获取信号量
\param[in]		 semId	信号量ID 用于输入信号量
\param[in]		 timeout		超时时间 用于输入超时间
\return 		 INT32
\attention 单位：微秒
*******************************************************************************/
INT32 semTakeVX55(RAPI_SEM_ID semId, int timeout)
{
	/*! 调用信号量等待函数，如果返回值为false 则return -1*/
	if(semTake(semId, (timeout / 1000 / 16.667)) == FALSE)
	{
		return - 1;
	}

	return 0;
}

/*!****************************************************************************
 信号量释放
\author 		 nanoss
\date			 2017/10/30
\brief			 释放信号量
\param[in]		 semId	信号量ID 用于输入信号量
\return 		 INT32
*******************************************************************************/
void semGiveVX55(RAPI_SEM_ID semId)
{
	semGive(semId);
	return;
}

/*!****************************************************************************
 创建消息队列
\author 		 nanoss
\date			 2017/10/30
\brief			 创建消息队列
\param[in]		 maxQueLen	消息个数 队列中最大消息个数
\param[in]		 maxMsgLen	消息长度 单个消息内容长度
\return 		 RAPI_MSG_Q_ID
*******************************************************************************/
RAPI_MSG_Q_ID msgQCreateVX55(int maxQueLen, int maxMsgLen)
{
	return msgQCreate(maxQueLen, maxMsgLen, MSG_Q_FIFO);
}

/*!****************************************************************************
 消息队列入队
\author 		 nanoss
\date			 2017/10/30
\brief			 将消息放入消息队列
\param[in]		 msgQId	 队列ID 标识消息队列
\param[in]		 buffer	 数据缓存 消息内容
\param[in]		 nBytes	 数据长度 数据内容长度
\param[in]		 timeout		等待时间 最长等待时间
\return 		 INT32
\attention timeout,等待时间(ms)
*******************************************************************************/
INT32 msgQSendVX55(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 nBytes, int timeout)
{
	msgQSend(msgQId, buffer, nBytes, timeout, MSG_PRI_NORMAL);
	return 0;
}

/*!****************************************************************************
 消息队列出队
\author 		 nanoss
\date			 2017/10/30
\brief			 将消息取出消息队列
\param[in]		 msgQId	 队列ID 标识消息队列
\param[in]		 buffer	 数据缓存 消息内容
\param[in]		 maxNBytes	数据长度 数据内容长度
\param[in]		 timeout		等待时间 最长等待时间
\return 		 INT32
\attention timeout,等待时间(ms)
*******************************************************************************/
INT32 msgQReceiveVX55(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 maxNBytes, int timeout)
{
	return msgQReceive(msgQId, buffer, maxNBytes, timeout);
}

/*!****************************************************************************
 系统RTC获取
\author 		 nanoss
\date			 2017/10/30
\brief			 系统RTC获取
\return 		 UINT64
\attention 系统RTC(ns)
*******************************************************************************/
UINT64 rtcGetVX55(void) /*ns*/
{
	return (UINT64)
	tickGet() * 16667 * 1000;
}

/*!****************************************************************************
 获取网络系统时标
\author 		 nanoss
\date			 2017/10/30
\brief			 获取网络系统时标
\return 		 UINT64
\attention 系统时标(ns)
*******************************************************************************/
UINT64 getSystemTimeTagVX55(void)
{
	return (UINT64)
	tickGet() * 16667 * 1000;
}

#endif

#ifdef APP_WIN32

/*!****************************************************************************
 创建任务
\author 		 nanoss
\date			 2017/10/30
\brief			 完成任务创建及启动
\param[in]		 name	 任务名称 输入任务名称
\param[in]		 priority	 优先级 输入任务的优先级
\param[in]		 entryPt		函数入口 任务函数入口
\param[in]		 stackSize	栈大小 任务栈空间
\return 		 INT32
*******************************************************************************/
INT32 createTaskWIN32(char * name, int priority, void(*entryPt) (void *), int stackSize)
{
	CreateThread(NULL, (DWORD) stackSize, (LPTHREAD_START_ROUTINE) entryPt, NULL, NULL, NULL);
	return 0;
}

/*!****************************************************************************
 任务延时
\author 		 nanoss
\date			 2017/10/30
\brief			 用于延迟当前任务指定时间
\param[in]		 ms	 延迟时间 延时的毫秒数
\return 		 INT32
*******************************************************************************/
INT32 taskDelayWIN32(int ms)
{
	Sleep(ms);
	return 0;
}

/*!****************************************************************************
 创建互斥信号量
\author 		 nanoss
\date			 2017/10/30
\brief			 创建互斥信号量
\return 		 RAPI_SEM_ID
*******************************************************************************/
RAPI_SEM_ID semMCreateWIN32(void)
{
	return CreateSemaphore(NULL, 1, 1, NULL);
}

/*!****************************************************************************
 创建通知信号量
\author 		 nanoss
\date			 2017/10/30
\brief			 创建通知信号量
\return 		 RAPI_SEM_ID
*******************************************************************************/
RAPI_SEM_ID semBCreateWIN32(void)
{
	return CreateSemaphore(NULL, 0, 1, NULL);
}

/*!****************************************************************************
 信号量获取
\author 		 nanoss
\date			 2017/10/30
\brief			 获取信号量
\param[in]		 semId	信号量ID 用于输入信号量
\param[in]		 timeout		超时时间 用于输入超时间
\return 		 INT32
\attention 单位：微秒
*******************************************************************************/
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

/*!****************************************************************************
 信号量释放
\author 		 nanoss
\date			 2017/10/30
\brief			 释放信号量
\param[in]		 semId	信号量ID 用于输入信号量
\return 		 INT32
*******************************************************************************/
void semGiveWIN32(RAPI_SEM_ID semId)
{
	ReleaseSemaphore(semId, 1, NULL);
	return;
}

/*!****************************************************************************
 创建消息队列
\author 		 nanoss
\date			 2017/10/30
\brief			 创建消息队列
\param[in]		 maxQueLen	消息个数 队列中最大消息个数
\param[in]		 maxMsgLen	消息长度 单个消息内容长度
\return 		 RAPI_MSG_Q_ID
*******************************************************************************/
RAPI_MSG_Q_ID msgQCreateWIN32(int maxQueLen, int maxMsgLen)
{
	return 0;
}

/*!****************************************************************************
 消息队列入队
\author 		 nanoss
\date			 2017/10/30
\brief			 将消息放入消息队列
\param[in]		 msgQId	 队列ID 标识消息队列
\param[in]		 buffer	 数据缓存 消息内容
\param[in]		 nBytes	 数据长度 数据内容长度
\param[in]		 timeout		等待时间 最长等待时间
\return 		 INT32
\attention timeout,等待时间(ms)
*******************************************************************************/
INT32 msgQSendWIN32(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 nBytes, int timeout)
{
	return 0;
}

/*!****************************************************************************
 消息队列出队
\author 		 nanoss
\date			 2017/10/30
\brief			 将消息取出消息队列
\param[in]		 msgQId	 队列ID 标识消息队列
\param[in]		 buffer	 数据缓存 消息内容
\param[in]		 maxNBytes	数据长度 数据内容长度
\param[in]		 timeout		等待时间 最长等待时间
\return 		 INT32
\attention timeout,等待时间(ms)
*******************************************************************************/
INT32 msgQReceiveWIN32(RAPI_MSG_Q_ID msgQId, char * buffer, UINT32 maxNBytes, int timeout)
{
	return 0;
}

/*!****************************************************************************
 系统RTC获取
\author 		 nanoss
\date			 2017/10/30
\brief			 系统RTC获取
\return 		 UINT64
\attention 系统RTC(ns)
*******************************************************************************/
UINT64 rtcGetWIN32(void) /*ns*/
{
	return (UINT64) (GetTickCount()) * 1000 * 1000;
}


#endif

