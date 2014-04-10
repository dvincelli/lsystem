#ifndef TURTLE_H
#define TURTLE_H
void setPoint(int x, int y);
void drawLine(int x, int y);
void forward(int step);
void backward(int step);
void turn(int alpha);
void startTurtle();
void hilbert(int depth, int side, int direction);
#endif
