libhjh.a : block_init.o drop.o refresh.o collision.o game_start.o move_block.o
	ar rv libhjh.a block_init.o drop.o refresh.o collision.o game_start.o move_block.o
block_init.o : block_init.c
	gcc -c block_init.c -I../hjh_header
drop.o : drop.c
	gcc -c drop.c -I../hjh_header
refresh.o : refresh.c
	gcc -c refresh.c -I../hjh_header -I/home/shinjaeho/sjh/sjh_hjh/sjh/sjh_header
collision.o : collision.c
	gcc -c collision.c -I../hjh_header
game_start.o : game_start.c
	gcc -c game_start.c -I../hjh_header -I/home/shinjaeho/sjh/sjh_hjh/sjh/sjh_header
move_block.o : move_block.c
	gcc -c move_block.c -I../hjh_header

clean :
	rm *.o libhjh.a
