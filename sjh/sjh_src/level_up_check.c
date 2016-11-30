#include "level_up_check.h"
#include "variable.h"

void level_up_check(void)
{
 	int temp = delete_line%3;
 	if(delete_line != 0 || temp==0)
 	{
 		countrange++;
	}
}

