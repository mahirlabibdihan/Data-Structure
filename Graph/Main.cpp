#include "Graph2.hpp"
int main()
{
	Graph g(6);
	g.connect(0,1);
	g.connect(1,2);
	g.connect(0,2);

	cout<<g.isBipartite()<<endl;
}