#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <iostream>
#include "cli.h"
#include "graph.h"

static class Cmd cmds[] = {
	{ "g", CLI::Graph },
	{ "quit", CLI::Quit },
};
static int ncmds = sizeof(cmds) / sizeof(cmds[0]);

int tty = 0;
Graph_t graphs = NULL;
Graph_t current = NULL;

static void
banner()
{
	std::cout << "Graph Database\n";
	std::cout << "Written by Frank W. Miller\n";
}

CLI::CLI()
{
	cmdline = NULL;
	pos = 0;
}

void
CLI::Start()
{
	char cmd[BUFSIZE], prompt[BUFSIZE];
	int i;

	tty = isatty(STDIN_FILENO);

	if (tty)
		banner();

	for (;;) {
		if (cmdline != NULL)
			free(cmdline);

		//cmdline = readline(PROMPT);
		memset(prompt, 0, BUFSIZE);
		if (graphs == NULL)
			sprintf(prompt, "> ");
		else
			sprintf(prompt, "%d> ", graphs_get_current_index());

		if (tty)
			cmdline = readline(prompt);
		else
			cmdline = readline("");

		if (cmdline == NULL || strlen(cmdline) == 0)
			continue;

		memset(cmd, 0, BUFSIZE);
		pos = 0;
		nextarg(cmdline, &pos, " ", cmd);

		for (i = 0; i < ncmds; i++)
			if (strcmp(cmd, cmds[i].cmd) == 0)
				(*(cmds[i].f)) (cmdline, &pos);
	}
}

static void
cli_graph_edge(char *cmdline, int *pos)
{
	char s[BUFSIZE];
	int args, i, j, k;

	args = 0;
	memset(s, 0, BUFSIZE);
	nextarg(cmdline, pos, " ", s);
	if (strlen(s) > 0) {
		// First arg
		i = atoi(s);
		args++;

		memset(s, 0, BUFSIZE);
		nextarg(cmdline, pos, " ", s);
		if (strlen(s) > 0) {
			// Second arg
			j = atoi(s);
			args++;

			memset(s, 0, BUFSIZE);
			nextarg(cmdline, pos, " ", s);
			if (strlen(s) > 0) {
				// Third arg
				k = atoi(s);
				args++;
			}
		}
	}
	if (args == 3) {
		Edge_t e = new class Edge;

		// Add a fully specified edge with a weight

		// XXX Check whether specified vertices correspond to
		//       existing vertices in the graph

		e->Set(i, j);
		e->SetWeight(k);
		current->Insert(e);

	} else if (args == 2) {
		Vertex_t v = new class Vertex;
		Edge_t e = new class Edge;

		// Add an edge using a specified existing vertex with
		//   a new random vertex and the specified weight

		v->id = current->NextID();
		current->Insert(v);
		e->Set(i, v->id);
		e->SetWeight(j);
		current->Insert(e);

	} else if (args == 1) {
		// Add an edge with an existing random vertex and one
		//   new random vertex with the specified weight
	}
}

void
CLI::Graph(char *cmdline, int *pos)
{
	char s[BUFSIZE];

	memset(s, 0, BUFSIZE);
	nextarg(cmdline, pos, " ", s);

	if (strlen(s) == 0) {
		Graph_t g;
		int cnt = 0;

		// Dump list of graphs
		for (g = graphs; g != NULL; g = g->next, cnt++) {
			if (g == current)
				std::cout << ">";
			std::cout << cnt << ":" << *g << "\n";
		}
	}
	if (strcmp(s, "new") == 0 || strcmp(s, "n") == 0) {
		Vertex_t v = new class Vertex;
		Graph_t g = new class Graph;

		// Create a new graph and insert it in graphs
		v->id = g->NextID();
		g->Insert(v);
		graphs_insert(g);
		if (current == NULL)
			current = g;
	}
	if (strcmp(s, "edge") == 0 || strcmp(s, "e") == 0) {
		cli_graph_edge(cmdline, pos);
	}
	if (strcmp(s, "dijkstra") == 0 || strcmp(s, "d") == 0) {
		char s[BUFSIZE];

		memset(s, 0, BUFSIZE);
		nextarg(cmdline, pos, " ", s);

		if (current != NULL)
			current->Dijkstra(atoi(s));
	}
	if (isdigit(s[0])) {
		Graph_t g;
		int cnt, i;

		i = atoi(s);
		for (cnt = 0, g = graphs; g != NULL; cnt++, g = g->next)
			if (cnt == i)
				current = g;
	}
}

void
CLI::Quit(char *cmdline, int *pos)
{
	exit(0);
}

void
graphs_insert(Graph_t g)
{
	Graph_t f;

	if (graphs == NULL) {
		graphs = g;
		return;
	}
	for (f = graphs; f->next != NULL; f = f->next);
	f->next = g;
}

int
graphs_get_current_index()
{
	Graph_t g;
	int cnt = 0;

	for (g = graphs; g != NULL; g = g->next, cnt++)
		if (g == current)
			return cnt;

	return (-1);
}

