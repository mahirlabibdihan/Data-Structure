#ifndef __GRAPH__
#define __GRAPH__
#include "../Queue/LQueue.hpp"
#include "../List/List.hpp"
#define Assert(val, s)                             \
    if (!(val))                                    \
    {                                              \
        cout << "Assertion Failed: " << s << endl; \
        exit(-1);                                  \
    }
#define VISITED 1
#define UNVISITED 0
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
void resetMark(Graph *G)
{
    for (int i = 0; i < G->n(); i++)
    {
        G->setMark(i, UNVISITED);
    }
}
void DFS(Graph *G, int v)
{ // Depth first search
    // PreVisit(G, v); // Take appropriate action
    G->setMark(v, VISITED);
    for (int w = G->first(v); w < G->n(); w = G->next(v, w))
    {
        if (G->getMark(w) == UNVISITED)
        {
            DFS(G, w);
        }
    }
    // PostVisit(G, v); // Take appropriate action
}

List<int> *rootForMinimumHeight(Graph *G, Queue<int> *q, List<int> *degree)
{
    //  first enqueue all leaf nodes in queue
    int V = G->n();
    for (int i = 0; i < V; i++)
    {
        degree->moveToPos(i);
        if (degree->getValue() == 1)
        {
            G->setMark(i, VISITED);
            q->enqueue(i);
        }
    }

    //  loop until total vertex remains less than 2
    while (V > 2)
    {
        int popEle = q->length();
        V -= popEle; // popEle number of vertices will be popped

        for (int i = 0; i < popEle; i++)
        {
            int v, w;
            v = q->dequeue();

            // for each neighbour, decrease its degree and
            // if it become leaf, insert into queue
            for (w = G->first(v); w < G->n(); w = G->next(v, w))
            {
                if (G->getMark(w) == UNVISITED)
                {
                    degree->moveToPos(w);
                    int tmp = degree->getValue() - 1;
                    degree->remove();
                    degree->insert(tmp);
                    if (degree->getValue() == 1)
                    {
                        q->enqueue(w);
                        G->setMark(w, VISITED);
                    }
                }
            }
        }
    }

    //  copying the result from queue to result vector
    List<int> *res; /// NEED TO ALLOCATE MEMORY
    while (q->length() > 0)
    {
        res->append(q->dequeue());
    }
    return res;
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