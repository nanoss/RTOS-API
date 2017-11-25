

#ifndef _RAPIPUB_H_
#define _RAPIPUB_H_

#include "Rapios.h"


#ifdef APP_VxWorks5_5
typedef SEM_ID RAPI_SEM_ID;
typedef MSG_Q_ID RAPI_MSG_Q_ID;

#endif

#ifdef APP_VxWorks653
typedef SEMAPHORE_ID_TYPE RAPI_SEM_ID;
typedef BUFFER_ID_TYPE RAPI_MSG_Q_ID;

#endif

#ifdef APP_WIN32
typedef HANDLE RAPI_SEM_ID;
typedef void * RAPI_MSG_Q_ID;

#endif


#define APPTASK_IDLE			133
#define APPTASK_BELOW_NORMAL	132
#define APPTASK_NOMAL			131
#define APPTASK_ABOVE_NORMAL	130
#define APPTASK_HIGH_PRIORITY	130


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
#endif

