#include <vector>
#include <climits>
#include "BinPriorityQueue.hpp"
#include "FibPriorityQueue.hpp"
#include "PriorityQueue.hpp"
using namespace std;

void dijkstra(vector<pair<int, int64_t>> adj[], int n, int source, vector<int64_t> &dist, vector<int> &parent, PriorityQueue<int, int64_t> *pq)
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = LLONG_MAX;
        parent[i] = -1;
    }
    dist[source] = 0;
    for (int i = 0; i < n; i++)
    {
        pq->push(i, dist[i], i);
    }
    while (!pq->empty()) // O(V)
    {                    // Now, get distances
        int u = pq->top();
        pq->pop();                          // O(logV)
        for (pair<int, int64_t> i : adj[u]) // Sum of length of all adjacency list is 2|E|
        {
            int v = i.first;
            int64_t w = i.second;
            if (pq->isExist(v) && dist[u] < LLONG_MAX && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;       // Update distance
                parent[v] = u;               // Update who it came from
                pq->decreaseKey(v, dist[v]); // Insert new distance in heap // O(logV)
            }
        }
    }
}