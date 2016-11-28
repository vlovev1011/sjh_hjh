/*Global Variable*/
#pragma once

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
