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
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
ll  visit[2000003];
ll  M[2000003],k,t,l,n,m;
ll  W[2000003];
vector< ll> graph[2000003];
void  dfs(vector<ll>graph[],ll s){
     visit[s]=1;
     if(s>n){
         k++;
     }
    if(s<=n){
        l++;
    }
    for(ll i=0;i<graph[s].size();i++){
        if(!visit[graph[s][i]]){
            dfs(graph,graph[s][i]);
        }
    }
    return ;
    
}
int main(){
    ll  i,x,a,b,z,y,j,p,c,v;
    cin>>n>>m;
    cin>>v;
    while(v--){
    cin>>a>>b;
    graph[a].push_back(b);
        graph[b].push_back(a);

    }
    cin>>v;
    while(v--){
    cin>>a>>b;
        a=a+n;
        b=b+n;
        graph[a].push_back(b);
        graph[b].push_back(a);

    }
    cin>>v;
    while(v--){
        cin>>a>>b;
        b=b+n;
        graph[a].push_back(b);
        graph[b].push_back(a);

    }
    for(i=1;i<=n+m;i++){
        visit[i]=0;
    }
    for(i=1;i<=n+m;i++){
        W[i]=0;
        M[i]=0;
    }

    c=0;
    for(i=1;i<=n+m;i++){
    if(!visit[i]){
        c++;
        k=0;
        l=0;
        dfs(graph,i);
        W[c]=k;
        M[c]=l;   
    }
    }
    ll ans=0;
    for(i=1;i<=c;i++){
        ans=ans+((n-M[i])*W[i]);
    }
    cout<<ans;
    return 0;
}