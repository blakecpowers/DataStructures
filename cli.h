#ifndef __CLI_H
#define __CLI_H

#include "graph.h"

#define BUFSIZE		0x1000
#define PROMPT		"db> "

char *readline(char *prompt);
void nextarg(char *ln, int *pos, char *sep, char *arg);

class Cmd {
public:
        char *cmd;
        void (*f) (char *cmdline, int *pos);
};

class CLI {
private:
	char *cmdline;
	int pos;

public:
	CLI();
	void Start();

	static void Quit(char *cmdline, int *pos);
	static void Graph(char *cmdline, int *pos);
};

extern Graph_t graphs;

void graphs_insert(Graph_t g);
int graphs_get_current_index();


#endif
