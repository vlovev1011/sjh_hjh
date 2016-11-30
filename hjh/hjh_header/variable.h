/*Global Variable*/
#pragma once
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/time.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <time.h>

#define CCHAR 0
#ifdef CTIME
#undef CTIME
#endif
#define CTIME 1

#define LEFT 0
#define RIGHT 1
#define DOWN 2
#define UP 3

#define T_BLOCK 1
#define S_BLOCK 2
#define Z_BLOCK 3
#define L_BLOCK 4
#define J_BLOCK 5
#define O_BLOCK 6



extern char i_block[4][4][4];
 // ****
extern char t_block[4][4][4];
 // ***
 //  *
extern char s_block[4][4][4];
 // *
 // **
 //  *
extern char z_block[4][4][4];
 //  *
 // **
 // *
extern char l_block[4][4][4];
 // *
 // *
 // **
extern char j_block[4][4][4];
 //  *
 //  *
 // **
extern char o_block[4][4][4];
 // **
 // **

extern char tetris_table[21][10];
extern int x; // Block -> x
extern int y; // Block -> y
extern int block_state; // block rotate state
extern int block_number;
extern int next_block_number;
extern long point;

int refresh(int signum);
int collision(int command);
void block_init(void);
int game_start(void);
int move_block(int command);
int drop(void);
