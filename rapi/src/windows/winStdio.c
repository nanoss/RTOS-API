

#include "rapi/rapi_config.h"


#if OSAPI_PLATFORM ==  OSAPI_PLATFORM_WINDOWS

#include <stdio.h>
#include <stdarg.h>

#include "rapi/rapi_types.h"
#include "rapi/rapi_stdio.h"

void RAPI_Stdio_printf(const char *format,...)
{
    va_list arglist;

    va_start(arglist, format);

    (void)vprintf_s(format,arglist);

    va_end(arglist);
}

#endif
