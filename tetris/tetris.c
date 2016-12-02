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
	int menu;
	menu=start_screen();

	while(1)
	{
		if(menu == 1)
		{
			game = GAME_START;
			game_start();
		}
		else if(menu == 2)
		{
			exit(0);
		}
	}





}
