#include <climits>
#include "graph.h"

Edge::Edge()
{
	id1 = 0;
	id2 = 0;
	w = UINT_MAX;
	next = NULL;
}

void
Edge::Get(vertexid_t *id1, vertexid_t *id2)
{
	if (id1 != NULL)
		*id1 = this->id1;
	if (id2 != NULL)
		*id2 = this->id2;
}

void
Edge::Set(vertexid_t id1, vertexid_t id2)
{
	this->id1 = id1;
	this->id2 = id2;
}

unsigned int
Edge::GetWeight()
{
	return w;
}

void
Edge::SetWeight(unsigned int w)
{
	this->w = w;
}

std::ostream&
operator<< (std::ostream& stream, const Edge& e)
{
	stream << "(" << e.id1 << "," << e.id2 << ")";
	stream << ":";
	if (e.w == UINT_MAX)
		stream << "INF";
	else
		stream << e.w;

	return stream;
}
