libfuncs.a : init_tetris_table.o start_screen.o line_clear.o display_tetris.o
	ar rv libfuncs.a init_tetris_table.o start_screen.o line_clear.o display_tetris.o

start_screen.o : start_screen.c
	gcc -c start_screen.c -I../sjh_header

init_tetris_table.o : init_tetris_table.c
	gcc -c init_tetris_table.c -I../sjh_header -I../../hjh/hjh_header

line_clear.o : line_clear.c 
	gcc -c line_clear.c -I../sjh_header -I../../hjh/hjh_header

display_tetris.o : display_tetris.c
	gcc -c display_tetris.c -I../sjh_header -I../../hjh/hjh_header


clean :
	rm  *.o *.a










