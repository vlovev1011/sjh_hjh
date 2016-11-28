#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/time.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <time.h>

#include "variable.h"

#define CCHAR 0
#ifdef CTIME
#undef CTIME
#endif
#define CTIME 1


