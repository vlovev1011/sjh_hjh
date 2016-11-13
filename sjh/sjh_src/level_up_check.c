#include "level_up_check.h"
int level_up_check(int speed, int delete_line)
{
	int temp = delete_line%3;
	int new_speed=speed;
	if(delete_line != 0 || temp==0)
	{
		new_speed=speed+1;
	}
	return new_speed;
}
