#include "Graph.h"
int main()
{
	Graph2 g(6);

	g.directConnect(2,3);
	g.directConnect(5,0);
	g.directConnect(4,0);
	g.directConnect(4,1);
	g.directConnect(3,1);

	g.topoSort();
}