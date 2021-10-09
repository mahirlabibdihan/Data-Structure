#include<bits/stdc++.h>
using namespace std;
#define INF 1e18
#define MAX 100001
vector<int> adj[MAX];  //connected vertex
vector<int> cost[MAX];  //cost of edges
vector<int> dist(MAX, INF); //minimum distance of a vertex from the source
vector<int> par(MAX, -1); //parent vertex of a child vertex
vector<int> ans;
queue<int> q;  //temporary queue
vector<bool> visited;

class graph
{
public:


    void input(int m)
    {
        while (m--)
        {
            int a, b, c;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }


    void output(int m)
    {
        for (int i = 1; i <= m; i++)
        {   cout << i << "(" << adj[i].size() << ")" << "->";
            for (int j = 0; j < adj[i].size(); j++)
                cout << adj[i][j] << " ";
            cout << endl;
        }
    }

    void traversal()
    {
        for (int i : ans) cout << i << " "; cout << endl;

    }

    void bfs(int a)
    {
        dist[a] = 0; 
        q.push(a);
        while (!q.empty())
        {
            int u = q.front(),v; 
            ans.push_back(u);
            q.pop();
            for (auto i : adj[u])
            {
                v = i;
                if (dist[v] == INF)
                {   
                    dist[v] = dist[u] + 1;
                    par[v] = u;
                    q.push(v);
                }
            }
        }
    }

    void dfs(int prev, int current)
    {
        for (auto i : adj[current]) 
            if (i != prev) 
                {cout << i << " "; dfs(current, i);}
    }


    /*
    void path(int a)
    {
        if(parent[a]>-1)
        {vector<int> path;
        int i=a;
        path.push_back(i);

        while(parent[i]>-1)
        {
            path.push_back(parent[i]);
            i=parent[i];
        }


        for(i=path.size()-1;i>-1;i--)
            cout<<path[i]<<" ";}

        else cout<<-1;

    }*/

    void path(int i)
    {
        if (i != 1) path(par[i]);
        cout << i << " ";
    }

};




int main()
{
    int n, m;
    cin >> n >> m;

    graph a;

    a.input(n - 1);
    a.bfs(0);
}

// KzQ5MTUyMjg5ODM4Njg=