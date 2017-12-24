

#ifndef _RAPITYPES_H_
#define _RAPITYPES_H_
		
#include "rapi/rapi_config.h"


#if RAPI_PLATFORM == RAPI_PLATFORM_WINDOWS		
	#if defined(_M_IX86)
		typedef signed int INT32;
		typedef unsigned int UINT32;
		typedef signed short INT16;
		typedef unsigned short UINT16;
		typedef signed char INT8;
		typedef unsigned char UINT8;
		typedef __int64 INT64;
		typedef unsigned __int64 UINT64;
		typedef float FLOAT32;
		typedef double DOUBLE64;	
	#else
		#error "x86  error. Please define data-types"
	#endif	
	typedef HANDLE RAPI_SEM_ID;
	typedef void * RAPI_MSG_Q_ID;
#endif

#if RAPI_PLATFORM == RAPI_PLATFORM_VXWORKS	
	typedef SEM_ID RAPI_SEM_ID;
	typedef MSG_Q_ID RAPI_MSG_Q_ID;
#endif

#endif /*.h*/

