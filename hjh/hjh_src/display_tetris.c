#include "variable.h"


void display_tetris(void)
{
        system("clear");
        int i, j;
        char (*block_pointer)[4][4][4] = NULL;

        switch(next_block_number)
        {
                case I_BLOCK :    block_pointer = &i_block;
                                         break;
                case T_BLOCK :    block_pointer = &t_block;
                                         break;
                case S_BLOCK :  block_pointer = &s_block;
                                         break;
                case Z_BLOCK :     block_pointer = &z_block;
                                        break;
                case L_BLOCK :     block_pointer = &l_block;
                                         break;
                case J_BLOCK :     block_pointer = &j_block;
                                         break;
                case O_BLOCK :    block_pointer = &o_block;
                                         break;
     }

     system("clear");
     printf("\n\n Next Block\n");

     for(i = 0 ; i < 4 ; i++)
     {
         printf("\n ");
         for(j = 0 ; j < 4 ; j++)
         {
             if((*block_pointer)[0][i][j] == 1)
                 printf("#");
           else if((*block_pointer)[0][i][j] == 0)
                 printf(" ");
        }
     }
     for(i = 2 ; i < 21 ; i++)
     {
        printf("\t");
        for(j = 0 ; j < 10 ; j++)
         {
             if(j == 0 || j == 9|| (i == 20 && (j > 1 || j < 9)))
            {
                printf("@");
            }
            else if(tetris_table[i][j] == 1)
                 printf("#");
             else if(tetris_table[i][j] == 0)
                 printf(" ");
         }
        printf("\n");
    }
}

