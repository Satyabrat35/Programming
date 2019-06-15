/**************erik****************/
// It could happen that a skipped odd node leads to a min hop value
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
//map<int,int> mp1;
//set<int> s1;
//set<int>::iterator it;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
#define f first
#define s second
typedef struct node
{
    int u, e, dist, hops;
}node;
 
auto comp = [](node &a, node &b)
{
    if(a.dist==b.dist)
        return a.hops>b.hops;
    return a.dist>b.dist;
};
 
const int MAX = 1000005;
int n, m;
vector<vector<pair<int,int>>> g;
vector<vector<int>> vis, hops;
vector<vector<long long>> dist;
 
void dijkstra()
{
    priority_queue<node, vector<node>, decltype(comp)> pq(comp);
    dist[0][0] = 0LL;
    dist[0][1] = 0LL;
    hops[0][0] = 0;
    hops[0][1] = 0;
    pq.push({0, 0, 0, 0});
    pq.push({0, 1, 0, 0});
    while(!pq.empty())
    {
        int u = pq.top().u, e = pq.top().e;
        pq.pop();
        if(vis[u][e])
            continue;
        vis[u][e] = 1;
        if(u==n-1)
            break;
        for(auto p:g[u])
        {
            int v = p.f, w = p.s;
            if(vis[v][w%2])
                continue;
            if(w%2==e)
            {
                if(dist[v][e] > dist[u][e] + w)
                {
                    dist[v][e] = dist[u][e] + w;
                    hops[v][e] = hops[u][e];
                    pq.push({v, e, dist[v][e], hops[v][e]});
                }
                else if(dist[v][e]==dist[u][e] + w && hops[v][e]>hops[u][e])
                {
                    hops[v][e] = hops[u][e];
                    pq.push({v, e, dist[v][e], hops[v][e]});
                }
            }
            else
            {
                if(dist[v][!e] > dist[u][e] + w)
                {
                    dist[v][!e] = dist[u][e] + w;
                    hops[v][!e] = hops[u][e] + 1;
                    pq.push({v, !e, dist[v][!e], hops[v][!e]});
                }
                else if(dist[v][!e] == dist[u][e] + w && hops[v][!e] > hops[u][e] + 1)
                {
                    hops[v][!e] = hops[u][e] + 1;
                    pq.push({v, !e, dist[v][!e], hops[v][!e]});
                }
            }
        }
    }
}
 
int main()
{
    cin>>n>>m;
    g.resize(n);
    vis.resize(n, vector<int>(2, 0));
    dist.resize(n, vector<long long>(2, LLONG_MAX));
    hops.resize(n, vector<int>(2, INT_MAX));
    for(int i=0;i<m;i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dijkstra();
    if(dist[n-1][0]<dist[n-1][1])
        cout<<dist[n-1][0]<<" "<<hops[n-1][0]<<endl;
    else if(dist[n-1][0]>dist[n-1][1])
        cout<<dist[n-1][1]<<" "<<hops[n-1][1]<<endl;
    else
        cout<<dist[n-1][0]<<" "<<min(hops[n-1][0], hops[n-1][1])<<endl;
    return 0;
}