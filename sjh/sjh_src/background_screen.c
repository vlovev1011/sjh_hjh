
void background_screen()
{
	char game_screen[22][28];

	for(int i=0; i<22; i++)
        {
                for(int z=0; z<28; z++)
                {
                        game_screen[i][z]=32;
                }
        }

	for(int i=0; i<22; i++)
	{
		game_screen[i][0]='*';
		game_screen[i][27]='*';
	}
	for(int i=0; i<28; i++)
	{
		game_screen[0][i]='*';
		game_screen[21][i]='*';
	}
	for(int i=0; i<22; i++)
	{
		for(int z=0; z<28; z++)
		{
			printf("%c",game_screen[i][z]);
		}
		printf("\n");
	}
}

