#include "variable.h"

int game_start(void)
{
	static struct sigaction sa;
	static struct itimerval timer;
	time_t ptime;
	struct tm *t;
	FILE *fp = NULL

	// init_tetris_table();

	memset(&sa,0,sizeof(sa));
	sa.sa_handler=&refresh;
	sigaction(SIGVTALRM, &sa, NULL);

	timer.it_value.tv_sec=0;
	timer.it_value.tv_usec=1;

	timer.it_value.tv_sec=0;
	timer.it_value.tv_usec=1;

	timer.it_interval.tv_sec=0;
	timer.it_interval.tv_usec=1;

	setitimer(ITIMER_VIRTUAL,&timer,NULL);

	return 0;
}
