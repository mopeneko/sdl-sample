build: main

main: main.c
	$(CC) $^ -o $@ `sdl2-config --cflags --libs`
