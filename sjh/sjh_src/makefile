libfuncs.a : background_screen.o line_clear.o level_up_check.o display_tetris.o
	ar rv libfuncs.a background_screen.o line_clear.o level_up_check.o display_tetris.o

background_screen.o : background_screen.c 
	gcc -c background_screen.c -I../sjh_header -I/home/shinjaeho/sjh/sjh_hjh/hjh/hjh_header

line_clear.o : line_clear.c 
	gcc -c line_clear.c -I../sjh_header -I/home/shinjaeho/sjh/sjh_hjh/hjh/hjh_header

level_up_check.o : level_up_check.c 
	gcc -c level_up_check.c -I../sjh_header -I/home/shinjaeho/sjh/sjh_hjh/hjh/hjh_header

display_tetris.o : display_tetris.c
	gcc -c display_tetris.c -I../sjh_header -I/home/shinjaeho/sjh/sjh_hjh/hjh/hjh_header


clean :
	rm  *.o *.a










