#include "var.h"
#include "display_tetris.h"



void display_tetris(void)
{
	char tetris_block_table[21][10];

	for(int i=0; i<21; i++)
        {
                for(int j=0; j<10; j++)
                {
                        tetris_block_table[i][j]=tetris_table[i][j];
                }
                printf("\n");
        }



	for(int i=1; i<20; i++)
	{
		for(int j=1; j<9; j++)
		{
			tetris_block_table[i][j]='#';
			printf("%c",tetris_block_table[i][j]);
		}
		printf("\n");
	}

        for(int i=0; i<21; i++)
        {
                for(int j=0; j<10; j++)
                {
                        printf("%c",tetris_block_table[i][j]);
                }
                printf("\n");
        }

}
