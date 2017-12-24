

#include "rapi/rapi_config.h"


#if RAPI_PLATFORM ==  RAPI_PLATFORM_VXWORKS

#include <stdio.h>
#include <stdarg.h>

#include "rapi/rapi_types.h"


void RAPI_Stdio_printf(const char *format,...)
{
    va_list arglist;

    va_start(arglist, format);

    (void)vprintf(format,arglist);

    va_end(arglist);	
}


#endif
