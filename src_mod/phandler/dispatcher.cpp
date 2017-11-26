#include "dispatcher.hpp"

#ifdef __cplusplus
extern "C" {
#endif

#include <qcommon_io.h>
#include <cmd.h>
#include <server.h>

#ifdef __cplusplus
}
#endif

#define VARG(num, type) ((type)(((int*)&Code_)[1 + num]))

void SV_GetStat(int clientNum, signed int index, int *ret);

void SysCallDispatcher(const EAPICode Code_, ...)
{
    switch(Code_)
    {
        case AC_Com_Printf:
            Com_Printf(VARG(0, const char*));
            break;
        case AC_Com_Error:
			Com_Error(0, VARG(0, const char*));
			break;
        case AC_Com_PrintError:
			Com_PrintError(VARG(0, const char*));
			break;
        case AC_Com_DPrintf:
		    Com_DPrintf(VARG(0, const char*));
		    break;
        case AC_Com_PrintWarning:
			Com_PrintWarning(VARG(0, const char*));
			break;
        case AC_Cbuf_AddText:
            Cbuf_AddText(VARG(0, const char*));
            break;
        case AC_SV_SetConfigString:
            SV_SetConfigstring(VARG(0, int), VARG(1, const char*));
            break;
        case AC_SV_GetConfigString:
            SV_GetConfigstring(VARG(0, int), VARG(1, char*), VARG(2, int));
            break;
        case AC_SV_GetStat:
            SV_GetStat(VARG(0, int), VARG(1, int), VARG(2, int*));
            break;
        case AC_SV_SetStat:
            SV_SetClientStat(VARG(0, int), VARG(1, int), VARG(2, int));
            break;
			default: 
            Com_Error(0, "Unknown system call index: %d", Code_);
    }
}

void SV_GetStat(int clientNum, signed int index, int *ret)
{
    *ret = SV_GetClientStat(clientNum, index);
}