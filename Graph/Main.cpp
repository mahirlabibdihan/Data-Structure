#include "LGraph.hpp"
int main()
{
	Graph *g = new LGraph(10);
	g->setEdge(0, 9, 4);
	g->setEdge(1, 2);
	g->setEdge(0, 7, 3);
	cout << g << endl;
}