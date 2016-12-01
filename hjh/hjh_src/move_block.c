#include "source.h"
#include "variable.h"

int move_block(int command)
{
	int i,j;
	int newx,newy;
	int oldx,oldy;
	int old_block_state;
	char (*block_pointer)[4][4][4]=NULL;

	newx=x;
	newy=y;

	old_block_state=block_state;

	if(collision(command) == 0)
	{
		switch(command)
		{
			case LEFT : newx--; break;
			case RIGHT : newx++; break;
			case DOWN : newy++; break;
			case UP : ++block_state%4; break;
		}
	}
	else
	{
		return 1;
	}

	switch(block_number)
	{
		case I_BLOCK : block_pointer = &i_block; break;
                case T_BLOCK : block_pointer = &t_block; break;
                case S_BLOCK : block_pointer = &s_block; break;
                case Z_BLOCK : block_pointer = &z_block; break;
                case L_BLOCK : block_pointer = &l_block; break;
                case J_BLOCK : block_pointer = &j_block; break;
                case O_BLOCK : block_pointer = &o_block; break;
	}

	for(i=0,oldy=y;i<4;i++,oldy++)
	{
		for(j=0,oldx=x;j<4;j++,oldx++)
		{
			if(oldx>0 && oldx<9 && oldy<20 && oldy>0)
			{
				if((*block_pointer)[old_block_state][i][j] == 1)
					tetris_table[oldy][oldx] = 0;
			}
		}
	}

	x=newx;
	y=newy;

	for(i=0,newy=y;i<4;i++,newy++)
	{
		for(j=0,newx=x;j<4;j++,newx++)
		{
			if(newx>0 && newx<9 && newy<20 && newy>0)
			{
				if((*block_pointer)[block_state][i][j] == 1)
					tetris_table[newy][newx] = (*block_pointer)[block_state][i][j];
			}
		}
	}

	return 0;
}
