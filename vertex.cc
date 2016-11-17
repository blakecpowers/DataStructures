#include <cstdlib>
#include "graph.h"

// Flag indicating whether the random number generated has been seeded
static int seeded = 0;

vertexid_t vertexid_rand()
{
	if (!seeded) {
		srand(time(NULL));
		seeded = 1;
	}
	// XXX Limit value to 16 bits for the moment
	return (vertexid_t) (rand() % 0x10000);
}

Vertex::Vertex()
{
	id = 0;
	next = NULL;
}

std::ostream&
operator<< (std::ostream& stream, const Vertex& v)
{
	//stream << std::hex << v.id;
	stream << v.id;
	return stream;
}
