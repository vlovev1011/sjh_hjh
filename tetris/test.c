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

int display_tetris_table(void)
{

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

    return 0;
}

int game_start(void)
{

     static struct sigaction sa;
     static struct itimerval timer;
     time_t ptime;
     struct tm *t;
     FILE *fp = NULL;

     if(game == GAME_START)
     {
         init_tetris_table();

         memset(&sa, 0, sizeof (sa));
         sa.sa_handler = &refresh;
         sigaction(SIGVTALRM, &sa, NULL);

         timer.it_value.tv_sec = 0;
         timer.it_value.tv_usec = 1;
         timer.it_interval.tv_sec = 0;
         timer.it_interval.tv_usec = 1;

         setitimer(ITIMER_VIRTUAL, &timer, NULL);


         while(1)
         {

             if(game == GAME_END)
             {
                 timer.it_value.tv_sec = 0;

                 timer.it_value.tv_usec = 0;

                 timer.it_interval.tv_sec = 0;

                 timer.it_interval.tv_usec = 0;

                 setitimer(ITIMER_VIRTUAL,&timer,NULL);

                 printf("\n\n Total Score : %ld ", point);
                 printf("\n\n Input your name : ");
                 scanf("%s%*c", temp_result.name);
                 temp_result.point = point;

                 if(temp_result.point >= best_point)

                     best_point = temp_result.point;
                 ptime = time(NULL);

                 t = localtime(&ptime);
                 temp_result.year = t->tm_year + 1900;
                 temp_result.month = t->tm_mon + 1;
                 temp_result.day = t->tm_mday;
                 temp_result.hour = t->tm_hour;
                 temp_result.min = t->tm_min;
                 fp = fopen("result", "ab");
                 fseek(fp, 1, SEEK_END);
                 fwrite(&temp_result, sizeof(struct result), 1, fp);
                 fclose(fp);
                 x = 3, y =0;
                 point = 0;
                 return 1;
             }

         }

     }
   return 0;

 }

int collision_test(int command)
{
     int i, j;
     int tempx, tempy;
     int oldx, oldy;
     int temp_block_state;
     char (*block_pointer)[4][4][4];
     char temp_tetris_table[21][10];
     oldx = tempx = x;
     oldy = tempy = y;
     temp_block_state = block_state;
     switch(command)
     {
         case    LEFT :    tempx--;
                                     break;
         case    RIGHT :    tempx++;
                                     break;
         case    DOWN :    tempy++;
                                     break;
         case ROTATE : temp_block_state++;
			temp_block_state %=  4;
                                     break;
     }
     switch(block_number)
     {
         case I_BLOCK :    block_pointer = &i_block;
                                         break;
         case T_BLOCK :    block_pointer = &t_block;
                                         break;
         case S_BLOCK :    block_pointer = &s_block;
                                         break;
         case Z_BLOCK :    block_pointer = &z_block;
                                         break;
         case L_BLOCK :     block_pointer = &l_block;
                                         break;
         case J_BLOCK :     block_pointer = &j_block;
                                         break;
         case O_BLOCK :    block_pointer = &o_block;
                                         break;
     }
     for(i = 0 ; i < 21 ; i++)
     {
         for(j = 0 ; j < 10 ; j++)
         {
             temp_tetris_table[i][j] = tetris_table[i][j];
        }
     }
     for(i = 0, oldy = y ; i < 4 ; i++, oldy++)
     {
         for(j = 0, oldx = x ; j < 4 ; j++, oldx++)
         {
             if(oldx > 0 && oldx < 9 && oldy < 20 && oldy > 0)
              {
                if((*block_pointer)[block_state][i][j] == 1)
                         temp_tetris_table[oldy][oldx] = 0;
             }
         }
     }
      for(i = 0 ; i < 4 ; i++)
      {
         for(j = 0 ; j < 4 ; j++)
         {
              if(temp_tetris_table[tempy+i][tempx+j] == 1 && (*block_pointer)[temp_block_state][i][j] == 1)
                     return 1;
         }
       }
   	 return 0;
}

int check_one_line(void)
{
     int i, j;
     int ti, tj;
     int line_hole;
     for(i = 19 ; i > 0 ; i--)
     {
         line_hole = 0;
         for(j = 1 ; j < 9 ; j++)
         {
             if(tetris_table[i][j] == 0)
             {
                 line_hole = 1;
             }
         }
         if(line_hole == 0)
         {
             point += 1000;
             for(ti = i ; ti > 0 ; ti--)
             {
                 for(tj = 0 ; tj < 9 ; tj++)
                 {
                     tetris_table[ti][tj] = tetris_table[ti-1][tj];
                 }
             }
         }
     }
     return 0;
}
