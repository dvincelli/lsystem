#include <stdio.h>
#include <stdlib.h>
#include "turtle.h"

void koch(int depth, int side)
{
	if (depth == 0) {
		forward(side);
	} else {
		koch(depth-1, side/3.0);
		turn(-60);

		koch(depth-1, side/3.0);
		turn(120);

		koch(depth-1, side/3.0);
		turn(-60);

		koch(depth-1, side/3.0);
	}
}

int main_koch(int argc, char **argv)
{
	if (argc < 3) {
		printf("Usage:\n");
		printf("%s [depth] [side]\n", argv[0]);
		exit(1);
	}

	startTurtle();
	koch(atoi(argv[1]), atoi(argv[2]));

	return 0;
}
