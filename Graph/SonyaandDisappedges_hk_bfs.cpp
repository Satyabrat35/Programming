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
ll live[1000001];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector <int> v[n+1];
    int a[m+1],b[m+1];
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
        v[a[i]].push_back(i);
        v[b[i]].push_back(i);
        live[i]=1e9+6;
    }
    ll dist[n+1];
    for(int i=1;i<=n;i++){
        dist[i] = 1e9+6;
    }
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        y--;
        live[y]=x;
    }
    dist[1]=0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int z = q.front();
        q.pop();
        for(int i=0;i<v[z].size();i++){
            int edge = v[z][i];
            if(live[edge]<=dist[z]) // Check whether in a particular time it could cover the point or its vanished!
                continue;
            int dest;
            if(a[edge]==z)
                dest = b[edge];
            else
                dest = a[edge];
            if(dist[dest] > dist[z] + 1){
                dist[dest] = dist[z] + 1;
                q.push(dest);
            }
            }
        }
        if(dist[n]>=1e9+6){
            dist[n]=-1;
        }
        cout<<dist[n];
        return 0;
    }