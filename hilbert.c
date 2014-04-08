#include "turtle.h"

void hilbert(int depth, int side, int direction)
{
	if (depth > 0) {
		turn(-direction * 90);
		hilbert(depth-1, side, -direction);
		forward(side);

		turn(direction * 90);
		hilbert(depth-1, side, direction);
		forward(side);

		hilbert(depth-1, side, direction);
		turn(direction * 90);
		forward(side);

		hilbert(depth-1, side, direction);
		turn(direction * 90);
	}
}

int main(int argc, char *argv[]) {

	if (argc < 4) {
		printf("Usage:\n");
		printf("%s [depth] [side] [direction]\n", argv[0]);
		exit(1);
	}

	startTurtle();

	hilbert(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));

	return 0;
}
