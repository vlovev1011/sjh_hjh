#pragma once


char i_block[4][4][4];
 // ****
char t_block[4][4][4];
 // ***
 //  *
char s_block[4][4][4];
 // *
 // **
 //  *
char z_block[4][4][4];
 //  *
 // **
 // *
char l_block[4][4][4];
 // *
 // *
 // **
char j_block[4][4][4];
 //  *
 //  *
 // **
char o_block[4][4][4];
 // **
 // **

char tetris_table[21][10];
int x; // Block -> x
int y; // Block -> y
int block_state; // block rotate state
int block_number;
int next_block_number;
long point;
int countrange;
int delete_line;


