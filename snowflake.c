#include <stdio.h>
#include <stdlib.h>
#include "turtle.h"

void snowflake(int depth, int side)
{
	koch(depth, side); turn(120);
	koch(depth, side); turn(120);
	koch(depth, side); turn(120);
}

int main_snowflake(int argc, char **argv)
{
	if (argc < 3) {
		printf("Usage:\n");
		printf("%s [depth] [side]\n", argv[0]);
		exit(1);
	}

	startTurtle();
	snowflake(atoi(argv[1]), atoi(argv[2]));

	pause();

	return 0;
}
