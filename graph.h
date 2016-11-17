#ifndef __GRAPH_H
#define __GRAPH_H

#include <iostream>

typedef unsigned long long u64_t;
typedef u64_t vertexid_t;

vertexid_t vertexid_rand();

// Forward declarations
class Vertex;
class Edge;
class Graph;

typedef class Vertex *Vertex_t;
typedef class Edge *Edge_t;
typedef class Graph *Graph_t;
//
// Now we can use these typedefs in the class declarations
//

class Vertex {
public:
	vertexid_t id;
	Vertex_t next;

	Vertex();

	friend std::ostream& operator<<
                (std::ostream& stream, const Vertex& v);
};

class Edge {
private:
	vertexid_t id1, id2;
	unsigned int w;		// Weight

public:
	Edge_t next;

	Edge();

	void Get(vertexid_t *id1, vertexid_t *id2);
	void Set(vertexid_t id1, vertexid_t id2);

	unsigned int GetWeight();
	void SetWeight(unsigned int w);

	friend std::ostream& operator<<
                (std::ostream& stream, const Edge& e);
};

class Graph {
private:
	Vertex_t v;
	Edge_t e;
	vertexid_t nextid;

public:
	Graph_t next;

	Graph();
	vertexid_t NextID();
	Vertex_t FirstVertex();
	Vertex_t NextEdge(Vertex_t v);
	Edge_t FirstEdge();
	Edge_t NextEdge(Edge_t e);
	void Insert(Vertex_t v);
	void Insert(Edge_t e);

	void Dijkstra(int start);

	friend std::ostream& operator<<
                (std::ostream& stream, const Graph& g);
};

#endif
