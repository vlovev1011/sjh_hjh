#pragma once

#include <stdio.h>

int start_screen()
{
        int speed;
        printf("************Tetris*************\n");
        printf("Speed Level (1~10) : ");
        scanf("%d\n",&speed);
        return speed;
}


