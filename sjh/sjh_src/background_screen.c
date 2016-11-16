#include "background_screen.h"
#include "var.h"

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

