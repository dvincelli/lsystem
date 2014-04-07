#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "SDL.h"
#include "SDL_gfxPrimitives.h"

int WINDOW_WIDTH = 640;
int WINDOW_HEIGHT = 480;
char* WINDOW_TITLE = "SDL Start";

int oldx;
int oldy;
int turtlex;
int turtley;
int turtleAngle;

SDL_Surface *screen = NULL;
/*
void setPoint(int x, int y)
{
}

void drawLine(int x, int y)
{
     lineRGBA(screen, 
               oldx, oldy,
               turtlex, turtley, 
               255, 0, 0, 255);

	oldx = turtlex;
	oldy = turtley;
}

void forward(int step)
{
	double xstep;
	double ystep;
	int oldx, oldy;

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
	turtleAngle = 90;
	turtlex = 0;
	turtley = 0;
	oldx = turtlex;
	oldy = turtley;
	setPoint(oldx, oldy);
}
*/

int main(int argc, char **argv)
{
   SDL_Init( SDL_INIT_VIDEO );

   screen = SDL_SetVideoMode( WINDOW_WIDTH, WINDOW_HEIGHT, 0, 
      SDL_HWSURFACE | SDL_DOUBLEBUF );
   SDL_WM_SetCaption( WINDOW_TITLE, 0 );

   SDL_Event event;
   int gameRunning = 1;

   while (gameRunning)
   {
      if (SDL_PollEvent(&event))
      {
         if (event.type == SDL_QUIT)
         {
            gameRunning = 0;
         }
      }

      SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

      pixelRGBA(screen, 
                10, 15, 
                255, 255, 255, 255);

      lineRGBA(screen, 
               20, 10,
               70, 90, 
               255, 0, 0, 255);

      trigonRGBA(screen,
                 500, 50,
                 550, 200, 
                 600, 150, 
                 0, 255, 255, 255);

      filledTrigonRGBA(screen,
                       200, 200,
                       300, 50,    
                       400, 200, 
                       0, 0, 255, 255);

      rectangleRGBA(screen, 
                    -10, 300, 
                    100, 380,
                    0, 255, 0, 255);

      boxRGBA(screen, 
              210, 76, 
              325, 300,
              255, 0, 0, 150);

      ellipseRGBA(screen,
                  600, 400,
                  50, 90,
                  255, 255, 0, 200);

      filledEllipseRGBA(screen,
                        600, 400,
                        25, 150,
                        0, 255, 0, 255);

      short x[6] = { 350, 275, 300, 325, 350, 400 }; 
      short y[6] = { 325, 325, 390, 390, 375, 300 };

      polygonRGBA(screen, 
                  x, y,
                  6,
                  255, 255, 255, 155);

      short s[5] = { 400, 450, 450, 425, 300 }; 
      short t[5] = { 400, 410, 450, 425, 500};

      filledPolygonRGBA(screen, 
                        s, t,
                        5,
                        255, 0, 255, 155);

      SDL_Flip(screen);
   }

   SDL_Quit();

   return 0;
}
