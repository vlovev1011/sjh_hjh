#pragma once

#include <stdio.h>
#include <stdlib.h>

int start_screen()
{
	system("clear");
        int speed;
        printf("************Tetris*************\n");
        printf("Speed Level (1~10) : ");
        scanf("%d",&speed);
        return speed;
}


