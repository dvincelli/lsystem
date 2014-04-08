#include <stdio.h>
#include <math.h>
#include "SDL2/SDL.h"
#include "turtle.h"

int startx;
int starty;
int turtlex;
int turtley;
int turtleAngle;

SDL_Renderer *renderer = NULL;
SDL_Window *win = NULL;

void handle_exit();

void setPoint(int x, int y)
{
	startx = x;
	starty = y;
}

void drawLine(int x, int y)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
	SDL_RenderDrawLine(renderer, startx, starty, x, y);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderPresent(renderer);
	setPoint(x, y);
	handle_exit();
}

void forward(int step)
{
	double xstep;
	double ystep;

	xstep = step * cos((turtleAngle * M_PI)/180);
	ystep = step * sin((turtleAngle * M_PI)/180);

	turtlex = turtlex + (int) xstep;
	turtley = turtley + (int) ystep;

	drawLine(turtlex, turtley);
}

void backward(int step)
{
	forward(-step);
}

void turn(int alpha)
{
	turtleAngle = (turtleAngle + alpha) % 360;
}

void startTurtle()
{
	int posX = 100, posY = 100, width = 1024, height = 768;
	win = SDL_CreateWindow("Turtle", posX, posY, width, height, 0);
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderClear(renderer);

	turtleAngle = 90;
	turtlex = 1024/2;
	turtley = 768/2;
	setPoint(turtlex, turtley);
}

void handle_exit()
{
	SDL_Event e;
	if (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(win);
			exit(0);
		}
	}
}

