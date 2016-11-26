#include "background_screen.h"
#include "variable.h"

char i_block[4][4][4];
char t_block[4][4][4];
char s_block[4][4][4];
char z_block[4][4][4];
char l_block[4][4][4];
char j_block[4][4][4];

extern int x; // Block -> x
extern int y; // Block -> y
extern int block_state; // block rotate state
extern int block_number;
extern int next_block_number;
extern long point;



char tetris_table[21][10];


void background_screen(int speed, int delete_line)
{
 	for(int i=0; i<21; i++)
 	{
 		for(int j=0; j<10; j++)
 		{
 			tetris_table[i][j]=' ';
 		}
 	}


 	for(int i=0; i<21; i++)
 	{
 		tetris_table[i][0]='@';
 		tetris_table[i][9]='@';
 	}
 	for(int i=0; i<10; i++)
 	{
 		tetris_table[20][i]='@';
 	}
 	system("clear");


 	printf("current level : %d\n",speed);
 	printf("delete_line : %d\n",delete_line);


 	for(int i=0; i<21; i++)
 	{
 		for(int z=0; z<10; z++)
 		{
 			printf("%c",tetris_table[i][z]);
 		}
 		printf("\n");
 	}
 }

