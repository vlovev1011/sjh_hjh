#include "variable.h"

void init_tetris_table(void)
{
        int i = 0, j = 0;
        for(i = 0 ; i < 20 ; i++)
        {
                for(j = 1 ; j < 9 ; j++)
                {
                        tetris_table[i][j] = 0;
                }
        }
        for(i = 0 ; i < 21 ; i++)
        {
                tetris_table[i][0] = 1;
                tetris_table[i][9] = 1;
        }
        for(j = 1 ; j < 9 ; j++)
        {
                tetris_table[20][j]= 1;
        }
}

