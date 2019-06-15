// Traverse to the last node and start bfs from that node //
/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
map<int,int> mp1;
//set<int> s1,s2;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int main() {
    int n;
    cin>>n;
    vector <pair<int,int>> v[n+1];
    int dis[n+1];
    memset(dis,0,sizeof(dis));
    for(int i=0;i<(n-1);i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(make_pair(y,1));
        v[y].push_back(make_pair(x,1));
    }
    int mx=0;
    bool vis[n+1];
    queue<int> q;
    dis[1]=0;
    memset(vis,false,sizeof(vis));
    q.push(1);
    while(!q.empty()){
        int a = q.front();
        vis[a]=true;
        q.pop();
        for(int j=0;j<v[a].size();j++){
            int x = v[a][j].first;
            if(vis[x]==false){
                dis[x]=dis[a]+v[a][j].second;
                mx=max(mx,dis[x]);
                q.push(x);
                vis[x]=true;
            }
        }
    }
    int pos = max_element(dis+1,dis+n+1) - dis;
    dis[pos]=0;
    vis[pos]=true;
    mx = 0;
    memset(vis,false,sizeof(vis));
    q.push(pos);
    while(!q.empty()){
        int a = q.front();
        vis[a]=true;
        q.pop();
        for(int j=0;j<v[a].size();j++){
            int x = v[a][j].first;
            if(vis[x]==false){
                dis[x]=dis[a]+v[a][j].second;
                mx=max(mx,dis[x]);
                q.push(x);
                vis[x]=true;
            }
        }
    }
    cout<<mx<<endl;
    return 0;

}