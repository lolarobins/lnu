// lola's not unix (LNU)
// shared header for utils
// Copyright (C) 2024 lolasnotunix

#ifndef __LNU_SYS_UTILS_COMMON
#define __LNU_SYS_UTILS_COMMON

#ifdef __cplusplus
extern "C"
{
#endif

// macros needed for debug/output
#if !(defined _UTIL_NAME && defined _UTIL_VERS)
#error Utility debug fields must be placed preceeding common.h include
#endif

#define _VERSION_INFO \
    _UTIL_NAME " " _UTIL_VERS  \
    "\nlnu sys-utils <https://lnu.lola.sh/>" \
    "\nMIT License - Copyright (C) lolanotunix\n"

#define _ERR_NO_OPERAND "%s: no operand [help: -h]\n"
#define _ERR_NO_PATH "%s: no path specified [help: -h]\n"
#define _ERR_UNKNOWN_OPT "%s: option %c is unknown [help: -h]\n"
#define _ERR_ARG_OPT "%s: option %c requires an argument [help: -h]\n"
#define _ERR_TOO_MANY_OPERANDS "%s: too many operands provided [help: -h]\n"
#define _ERR_CALL_FAIL "error calling %s(): %s\n"


#ifdef __cplusplus
}
#endif

#endif
