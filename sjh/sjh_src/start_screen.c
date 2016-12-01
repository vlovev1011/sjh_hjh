#include "start_screen.h"


int start_screen(void)
{
	system("clear");
        int menu;
        system("clear");
        printf("************Tetris*************\n");
        printf("\n\n\n\n\n");
        printf("***********************\n");
        printf("1. game_start\n");
        printf("2. game_end\n");
        printf("***********************\n");
        printf("select menu : ");
        scanf("%d",&menu);
        return menu;
}

