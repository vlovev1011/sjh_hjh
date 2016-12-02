#include "start_screen.h"
#include "init_tetris_table.h"
#include "line_clear.h"
#include "display_tetris.h"

#include "variable.h"
#include "getch.h"
#include "source.h"
#include "init_extern_variable.h"

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
