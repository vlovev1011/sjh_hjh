libhjh.a : block_init.o drop.o refresh.o collision.o game_start.o move_block.o display_tetris.o line_clear.o init_tetris_table.o
	ar rv libhjh.a block_init.o drop.o refresh.o collision.o game_start.o move_block.o display_tetris.o line_clear.o init_tetris_table.o
block_init.o : block_init.c
	gcc -c block_init.c -I../hjh_header
drop.o : drop.c
	gcc -c drop.c -I../hjh_header
refresh.o : refresh.c
	gcc -c refresh.c -I../hjh_header -L/../../sjh/sjh_src -lfuncs
collision.o : collision.c
	gcc -c collision.c -I../hjh_header
game_start.o : game_start.c
	gcc -c game_start.c -I../hjh_header -L/../../sjh/sjh_src -lfuncs
move_block.o : move_block.c
	gcc -c move_block.c -I../hjh_header
display_tetris.o : display_tetris.c
	gcc -c display_tetris.c -I../hjh_header
line_clear.o : line_clear.c
	gcc -c line_clear.c -I../hjh_header
init_tetris_table.o : init_tetris_table.c
	gcc -c init_tetris_table.c -I../hjh_header
clean :
	rm *.o libhjh.a
