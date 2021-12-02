#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
// List Representation
class Graph
{
    vector<int> *adj;
    int *inDegree;
    bool *visited;
    int n;
public:
    Graph(int n)
    {
        this->n = n;
        adj = new vector<int>[n];
        visited = new bool[n]();
        inDegree = new int[n]();
    }
    void connect(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void directConnect(int u,int v)
    {
        adj[u].push_back(v);
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
    void topoSort()
    {
        for(int i=0;i<n;i++)
        {
            inDegree[i] = visited[i] = 0;
        }

        for(int i=0;i<n;i++)
        {
            for(int j:adj[i])
            {
                inDegree[j]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(inDegree[i]==0)
                {
                    visited[i]=true;
                    q.push(i);
                }
            }         
        }

        while(!q.empty())
        {
            int v = q.front();
            q.pop();

            cout<<v<<endl;
            for(int i:adj[v])
            {
                if(!visited[i])
                {
                    inDegree[i]--;
                    if(inDegree[i]==0)
                    {
                        visited[i]=true;
                        q.push(i);
                    }
                }             
            }        
        }
    }
    bool colorGraph(int *color,int pos,int c)
    {
        color[pos] = c;
        bool ans=true;
        for(int i:adj[pos])
        {
            if(!color[i])
            {
                ans=ans&&colorGraph(color,i,-color[pos]);
            }
            else if(color[i]==color[pos])
            {
                ans=false;
            }
        }
        return ans;
    }
    bool isBipartite()
    {
        int *color=new int[n]();
        return colorGraph(color,0,1);
    }
};