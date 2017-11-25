

#ifndef _RAPIOS_H_
#define _RAPIOS_H_




#ifdef APP_VxWorks5_5
#include <vxWorks.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semLib.h>
#include <taskLib.h>
#include <msgQLib.h>
#include <logLib.h>
#include <tickLib.h>
#include <sysLib.h>
#include <intLib.h>
#include <ioLib.h>
#include <iv.h>
#include <time.h>
#include <math.h>
#endif

#ifdef APP_VxWorks653
#include <vxWorks.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semLib.h>
#include <taskLib.h>
#include <msgQLib.h>
#include <logLib.h>
#include <tickLib.h>
#include <sysLib.h>
#include <intLib.h>
#include <ioLib.h>
#include <iv.h>
#include <time.h>
#include <math.h>

#endif

#ifdef APP_WIN32
//#include <StdAfx.h>
#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include "time.h"
#include <windows.h>
#include <process.h>
#endif


#ifdef APP_WIN32

typedef unsigned int UINT32;
typedef int INT32;
typedef unsigned short UINT16;
typedef short INT16;
typedef signed char INT8;
typedef unsigned char UINT8;
typedef int BOOL;
typedef int STATUS;
typedef unsigned long long UINT64;

//#define NULL					0
#ifndef OK
#define OK						0
#endif

#ifndef ERROR
#define ERROR					-1
#endif

#endif



#endif

