#include "hilbert.h"
#include "dragon.h"
#include "koch.h"
#include "snowflake.h"

#include <stdio.h>
#include <libgen.h>


int main(int argc, char **argv)
{
	char *progname = basename(argv[0]);

	if (strcmp(progname, "dragon") == 0) {
		main_dragon(argc, argv);
	}
	if (strcmp(progname, "hilbert") == 0) {
		main_hilbert(argc, argv);
	}
	if (strcmp(progname, "koch") == 0) {
		main_koch(argc, argv);
	}
	if (strcmp(progname, "snowflake") == 0) {
		main_snowflake(argc, argv);
	}

	for(;;) {
		handle_exit();
	}

	return 0;
}
