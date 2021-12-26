#ifndef __GRAPH__
#define __GRAPH__
#include "../Queue/LQueue.hpp"
#define Assert(val, s)                             \
    if (!(val))                                    \
    {                                              \
        cout << "Assertion Failed: " << s << endl; \
        exit(-1);                                  \
    }
#define VISITED true
#define UNVISITED false
// Graph abstract class. This ADT assumes that the number
// of vertices is fixed when the graph is created.
class Graph
{
private:
    void operator=(const Graph &) {} // Protect assignment
    Graph(const Graph &) {}          // Protect copy constructor
public:
    Graph() {}          // Default constructor
    virtual ~Graph() {} // Base destructor
    // Initialize a graph of n vertices
    virtual void init(int n) = 0;
    // Return: the number of vertices and edges
    virtual int n() = 0;
    virtual int e() = 0;
    // Return v’s first neighbor
    virtual int first(int v) = 0;
    // Return v’s next neighbor
    virtual int next(int v, int w) = 0;
    // Set the weight for an edge
    // i, j: The vertices
    // wgt: Edge weight
    virtual void setEdge(int v1, int v2, int wght = 1) = 0;
    // Delete an edge
    // i, j: The vertices
    virtual void delEdge(int v1, int v2) = 0;
    // Determine if an edge is in the graph
    // i, j: The vertices
    // Return: true if edge i,j has non-zero weight
    virtual bool isEdge(int i, int j) = 0;
    // Return an edge’s weight
    // i, j: The vertices
    // Return: The weight of edge i,j, or zero
    virtual int weight(int v1, int v2) = 0;
    // Get and Set the mark value for a vertex
    // v: The vertex
    // val: The value to set
    virtual int getMark(int v) = 0;
    virtual void setMark(int v, int val) = 0;
};
void DFS(Graph *G, int v)
{ // Depth first search
    // PreVisit(G, v); // Take appropriate action
    G->setMark(v, VISITED);
    for (int w = G->first(v); w < G->n(); w = G->next(v, w))
        if (G->getMark(w) == UNVISITED)
            DFS(G, w);
    // PostVisit(G, v); // Take appropriate action
}
void BFS(Graph *G, int start, Queue<int> *Q)
{
    int v, w;
    Q->enqueue(start); // Initialize Q
    G->setMark(start, VISITED);
    while (Q->length() != 0)
    { // Process all vertices on Q
        v = Q->dequeue();
        // PreVisit(G, v); // Take appropriate action
        for (w = G->first(v); w < G->n(); w = G->next(v, w))
            if (G->getMark(w) == UNVISITED)
            {
                G->setMark(w, VISITED);
                Q->enqueue(w);
            }
    }
}
ostream &operator<<(ostream &os, Graph *g)
{
    for (int i = 0; i < g->n(); i++)
    {
        cout << i;
        int w = g->first(i);
        while (w != g->n())
        {
            cout << "->" << w << "[" << g->weight(i, w) << "]";
            w = g->next(i, w);
        }
        cout << endl;
    }
    return os;
}
#endif