/*Header*/
#include <stdio.h>
#include <stdlib.h> // system("clear") , srand
#include <termios.h> // tcgetattr()
#include <unistd.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <time.h>
#include <signal.h>
#include <string.h>


#include "getch.h"

/*Macro*/
#define CCHAR 0

#define LEFT 0
#define RIGHT 1
#define DOWN 2
#define UP 3

#define I_BLOCK 0
#define T_BLOCK 1
#define S_BLOCK 2
#define Z_BLOCK 3
#define L_BLOCK 4
#define J_BLOCK 5
#define O_BLOCK 6

/*Function*/
int Key_input(void);
int Block_move(int command);
void Start_block(void);
void Block_rotate();
int getch(void);
int Game_start(void);

/*Global Variable*/
char i_block[4][4][4] = 

{ 

	1, 1, 1, 1,    0, 0, 0, 0,    0, 0, 0, 0,    0,0,0,0, 

	0, 0, 0, 1,   0, 0, 0, 1,    0, 0, 0, 1,    0,0,0,1, 

	0, 0, 0, 0,    0, 0, 0, 0,   0, 0, 0, 0,   1, 1, 1, 1,

	1, 0, 0, 0,   1, 0, 0, 0,    1, 0, 0, 0,    1,0,0,0 

}; // ****

   

char t_block[4][4][4] = 

{ 

	1, 0, 0, 0,   1, 1, 0, 0,    1, 0, 0, 0,   0, 0, 0, 0,

	1, 1, 1, 0,   0, 1, 0, 0,   0, 0, 0, 0,    0, 0, 0, 0,

	0, 0, 1, 0,   0, 1, 1, 0,   0, 0, 1, 0,   0, 0, 0, 0,

	0, 0, 0, 0,   0, 1, 0, 0,   1, 1, 1, 0,   0, 0, 0, 0

}; // ***  
   //  *
   

char s_block[4][4][4] = 

{ 

	1, 0, 0, 0,    1, 1, 0, 0,    0, 1, 0, 0,   0, 0, 0, 0,

	0, 1, 1, 0,    1, 1, 0, 0,    0, 0, 0, 0,   0, 0, 0, 0,

	0, 1, 0, 0,    0, 1, 1, 0,    0, 0, 1, 0,   0, 0, 0, 0,

	0, 0, 0, 0,   0, 1, 1, 0,    1, 1, 0, 0,    0, 0, 0, 0

}; // *
   // **
   //  *

char z_block[4][4][4] = 

{ 

	0, 1, 0, 0,    1, 1, 0, 0,   1, 0, 0, 0,    0, 0,0, 0, 

	1, 1, 0, 0,    0, 1, 1, 0,   0, 0, 0, 0,    0, 0, 0, 0,

	0, 0, 1, 0,    0, 1, 1, 0,   0, 1, 0, 0,    0, 0, 0, 0,

	0, 0, 0, 0,    1, 1, 0, 0,    0, 1, 1, 0,   0, 0, 0, 0

}; //  *
   // ** 
   // *

char l_block[4][4][4] = 

{ 

	1, 0, 0, 0,    1, 0, 0, 0,    1, 1, 0, 0,   0, 0, 0, 0,

	1, 1, 1, 0,    1, 0, 0, 0,    0, 0, 0, 0,    0, 0, 0, 0,

	0, 1, 1, 0,    0, 0, 1, 0,    0, 0, 1, 0,    0, 0, 0, 0,

	0, 0, 0, 0,    0, 0, 1, 0,    1, 1, 1, 0,    0, 0, 0, 0

}; // *
   // *
   // **

char j_block[4][4][4] = 

{ 

	0, 1, 0, 0,    0, 1, 0, 0,    1, 1, 0, 0,     0, 0, 0, 0,

	1, 0, 0, 0,    1, 1, 1, 0,    0, 0, 0, 0,    0, 0, 0, 0,

	1, 1, 0, 0,    1, 0, 0, 0,    1, 0, 0, 0,    0, 0, 0, 0,

	1, 1, 1, 0,    0, 0, 1, 0,    0, 0, 0, 0,    0, 0, 0, 0

}; //  *
   //  *
   // **

char o_block[4][4][4] = 

{ 

	1, 1, 0, 0,    1, 1, 0, 0,    0, 0, 0, 0,    0, 0, 0, 0,

	1, 1, 0, 0,    1, 1, 0, 0,    0, 0, 0, 0,    0, 0, 0, 0,

	1, 1, 0, 0,    1, 1, 0, 0,    0, 0, 0, 0,    0, 0, 0, 0,

	1, 1, 0, 0,    1, 1, 0, 0,    0, 0, 0, 0,    0, 0, 0, 0,

}; // ** 
   // **
int x = 3; // Block -> x
int y = 0; // Block -> y
int block_state; // block rotate state
int block_num;

int main()
{
	char key;
	int state=0;
	Start_block();
	
	
	while(1)
	{
		Game_start();
	}
	return 0;
}

int Game_start(void)
{
	static struct sigaction sa;
	static struct itimerval timer;
	time_t ptime;
	struct tm *t;

	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &refresh;
	sigaction(SIGVTALRM,&sa,NULL);

	timer.it_value.tv_sec=0;
	timer.it_value.tv_usec = 1;

	timer.ti_interval.tv_sec=0;
	timer.it_interval.tv_usec = 1;

	setitimer(ITIMER_VIRTUAL, &timer, NULL);

	
}

int refresh(int signum)
{
	static int downcount = 0;
	static int setcount =0;
	static long speedcount = 0;
	static int countrange = 5;
	static int firststart = 0;

	srand((unsigned)time(NULL));

	if(firststart == 0)
	{
		block_num = rand()%7;
		firststart++;
	}

	key_input();
	
	

	
}

int Key_input()
{
	char key;

	key = getch();
	
	switch(key)
	{
		case 74 :
		case 106 : Block_move(LEFT);
				break;
		case 76 :
		case 108 : Block_move(RIGHT);
				break;
		case 75 :
		case 107 : Block_move(DOWN);
				break;
		case 73 :
		case 105 : Block_move(UP);
				break;
		case 65 :
		case 97 : drop();
				break;

		default : break;
	}
	return 0;
}

int Block_move(int command)
{
	int newx = x;
	int newy = y;
	

	switch(command)
	{
		case LEFT : newx--;
			break;
		case RIGHT : newx++;
			break;
		case DOWN : newy++;
			break;
		case UP : block_state = ++block_state%4;
			break;
	}
	return 0;
}

void Start_block(void)
{
	for(int j=0;j<4;j++)
	{
		for(int i=0;i<4;i++)
		{
			if(i_block[0][i][j] == 1)
			{
				printf("%c",'#');
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("\n");
	return;
	
}

void Block_rotate()
{

	system("clear");

	for(int j=0;j<4;j++)
	{
		for(int i=0;i<4;i++)
		{
			if(i_block[block_state][i][j] == 1)
			{
				printf("%c",'#');
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("\n");
	return;
}

























