#include "background_screen.h"

void background_screen(int speed, int delete_line)
{

	char game_screen[21][10];

	for(int i=0; i<21; i++)
	{
		for(int j=0; j<10; j++)
		{
			game_screen[i][j]=' ';
		}
	}

	for(int i=0; i<21; i++)
	{
		game_screen[i][0]='@';
		game_screen[i][9]='@';
	}
	for(int i=0; i<10; i++)
	{
		game_screen[20][i]='@';
	}
	system("clear");

	printf("current level : %d\n",speed);
	printf("delete_line : %d\n",delete_line);

	for(int i=0; i<21; i++)
	{
		for(int z=0; z<10; z++)
		{
			printf("%c",game_screen[i][z]);
		}
		printf("\n");
	}
}

