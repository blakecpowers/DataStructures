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
	int count = 1;
	Vertex_t x;
	for (x = v; x->next != NULL; x = x->next)
	{
		count++;
	}
	std::cout<<count<<"\n";

	unsigned int D[count];
	// setting all weights to infinity
	for (int i = 0; i<count; i++)
	{
		D[i] = 999999;
	}
	// iterating through the edges, and updating their weights FROM THE START NODE ONLY.
	for (Edge_t temp = e; temp!= NULL; temp=temp->next)
	{
		vertexid_t v1,v2;
		temp->Get(&v1,&v2);
		if (int(v1) == start)
		{
			//v2-1 because the array is "0" based.
			D[int(v2)-1] = temp->GetWeight();
		}
	}
	// We need to make the weight from a vertice to itself be = 0;
 	D[start-1] = 0;
	bool S[count];
	// setting all the booleans to false unless it's the start node
	for (int i=0; i<count; i++)
	{
		if ((i+1) == start)
		{
			S[i] = true;
		}
		else
		{
			S[i] = false;
		}

	}


	

	for (int j=0; j<count; j++)
	{
		unsigned int SPath = 999999;
		int SVertex = 0;
		for (int i=0; i<count; i++)
		{
			if (S[i] == false)
			{
				if (SPath > D[i])
				{
					SPath = D[i];
					SVertex = i;
				}
			}
		}
		S[SVertex] = true;
		std:: cout<< SVertex << " has been added to S array." << std:: endl;
		// if the edge between a true and a false then......
		// if the v2 of the D array is greater than the weight at this temp + v1 of the D array
		// then set them equal.
		for (Edge_t temp = e; temp!= NULL; temp=temp->next)
		{
			vertexid_t v1,v2;
			temp->Get(&v1,&v2);
			if ((S[v1-1] == true) && (S[v2-1] == false))
			{
				if (D[v2-1] > temp->GetWeight() + D[v1-1])
				{
					D[v2-1] = temp->GetWeight() + D[v1-1];
				}
			} 
		}
	}
	for (int i=0; i<count; i++)
	{
		std:: cout<< "The weight from "<< start<< " to "<< i+1 << " is:" << D[i] << std:: endl;
	}
}




		/*vertexid_t v1,v2;
		temp->Get(&v1,&v2);
		for (int i = 0; i<count; i++)
		{
			if (S[i] == v1)
			{
				if (shortest->GetWeight() > temp->GetWeight())
				{
					shortest = temp;					
				}
			}	
		}
		S[int (v2) -1] = true;

		for (Edge_t temp = e->next; temp != NULL; temp = temp->next)
		{
			if 
		}*/

	
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
