clean:
	rm *.o turtle

turtle.o: turtle.c
	gcc -Wall -lc -lm `sdl-config --cflags` turtle.c -o turtle

turtle: turtle.o
	ld -dynamic-linker `sdl-config --libs` -lc -lm -lSDL_gfx turtle.o -o turtle
