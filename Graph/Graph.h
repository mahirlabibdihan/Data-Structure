#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
The following two are the most commonly used representations of a graph. 
1. Adjacency Matrix 
    Pros:
    a. Removing an edge takes O(1) time
    b. Checking whether there is an edge from vertex ‘u’ to vertex ‘v’ takes O(1) time
    Cons:
    a. Consumes more space O(n^2)
2. Adjacency List 
    Pros:
    a. Saves space O(|V|+|E|)
    Cons:
    a. Checking whether there is an edge from vertex ‘u’ to vertex ‘v’ takes O(n) time
*/


// Array Representation
class Graph1
{
    int** adj;
    bool *visited;
    int n;
public:
    Graph(int n)
    {
        this->n = n;
        adj = new int*[n];
        for(int i=0;i<n;i++)
        {
            adj[i] = new int[n]();
        }
        visited = new bool[n]();
    }

    // O(1)
    void connect(int u, int v)
    {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // O(1)
    void connect(int u, int v,int w)
    {
        adj[u][v] = w;
        adj[v][u] = w;
    }

    // O(1)
    bool isConnected(int u,int v)
    {
        return adj[u][v];
    }

    // O(1)
    void disconnected(int u,int v)
    {
        adj[u][v] = 0;
        adj[v][u] = 0;
    }

    // O(n^2)
    void dfs(int v)
    {
        visited[v]=true;
        for (int i=0;i<n;i++) 
        {
            if(adj[v][i]>0)
            {
                if(!visited[i])
                {
                    dfs(i);
                }  
            }            
        }
    }

    // O(n^2)
    void bfs(int v)
    {
        for(int i = 0; i < n; i++)
        {
            visited[i] = false;
        } 

        queue<int> q;

        visited[v]=true;
        q.push(v);

        while (!q.empty())
        {
            v = q.front(); 
            q.pop();
            for (int i=0;i<n;i++) 
            {
                if(adj[v][i]>0)
                {
                    if(!visited[i])
                    {
                        visited[i]=true;
                        q.push(i);
                    }     
                }       
            }
        }
    }
    void print()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

// List Representation
class Graph2
{
    vector<int> *adj;
    bool *visited;
    int n;
public:
    Graph(int n)
    {
        this->n = n;
        adj = new vector<int>[n];
        visited = new bool[n]();
    }
    void connect(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool isConnected(int u,int v)
    {
        for(int i:adj[u])
        {
            if(i==v)
            {
                return true;
            }
        }
        return false;
    }
    void disconnect(int u,int v)
    {
        for (int i = 0; i < adj[u].size(); i++) {
            if (adj[u][i] == v) {
                adj[u].erase(adj[u].begin() + i);
                break;
            }
        }

        for (int i = 0; i < adj[v].size(); i++) {
            if (adj[v][i] == u) {
                adj[v].erase(adj[v].begin() + i);
                break;
            }
        }
    }
    void print()
    {
        for(int i=0;i<n;i++)
        {
            cout<<i;
            for(int j:adj[i])
            {
                cout<<"->"<<adj[i][j];
            }
            cout<<endl;
        }
    }

    // O(n)
    void dfs(int v)
    {
        visited[v]=true;
        for (int i : adj[v]) 
        {
            if(!visited[i])
            {
                dfs(i);
            }  
        }
    }

    // O(n)
    void bfs(int v)
    {
        for(int i = 0; i < n; i++)
        {
            visited[i] = false;
        } 

        queue<int> q;

        visited[v]=true;
        q.push(v);

        while (!q.empty())
        {
            v = q.front(); 
            q.pop();
            for (int i : adj[v])
            {
                if(!visited[i])
                {
                    visited[i]=true;
                    q.push(i);
                }            
            }
        }
    }
};