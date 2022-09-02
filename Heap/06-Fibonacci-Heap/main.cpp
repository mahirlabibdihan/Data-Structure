#include <iostream>
#include <fstream>
#include <vector>
#include "Dijkstra.hpp"
#include "BinPriorityQueue.hpp"
#include "FibPriorityQueue.hpp"
#include <chrono>
using namespace std;
using namespace chrono;
// For undirected graph
void printPath(int u, vector<int> &parent)
{
    if (parent[u] != -1)
    {
        printPath(parent[u], parent);
    }
    cout << u << " -> ";
}
int countLength(int u, vector<int> &parent)
{
    if (parent[u] == -1)
    {
        return 0;
    }
    // cout << u << " ";
    int sz = countLength(parent[u], parent) + 1;
    // cout << sz << " ";
    return sz;
}
void print(vector<int> &parent, vector<int64_t> &dist, int d, chrono::time_point<chrono::system_clock> startTime, chrono::time_point<chrono::system_clock> endTime)
{
    if (parent[d] == -1)
    {
        cerr << "Destination not reachable" << endl;
        return;
    }
    cout << "Shortest path cost: " << dist[d] << endl;
    cout << "Shortest path: ";
    printPath(parent[d], parent);
    cout << d << endl;
    cout << "Shortest path length: " << countLength(d, parent) << endl;
    cout << "Execution time: " << (chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count() / (1000000.0)) << " ms" << endl;
}
void binary(vector<pair<int, int64_t>> adj[], int n, int s, int d)
{
    // cout << "BINARY HEAP" << endl;
    chrono::time_point<system_clock> startTime = chrono::high_resolution_clock::now();
    vector<int64_t> dist(n);
    vector<int> parent(n);
    PriorityQueue<int, int64_t> *pq = new BinPriorityQueue<int, int64_t>(n);
    dijkstra(adj, n, s, dist, parent, pq);
    chrono::time_point<system_clock> endTime = chrono::high_resolution_clock::now();
    // print(parent, dist, d, startTime, endTime);
    printf("%6d %7lld %10g ms ", countLength(d, parent), dist[d], chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count() / (1000000.0));
}
void fibonacci(vector<pair<int, int64_t>> adj[], int n, int s, int d)
{
    // cout << "FIBONACCI HEAP" << endl;
    chrono::time_point<system_clock> startTime = chrono::high_resolution_clock::now();
    vector<int64_t> dist(n);
    vector<int> parent(n);
    PriorityQueue<int, int64_t> *pq = new FibPriorityQueue<int, int64_t>(n);
    dijkstra(adj, n, s, dist, parent, pq);
    chrono::time_point<system_clock> endTime = chrono::high_resolution_clock::now();
    // print(parent, dist, d, startTime, endTime);
    printf("%10g ms\n", chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count() / (1000000.0));
}
int main()
{
    ifstream input;
    input.open("test_2_graph.in");
    freopen("output.in", "w", stdout);
    // freopen("graph.in", "r", stdin);
    int n, m;
    input >> n >> m;
    vector<pair<int, int64_t>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        int64_t w;
        input >> u >> v >> w;
        // cout << u << " " << v/ << endl;
        // u--;
        // v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        // cout << "." << endl;
    }
    // freopen("path.in", "r", stdin);
    printf("%6s %7s %13s %13s\n", "Length", "Cost", "Binary", "Fibonacci");
    input.close();
    input.open("test_2_query.in");
    int k;
    input >> k;
    while (k--)
    {
        int s, d;
        input >> s >> d;
        // cout << s << " " << d << endl;
        binary(adj, n, s, d);
        fibonacci(adj, n, s, d);
    }
    input.close();
    return EXIT_SUCCESS;
}
