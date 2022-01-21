#include "LGraph.hpp"
#include <vector>
#include "../Queue/AQueue.hpp"
vector<int> BFS(Graph *G, int start, int end, Queue<int> *q)
{
    vector<int> par(G->n(), -1);
    q->enqueue(start); // Initialize Q
    G->setMark(start, VISITED);
    while (q->length() != 0)
    { // Process all vertices on Q
        int v, w;
        v = q->dequeue();
        if (v == end)
        {
            break;
        }
        // PreVisit(G, v); // Take appropriate action
        for (w = G->first(v); w < G->n(); w = G->next(v, w))
        {
            if (G->getMark(w) == UNVISITED)
            {
                G->setMark(w, VISITED);
                q->enqueue(w);
                par[w] = v;
            }
        }
    }
    return par;
}
int main()
{
    int n, m;
    // cin >> n >> m;
    n = 10;
    m = 10;
    vector<string> grid = {"##########",
                           "#........#",
                           "#.....####",
                           "#........#",
                           "#..####..#",
                           "#..####..#",
                           "#........#",
                           "#...##...#",
                           "#...##...#",
                           "##########"};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << "DOWN" << endl;
    Graph *G = new LGraph(n * m);
    cout << "DOWN" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int idx = m * i + j;
            if (j > 0)
            {
                G->setEdge(idx, idx - 1);
            }
            if (j < m - 1)
            {
                G->setEdge(idx, idx + 1);
            }
            if (i > 0)
            {
                G->setEdge(idx, idx - n);
            }
            if (i < n - 1)
            {
                G->setEdge(idx, idx + n);
            }
            if (grid[i][j] == '#')
            {
                G->setMark(idx, VISITED);
            }
        }
    }
    int start = m + 1;
    int end = n * m - m - 2;
    vector<int> par = BFS(G, start, end, new AQueue<int>());
    int i = end;
    while (i > -1)
    {
        grid[i / m][i % m] = '=';
        i = par[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}