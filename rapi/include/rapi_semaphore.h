

#ifndef _RAPISEMAPHORE_H_
#define _RAPISEMAPHORE_H_

#include "rapi/rapi_config.h"
#include "rapi/rapi_types.h"

#ifdef __cplusplus
extern "C"
{
#endif

extern RAPI_SEM_ID RAPI_SemMCreate(void);
extern RAPI_SEM_ID RAPI_SemBCreate(void);
extern INT32 RAPI_SemTake(RAPI_SEM_ID semId, int timeout);/*ms*/
extern void RAPI_SemGive(RAPI_SEM_ID semId);


#ifdef __cplusplus
} /* extern "C" */
#endif




#endif /*.h*/

