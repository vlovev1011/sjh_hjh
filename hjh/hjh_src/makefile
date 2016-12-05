libhjh.so libhjh.so.1 : libhjh.so.1.0
	ln -s libhjh.so.1.0 libhjh.so
	ln -s libhjh.so.1.0 libhjh.so.1

libhjh.so.1.0 : block_init.o drop.o refresh.o collision.o game_start.o move_block.o
	ld -shared -soname=libhjh.so.1 *.o -o libhjh.so.1.0 -lc

block_init.o : block_init.c
	gcc -fPIC -c block_init.c -I../hjh_header
drop.o : drop.c
	gcc -fPIC -c drop.c -I../hjh_header
refresh.o : refresh.c
	gcc -fPIC -c refresh.c -I../hjh_header -L/../../sjh/sjh_src -lfuncs
collision.o : collision.c
	gcc -fPIC -c collision.c -I../hjh_header
game_start.o : game_start.c
	gcc -fPIC -c game_start.c -I../hjh_header -L/../../sjh/sjh_src -lfuncs
move_block.o : move_block.c
	gcc -fPIC -c move_block.c -I../hjh_header
clean :
	rm *.o  *.so

