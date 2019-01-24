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
int main(){
    int t;
    cin>>t;
    while(t--){
    int n,st,en;
    cin>>n>>st>>en;
    vector<int> v[n+1];
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        int a,b;
        a = i + (x%n);
        b = i - (x%n);
        if(a>n)
            a=a%n;
        if(b<=0)
            b=b+n;
        v[i].push_back(a);
        v[i].push_back(b);
    }
    int dist[n+1];
    for(int i=1;i<=n;i++){
        dist[i]=1e6;
    }
    queue <int> q;
    q.push(st);
    dist[st]=0;
    while(!q.empty()){
        int z = q.front();
        q.pop();
        for(int i=0;i<v[z].size();i++){
            if(dist[v[z][i]] > dist[z] + 1){
                dist[v[z][i]] = dist[z] + 1;
                q.push(v[z][i]);
            }
        }
    }
    if(dist[en] == 1e6)
        dist[en]=-1;
    cout<<dist[en]<<endl;
    }
    return 0;
}