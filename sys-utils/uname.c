// lola's not unix (LNU)
// uname v1.0.0
// Copyright (C) 2024 lolasnotunix

#define _UTIL_NAME "uname"
#define _UTIL_VERS "1.0.0"
#include "common.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

int main(int argc, char *argv[])
{
    struct utsname sys_info;
    uname(&sys_info);

    // flags: selected info to print (000mnrsv)
    char c, flags = 0;
    while ((c = getopt(argc, argv, "ahimnrsv")) != -1)
    {
        switch (c)
        {
        case 'a':
            flags |= 0x1F;
            break;

        case 'h':
            printf("%s [-ahimnrsv]\n"
                "get system information.\n"
                "  -a  show all values\n"
                "  -h  print help/usage\n"
                "  -i  print version info (substituted for posix)\n"
                "  -m  print machine platform\n"
                "  -n  print machine name\n"
                "  -r  print os release\n"
                "  -s  print os name\n"
                "  -v  print os version\n",
                argv[0]);
            return 0;

        case 'i':
            printf(_VERSION_INFO);
            return 0;

        case 'm':
            flags |= 0x10;
            break;

        case 'n':
            flags |= 0x8;
            break;

        case 'r':
            flags |= 0x4;
            break;

        case 's':
            flags |= 0x2;
            break;

        case 'v':
            flags |= 0x1;
            break;

        default:
            fprintf(stderr, _ERR_UNKNOWN_OPT, argv[0], optopt);
            return 1;
        }
    }

    if (!flags)
        flags |= 0x2; // s is default in posix

    printf("%s%c%s%c%s%c%s%c%s\n",
        flags & 0x2 ? sys_info.sysname : "", flags & 0x2 ? ' ' : 0, // s
        flags & 0x8 ? sys_info.nodename : "", flags & 0x8 ? ' ' : 0, // n
        flags & 0x4 ? sys_info.release : "", flags & 0x4 ? ' ' : 0, // r
        flags & 0x1 ? sys_info.version : "", flags & 0x1 ? ' ' : 0, // v
        flags & 0x10 ? sys_info.machine : ""); // m

    return 0;
}