#include "var.h"
#include "display_tetris.h"

void display_tetris(void)
{
	//system("clear");
	for(int i=0; i<21; i++)
	{
		for(int j=0; j<10; j++)
		{
			//tetris_table[i][j]='#';
			printf("%c",tetris_table[i][j]);
		}
		printf("\n");
	}
}
