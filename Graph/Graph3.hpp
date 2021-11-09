#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
// Weighted Graph
class Graph3
{
    vector<pair<int,int>> *adj;
    int n;
    Graph3()
    {
        this->n=n;
    }
    void connect(int u,int v,int w)
    {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    void directConnect(int u,int v,int w)
    {
        adj[u].push_back({v,w});
    }
     void djikstra(int a)
    {
        vector<int> dist(n, INT_MAX); 
        priority_queue<pair<int,int>> q;

        dist[a] = 0; 
        q.push({dist[a], a});

        while (!q.empty())
        {
            int u = q.top().second;
            q.pop();
            for (auto i : adj[u])
            {
                int v = i.first;
                if (dist[v] > dist[u] + i.second)
                {   
                    dist[v] = dist[u] + i.second;
                    // par[v] = u;
                    q.push({ -dist[v], v});
                }
            }
        }
    }
};