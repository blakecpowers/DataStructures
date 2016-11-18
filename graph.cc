#include "graph.h"

Graph::Graph()
{
	v = NULL;
	e = NULL;
	nextid = 1;
	next = NULL;
}

vertexid_t
Graph::NextID()
{
	// Each graph keeps a counter of vertex ids to be used and
	// incremented when a new vertex is created
	return nextid++;
}

Vertex_t
Graph::FirstVertex()
{
	return v;
}

Edge_t
Graph::FirstEdge()
{
	return e;
}

void
Graph::Insert(Vertex_t v)
{
	Vertex_t w;

	if (this->v == NULL) {
		this->v = v;
		return;
	}
	// Insert at the end of the vertex list
	for (w = this->v; w->next != NULL; w = w->next);
	w->next = v;
}

void
Graph::Insert(Edge_t e)
{
	Edge_t w;

	if (this->e == NULL) {
		this->e = e;
		return;
	}
	// Insert at the end of the edge list
	for (w = this->e; w->next != NULL; w = w->next);
	w->next = e;
}

void
Graph::Dijkstra(int start)
{
	std::cout << "Dijkstra for vertex " << start << "\n";
}

std::ostream&
operator<< (std::ostream& stream, const Graph& g)
{
	Vertex_t v;
	Edge_t e;

	stream << "({";
	for (v = g.v; v != NULL; v = v->next) {
		stream << *v;
		if (v->next != NULL)
			stream << ",";
	}
	stream << "},{";
	for (e = g.e; e != NULL; e = e->next) {
		stream << *e;
		if (e->next != NULL)
			stream << ",";
	}
	stream << "})";
	return stream;
}
