#include "source.h"
#include "variable.h"
#include "getch.h"

int refresh(int signum)
{
	static int downcount=0;
	static int setcount=0;
	static long speedcount=0;
	//static int countrange=5;
	static int firststart=0;

	char ch;

	srand((unsigned)time(NULL));
	countrange=5;
	if(firststart == 0)
	{
		block_number=rand()%7;
		if(firststart == 0)
			firststart++;
	}

	if(downcount == countrange-1)
	{
		point+=1;
		move_blcok(DOWN);
	}

	if(speedcount == 499)
	{
		if(countrange != 1)
			countrange--;
	}

	downcount++;
	downcount %= countrange;
	speedcount++;
	speedcount %= 500;

	if(x==3 && y==0)
	{
		if(collision(LEFT) || collision(RIGHT) || collision(DOWN) || collision(UP))
		{
			printf("\n Game End !! \n");
			downcount=0;
			setcount=0;
			speedcount=0;
			countrange=5;
			firststart=0;
		}
	}
	if(collision(DOWN))
	{
		if(setcount == 9)
		{
			block_number = next_block_number;
			next_block_number = rand()%7;
			block_state=0;
			x=3;
			y=0;
		}
		setcount++;
		setcount%=10;
	}
	ch = getch();

	switch(ch)
	{
		case 74:
		case 106 : move_block(LEFT); break;
                case 76:
                case 108 : move_block(RIGHT); break;
                case 75:
                case 107 : move_block(DOWN); break;
                case 73:
                case 105 : move_block(UP); break;
                case 65:
                case 97 : drop(); break;
                case 80:
                case 112 : downcount=0;
				setcount=0;
				speedcount=0;
				countrange=5;
				firststart=0;
				break;
		default : break;

	}
	return 0;
}

