

#ifndef _RAPICONFIG_H_
#define _RAPICONFIG_H_

#define RAPI_PLATFORM_VXWORKS    	1
#define RAPI_PLATFORM_WINDOWS    	2
#define RAPI_PLATFORM_VX653_CAPI 	3 

/* 
If use VX653_CAPI,  please define __VX653_CAPI__ in appConfig.h
 */
#ifndef RAPI_PLATFORM
	#if defined(_MSC_VER) || defined(WIN32)
		#define RAPI_PLATFORM RAPI_PLATFORM_WINDOWS
	#elif defined(__vxworks)
		#define RAPI_PLATFORM RAPI_PLATFORM_VXWORKS
	#elif defined(__VX653_CAPI__)
		#define RAPI_PLATFORM RAPI_PLATFORM_VX653_CAPI
	#else
		#error "Unable to determine RAPI_PLATFORM. Please specify."
	#endif
#endif


/* windows */
#if RAPI_PLATFORM == RAPI_PLATFORM_WINDOWS
	#ifndef APP_BIGEDITION
		#ifdef _M_IX86
			#define APP_BIGEDITION 0
		#else
			#error "Unable to determine endianess. Please specify APP_BIGEDITION"
		#endif
	#endif	
#endif
/* vxWorks */
#if RAPI_PLATFORM == RAPI_PLATFORM_VXWORKS
	#ifndef APP_BIGEDITION
		#ifdef __BIG_ENDIAN__
			#define APP_BIGEDITION 1
		#else
			#define APP_BIGEDITION 0
		#endif
	#endif
#endif
/* vx653_capi */
#if RAPI_PLATFORM == RAPI_PLATFORM_VXWORKS
	#ifndef APP_BIGEDITION
		#ifdef __BIG_ENDIAN__
			#define APP_BIGEDITION 1
		#else
			#define APP_BIGEDITION 0
		#endif
	#endif
#endif

#endif /*.h*/


