// Optimized Undirected Graph
// Lower triangular Matrix
/*
Graph:
5
1 2
3 4
5 2
1 5
Representation:
  1 2 3 4 5
1 0
2 1 0
3 0 0 0
4 0 0 1 0
5 0 1 0 0 1
*/
#ifndef __A_U_GRAPH__
#define __A_U_GRAPH__
#include "Graph.hpp"
// Implementation for the adjacency matrix representation
class AUGraph : public Graph
{
private:
    int numVertex, numEdge; // Store number of vertices, edges
    int **matrix;           // Pointer to adjacency matrix
    int *mark;              // Pointer to mark array
public:
    AUGraph(int numVert) // Constructor
    {
        init(numVert);
    }
    ~AUGraph()
    {                  // Destructor
        delete[] mark; // Return dynamically allocated memory
        for (int i = 0; i < numVertex; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    void init(int n)
    { // Initialize the graph
        int i;
        numVertex = n;
        numEdge = 0;
        mark = new int[n]; // Initialize mark array
        for (i = 0; i < numVertex; i++)
        {
            mark[i] = UNVISITED;
        }
        matrix = (int **)new int *[numVertex]; // Make matrix
        for (i = 0; i < numVertex; i++)
        {
            matrix[i] = new int[i + 1];
        }
        for (i = 0; i < numVertex; i++) // Initialize to 0 weights
        {
            for (int j = 0; j <= i; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    int n() { return numVertex; } // Number of vertices
    int e() { return numEdge; }   // Number of edges
    // Return first neighbor of "v"
    int first(int v)
    {
        for (int i = 0; i < numVertex; i++)
        {
            if (matrix[max(v, i)][min(v, i)] != 0)
            {
                return i;
            }
        }
        return numVertex; // Return n if none
    }
    // Return v’s next neighbor after w
    int next(int v, int w)
    {
        for (int i = w + 1; i < numVertex; i++)
        {
            if (matrix[max(v, i)][min(v, i)] != 0)
            {
                return i;
            }
        }
        return numVertex; // Return n if none
    }
    // Set edge (v1, v2) to "wt"
    void setEdge(int v1, int v2, int wt = 1) // 1 for unweighted
    {
        Assert(wt > 0, "Illegal weight value");
        if (!isEdge(v1, v2))
        {
            numEdge++;
        }
        matrix[max(v1, v2)][min(v1, v2)] = wt;
    }
    void delEdge(int v1, int v2)
    { // Delete edge (v1, v2)
        if (isEdge(v1, v2))
        {
            numEdge--;
        }
        matrix[max(v1, v2)][min(v1, v2)] = 0;
    }
    bool isEdge(int i, int j) // Is (i, j) an edge?
    {
        return matrix[max(i, j)][min(i, j)] != 0;
    }
    int weight(int v1, int v2) { return matrix[max(v1, v2)][min(v1, v2)]; }
    int getMark(int v) { return mark[v]; }
    void setMark(int v, int val) { mark[v] = val; }
};
#endif