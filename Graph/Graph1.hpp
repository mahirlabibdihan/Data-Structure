#include <iostream>
using namespace std;
// Array Representation
class Graph1
{
    int** adj;
    bool *visited;
    int n;
public:
    Graph1(int n)
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
