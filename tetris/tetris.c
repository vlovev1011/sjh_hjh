#include "start_screen.h"
#include "background_screen.h"
#include "level_up_check.h"
#include "line_clear.h"
#include "display_tetris.h"
#include "variable.h"

void main()
{
	//int( * tetris_table)[21][10];
	static int speed;
	static int delete_line=0;
	speed = start_screen();




	background_screen(speed,delete_line);
	display_tetris();
	delete_line = line_clear();
	speed=level_up_check(speed,delete_line);
	
}
