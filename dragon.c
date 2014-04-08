#include <stdio.h>
#include <unistd.h>
#include "turtle.h"

void dragon(int depth, int side)
{
	if (depth ==  0) {
		forward(side);
	} else if (depth > 0) {
		dragon(depth-1, side);
		turn(90);
		dragon(-(depth-1), side);
	} else {
		dragon(-(depth+1), side);
		turn(270);
		dragon(depth+1, side);
	}
}

int main(int argc, char *argv[]) {

	if (argc < 3) {
		printf("Usage:\n");
		printf("%s [depth] [side]\n", argv[0]);
		return 1;
	}

	startTurtle();

	dragon(atoi(argv[1]), atoi(argv[2]));

	return 0;
}
