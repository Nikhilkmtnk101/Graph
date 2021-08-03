/*
    Template of Bidirectional Graph having both DFS and BFS can not be used for only primitive Data types and Strings.
*/
#include<bits//stdc++.h>
using namespace std;
#define pb push_back
template<typename T>
class Graph
{
public:
    int sz;
    map<T,vector<T>> graph;
    Graph(int n)
    {
        sz=n;
    }
    void add_edges(T u,T v)
    {
        graph[u].pb(v);
        graph[v].pb(u);
    }
    void dfs_helper(T src,map<T,bool> &vis,vector<T> &ans)
    {
        ans.pb(src);
        vis[src]=true;
        for(auto u:graph[src])
        {
            if(vis[u]==false)
            {
                dfs_helper(u,vis,ans);
            }
        }
    }
    vector<T> dfs(T src)
    {
        vector<T> ans;
        map<T,bool> vis;
        dfs_helper(src,vis,ans);
        return ans;
    }
    vector<T> bfs(T src)
    {
        queue<T> que;
        map<T,bool> vis;
        vis[src]=true;
        vector<T> ans;
        que.push(src);
        while(que.size()>0)
        {
            T node=que.front();que.pop();
            ans.pb(node);
            for(T u:graph[node])
            {
                if(vis[u]==false)
                {
                    vis[u]=true;
                    que.push(u);
                }
            }
        }
        return ans;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    Graph<int> g(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g.add_edges(u,v);
    }
    vector<int> dfs=g.dfs(0);
    vector<int> bfs=g.bfs(0);
    for(int i=0;i<n;i++)
    {
        cout<<dfs[i]<<" ";
    }
    cout<<'\n';
    for(int i=0;i<n;i++)
    {
        cout<<bfs[i]<<" ";
    }
    cout<<'\n';
}
