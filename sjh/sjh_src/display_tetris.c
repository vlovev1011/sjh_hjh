#include "display_tetris.h"
#include "variable.h"


void display_tetris(void)
{


	for(int i=0; i<20; i++)
        {
                for(int j=1; j<9; j++)
                {
                        tetris_table[i][j]='#';
                }
        }



        for(int i=0; i<21; i++)
        {
                for(int j=0; j<10; j++)
                {
                        printf("%c",tetris_table[i][j]);
                }
                printf("\n");
        }

}
