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
ll dist[10005];

int main() {
    int t;
    cin>>t;
    while(t--){
    int n,m;
    cin>>n>>m;
    vector <int> v[n+1];
    for(int i=0;i<10005;i++){
        dist[i]=1e6;
    }
    while(m--){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    //bool vis[n+1];
    queue <int> q;
    dist[1]=0;
    q.push(1);
    while(!q.empty()){
        int a = q.front();
        q.pop();
        for(int i=0;i<v[a].size();i++){
            //cout<<dist[v[a][i]]<<endl;
            if(dist[v[a][i]] > dist[a] + 1){
                dist[v[a][i]] = dist[a] + 1;
                //cout<<v[a][i]<<' '<<dist[v[a][i]]<<endl;
                q.push(v[a][i]);
            }
        }
    }
    cout<<dist[n]<<endl;
    }
    return 0;

}