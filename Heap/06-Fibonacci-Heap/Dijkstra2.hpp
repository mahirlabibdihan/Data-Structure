#include <vector>
// #include <queue>
#include <climits>
#include "BinPriorityQueue.hpp"
#include "FibPriorityQueue.hpp"
#include "PriorityQueue.hpp"
using namespace std;

void dijkstra(vector<pair<int, int64_t>> adj[], int n, int source, vector<int64_t> &dist, vector<int> &parent, PriorityQueue<int, int64_t> *pq)
{
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[source] = 0;
    pq->push(source, dist[source], source);

    // Initialize heap array
    // O(ElogV)
    for (int i = 0; i < n; i++)
    { // Now, get distances
        pair<int64_t, int> temp;
        int u;
        int64_t w;
        // cout << "START" << endl;
        do
        {
            // cout << pq->size() << endl;
            if (pq->empty())
            {
                // Nothing to remove
                cout << "EMPTY" << endl;
                return;
            }
            u = pq->top();
            pq->pop(); // O(logV)

        } while (visited[u]);
        // cout << "END" << endl;
        visited[u] = true;
        // cout << u << " " << w << endl;
        for (pair<int, int64_t> i : adj[u]) // Sum of length of all adjacency list is 2|E|
        {
            int v = i.first;
            int64_t w = i.second;

            // RELAX
            // cout << v << " " << w << " " << n << endl;
            if (!visited[v] && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;   // Update distance
                parent[v] = u;           // Update who it came from
                pq->push(v, dist[v], v); // Insert new distance in heap // O(logV)
            }
            // cout << "PASSED";
        }
    }
}