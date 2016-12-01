#include "start_screen.h"
#include "background_screen.h"
#include "level_up_check.h"
#include "line_clear.h"
#include "display_tetris.h"
#include "variable.h"

int countrange;
int delete_line;
char tetris_table[21][10];

void main()
{
	int GAME_START;

	delete_line=0;
	countrange=5;
	GAME_START = start_screen();


	while(GAME_START==1)
	{
		background_screen();
		display_tetris();
		line_clear();
		level_up_check();
	}
	if(GAME_START == 2)
	{
		return;
	}

}
