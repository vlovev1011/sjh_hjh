#include <stdio.h>
   #include <stdlib.h>
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
  #define ROTATE 3
  #define I_BLOCK 0
  #define    T_BLOCK 1
  #define S_BLOCK 2
  #define Z_BLOCK 3
  #define L_BLOCK 4
  #define J_BLOCK 5
  #define O_BLOCK 6
  #define GAME_START 0
  #define GAME_END 1
  char i_block[4][4][4] =
      {
              1, 1, 1, 1,    0, 0, 0, 0,    0, 0, 0, 0,    0,0,0,0,
              0, 0, 0, 1,   0, 0, 0, 1,    0, 0, 0, 1,    0,0,0,1,
              0, 0, 0, 0,    0, 0, 0, 0,   0, 0, 0, 0,   1, 1, 1, 1,
              1, 0, 0, 0,   1, 0, 0, 0,    1, 0, 0, 0,    1,0,0,0
      };
  char t_block[4][4][4] =
      {
              1, 0, 0, 0,   1, 1, 0, 0,    1, 0, 0, 0,   0, 0, 0, 0,
              1, 1, 1, 0,   0, 1, 0, 0,   0, 0, 0, 0,    0, 0, 0, 0,
              0, 0, 1, 0,   0, 1, 1, 0,   0, 0, 1, 0,   0, 0, 0, 0,
              0, 0, 0, 0,   0, 1, 0, 0,   1, 1, 1, 0,   0, 0, 0, 0
      };
  char s_block[4][4][4] =
      {
              1, 0, 0, 0,    1, 1, 0, 0,    0, 1, 0, 0,   0, 0, 0, 0,
              0, 1, 1, 0,    1, 1, 0, 0,    0, 0, 0, 0,   0, 0, 0, 0,
              0, 1, 0, 0,    0, 1, 1, 0,    0, 0, 1, 0,   0, 0, 0, 0,
              0, 0, 0, 0,   0, 1, 1, 0,    1, 1, 0, 0,    0, 0, 0, 0
      };
  char z_block[4][4][4] =
      {
              0, 1, 0, 0,    1, 1, 0, 0,   1, 0, 0, 0,    0, 0,0, 0,
              1, 1, 0, 0,    0, 1, 1, 0,   0, 0, 0, 0,    0, 0, 0, 0,
              0, 0, 1, 0,    0, 1, 1, 0,   0, 1, 0, 0,    0, 0, 0, 0,
              0, 0, 0, 0,    1, 1, 0, 0,    0, 1, 1, 0,   0, 0, 0, 0
      };
  char l_block[4][4][4] =
      {
              1, 0, 0, 0,    1, 0, 0, 0,    1, 1, 0, 0,   0, 0, 0, 0,
              1, 1, 1, 0,    1, 0, 0, 0,    0, 0, 0, 0,    0, 0, 0, 0,
              0, 1, 1, 0,    0, 0, 1, 0,    0, 0, 1, 0,    0, 0, 0, 0,
              0, 0, 0, 0,    0, 0, 1, 0,    1, 1, 1, 0,    0, 0, 0, 0
      };
  char j_block[4][4][4] =
      {
              0, 1, 0, 0,    0, 1, 0, 0,    1, 1, 0, 0,     0, 0, 0, 0,
              1, 0, 0, 0,    1, 1, 1, 0,    0, 0, 0, 0,    0, 0, 0, 0,
              1, 1, 0, 0,    1, 0, 0, 0,    1, 0, 0, 0,    0, 0, 0, 0,
              1, 1, 1, 0,    0, 0, 1, 0,    0, 0, 0, 0,    0, 0, 0, 0
      };
  char o_block[4][4][4] =
      {
              1, 1, 0, 0,    1, 1, 0, 0,    0, 0, 0, 0,    0, 0, 0, 0,
              1, 1, 0, 0,    1, 1, 0, 0,    0, 0, 0, 0,    0, 0, 0, 0,
             1, 1, 0, 0,    1, 1, 0, 0,    0, 0, 0, 0,    0, 0, 0, 0,
             1, 1, 0, 0,    1, 1, 0, 0,    0, 0, 0, 0,    0, 0, 0, 0,
     };
 char tetris_table[21][10];
 static struct result
 {
     char name[30];
     long point;
     int year;
     int month;
    int day;
     int hour;
     int min;
     int rank;
}temp_result;

 int block_number = 0;
 int next_block_number = 0;
 int block_state = 0;
 int x = 3, y = 0;
 int game = GAME_END;
 int best_point = 0;
 long point = 0;

 int check_one_line(void);
 int display_menu(void);
 int init_tetris_table(void);
 int display_tetris_table(void);


 int game_start(void);
 int refresh(int);
 int move_block(int);
 int drop(void);
 int collision_test(int);

 int print_result(void);
 int search_result(void);
 int getch(void);

int main(void)
 { 
     int menu = 1;
  
     while(menu) 
     { 
         menu = display_menu(); 
  
         if(menu == 1) 
         { 
             game = GAME_START; 
             menu = game_start(); 
         } 
         else if(menu == 2) 
         { 
             search_result(); 
         } 
         else if(menu == 3) 
         { 
            print_result(); 
         } 
        else if(menu == 4) 
        { 
             exit(0); 
         } 
     } 
  
     return 0;
 } 

int init_tetris_table(void)
 { 
     int i = 0, j = 0;
  
     for(i = 0 ; i < 20 ; i++)
         for(j = 1 ; j < 9 ; j++)
             tetris_table[i][j] = 0; 
  
     for(i = 0 ; i < 21 ; i++)
     { 
         tetris_table[i][0] = 1; 
         tetris_table[i][9] = 1; 
     } 
  
     for(j = 1 ; j < 9 ; j++)
         tetris_table[20][j]= 1; 
  
     return 0;
 } 