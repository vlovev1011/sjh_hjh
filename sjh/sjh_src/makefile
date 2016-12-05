libfuncs.so libfuncs.so.1 : libfuncs.so.1.0
	ln -s libfuncs.so.1.0 libfuncs.so
	ln -s libfuncs.so.1.0 libfuncs.so.1
libfuncs.so.1.0 : start_screen.o init_tetris_table.o line_clear.o display_tetris.o
	ld -shared -soname=libfuncs.so.1 *.o -o libfuncs.so.1.0 -lc

start_screen.o : start_screen.c
	gcc -fPIC -c start_screen.c -I../sjh_header

init_tetris_table.o : init_tetris_table.c
	gcc -fPIC -c init_tetris_table.c -I../sjh_header -I../../hjh/hjh_header

line_clear.o : line_clear.c
	gcc -fPIC -c line_clear.c -I../sjh_header -I../../hjh/hjh_header

display_tetris.o : display_tetris.c
	gcc -fPIC -c display_tetris.c -I../sjh_header -I../../hjh/hjh_header


clean :
	rm  *.o *.a *.so
