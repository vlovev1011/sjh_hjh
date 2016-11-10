#include <stdio.h>

void main()
{
	char game_screen[20][14];

	for(int i=0; i<20; i++)
        {
                for(int z=0; z<14; z++)
                {
                        game_screen[i][z]=32;
			//tan - 9
                }
                printf("\n");
        }

	for(int i=1; i<20; i++)
	{
		game_screen[i][0]='|';
		game_screen[i][13]='|';
	}
	for(int i=0; i<14; i++)
	{
		game_screen[0][i]='-';
		game_screen[19][i]='-';
	}
	for(int i=0; i<20; i++)
	{
		for(int z=0; z<14; z++)
		{
			printf("%c",game_screen[i][z]);
		}
		printf("\n");
	}
}

