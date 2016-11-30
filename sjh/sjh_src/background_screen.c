#include "background_screen.h"
#include "variable.h"




void background_screen(void)
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


 	printf("current level : %d\n",countrange);
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

