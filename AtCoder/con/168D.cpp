/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
//map<ll,ll> mp1;
//set<int> s1;
//set<int>::iterator it;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(ll i=0;i<n;i++)
#define rf(i,n) for(ll i=n-1;i>=0;i--)
#define PI 3.14159265
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vec(n);
    int dist[n+1];
    bool vis[n+1];
    for(int i=0;i<=n;i++){vis[i]=false;}
    f(i,m){
        int a,b;
        cin>>a>>b;
        vec[a-1].push_back(b-1);
        vec[b-1].push_back(a-1);
    }
    queue<int> q;
    q.push(0);
    dist[0]=0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<vec[x].size();i++){
            int p = vec[x][i];
            if(vis[p]==false){
                vis[p]=true;
                dist[p]=x+1;
                q.push(p);
            }
        }
    }
    cout<<"Yes"<<endl;
    for(int i=1;i<n;i++){
        cout<<dist[i]<<endl;
    }
}