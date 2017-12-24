

#ifndef _RAPIDEBUG_H_
#define _RAPIDEBUG_H_

#include "rapi/rapi_config.h"
#include "rapi/rapi_types.h"
#include "rapi/rapi_stdio.h"

	
#ifdef __cplusplus
extern "C"
{
#endif

typedef enum 
{
	ERROR_INFO = 0,  
	TIP_INFO = 1, 
	DBG_INFO = 2, 
	
	/*to add group 10*/
	
	/*to add group 20*/
	

	RAPI_MAX_PRN_INFO = 255
} RAPI_DEBUG_INFO_E;

extern UINT8 rapiCtrlLogStat[RAPI_MAX_PRN_INFO];


#define rlog(flag_, fmt_) do{ \
	if(1 == rapiCtrlLogStat[flag_]) { RAPI_Stdio_printf("line%d:"fmt_, __LINE__);} }while(0)	
#define rlog1(flag_, fmt_, p1_)  do{\
	if(1 == rapiCtrlLogStat[flag_]) { RAPI_Stdio_printf("line%d:"fmt_, __LINE__ , p1_);} }while(0)
#define rlog2(flag_, fmt_, p1_, p2_)  do{\
	if(1 == rapiCtrlLogStat[flag_]) { RAPI_Stdio_printf("line%d:"fmt_, __LINE__ , p1_, p2_);} }while(0)
#define rlog3(flag_, fmt_, p1_, p2_, p3_)  do{\
	if(1 == rapiCtrlLogStat[flag_]) { RAPI_Stdio_printf("line%d:"fmt_, __LINE__ , p1_, p2_, p3_);} }while(0)
#define rlog4(flag_, fmt_, p1_, p2_, p3_, p4_)  do{\
	if(1 == rapiCtrlLogStat[flag_]) { RAPI_Stdio_printf("line%d:"fmt_, __LINE__ , p1_, p2_, p3_, p4_);} }while(0)
#define rlog5(flag_, fmt_, p1_, p2_, p3_, p4_, p5_)  do{\
	if(1 == rapiCtrlLogStat[flag_]) { RAPI_Stdio_printf("line%d:"fmt_, __LINE__ , p1_, p2_, p3_, p4_, p5_);} }while(0)	
#define rlog6(flag_, fmt_, p1_, p2_, p3_, p4_, p5_, p6_)  do{\
	if(1 == rapiCtrlLogStat[flag_]) { RAPI_Stdio_printf("line%d:"fmt_, __LINE__ , p1_, p2_, p3_, p4_, p5_, p6_);} }while(0)
#define rlog7(flag_, fmt_, p1_, p2_, p3_, p4_, p5_, p6_, p7_)  do{\
	if(1 == rapiCtrlLogStat[flag_]) { RAPI_Stdio_printf("line%d:"fmt_, __LINE__ , p1_, p2_, p3_, p4_, p5_, p6_, p7_);} }while(0)
#define rlog8(flag_, fmt_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_)  do{\
	if(1 == rapiCtrlLogStat[flag_]) { RAPI_Stdio_printf("line%d:"fmt_, __LINE__ , p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_);} }while(0)
#define rlog9(flag_, fmt_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_)  do{\
	if(1 == rapiCtrlLogStat[flag_]) { RAPI_Stdio_printf("line%d:"fmt_, __LINE__ , p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_);} }while(0)
	

extern void rlogen(UINT32 arg, UINT8 printFlag);
	

#ifdef __cplusplus
} /* extern "C" */
#endif


#endif /*.h*/

