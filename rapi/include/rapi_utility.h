

#ifndef _RAPIUTILITY_H_
#define _RAPIUTILITY_H_
		
#include "rapi/rapi_config.h"
#include "rapi/rapi_types.h"
		
		
#ifdef __cplusplus
extern "C"
{
#endif
		
	
#if RAPI_PLATFORM == RAPI_PLATFORM_WINDOWS		
	#define NELEMENTS(array)		/* number of elements in an array */ \
		(sizeof (array) / sizeof ((array) [0]))
#endif



#ifdef __cplusplus
} /* extern "C" */
#endif


#endif /*.h*/

