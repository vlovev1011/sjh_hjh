#include "start_screen.h"
#include "background_screen.h"
#include "level_up_check.h"
#include "line_clear.h"


void main()
{
	static int speed;
	static int delete_line;
	delete_line=line_clear();

	speed=level_up_check(start_screen(),delete_line);
	background_screen(speed,delete_lien);
}
