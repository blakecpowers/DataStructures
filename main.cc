#include <cstdlib>
#include "cli.h"

int
main(int argc, char **argv)
{
	class CLI cli;

	// All we do here is start a Command Line Interpreter (CLI)	
	cli.Start();

	// Not reached
	exit(0);
}
