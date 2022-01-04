#include "Graph/LGraph.hpp"
#include <iostream>
#include <map>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

vector<int> solve(Graph *adj, int n, int m)
{
    vector<int> res;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1); // Initialize Q
    while (!pq.empty())
    { // Process all vertices on Q
        int v, w;
        v = pq.top();
        pq.pop();
        res.push_back(v);
        adj->setMark(v, VISITED);
        for (w = adj->first(v); w < adj->n(); w = adj->next(v, w))
        {
            if (adj->getMark(w) == UNVISITED)
            {
                adj->setMark(w, VISITED);
                pq.push(w);
            }
        }
    }
    return res;
}
int main()
{
    int n, m;
    cin >> n >> m;
    Graph *adj = new LGraph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj->setEdge(a, b);
        adj->setEdge(b, a);
    }
    vector<int> res = solve(adj, n, m);
    for (int i : res)
    {
        cout << i << " ";
    }
    delete adj;
}