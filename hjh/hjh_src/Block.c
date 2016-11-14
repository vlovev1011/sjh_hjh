/*Header*/
#include <stdio.h>
#include <stdlib.h> // system("clear")
#include <termios.h> // tcgetattr()
#include <unistd.h>

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
void Start_block(void);
void Block_rotate();
int getch(void);

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


int main()
{
	char key;
	int state=0;
	Start_block();
	
	
	while(1)
	{
		Key_input()
	}
	return 0;
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

























