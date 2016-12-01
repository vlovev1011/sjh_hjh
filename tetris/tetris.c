#include "start_screen.h"
#include "init_tetris_table.h"
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
	init_tetris_table();

	GAME_START = start_screen();


	if(GAME_START==1)
	{
		display_tetris();
		line_clear();
	}
	if(GAME_START == 2)
	{
		return;
	}

}
