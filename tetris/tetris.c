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
	//int( * tetris_table)[21][10];
	//static int speed;
	delete_line=0;
	countrange=5;
        start_screen();




	background_screen();
	display_tetris();
	line_clear();
	level_up_check();
	
}
