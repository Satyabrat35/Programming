/**************erik****************/
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
const int MAX = 100005;
vector<pair<ll,int> > vec[MAX],vecd[MAX];
ll dist[MAX],dist2[MAX],dist3[MAX],dist4[MAX];
bool vis[MAX];

void initialize(int n){
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
}
void dijkstra(int source){
    memset(vis, false , sizeof vis);            
    dist[source] = 0;
    multiset < pair < ll , int > > s;       
    s.insert({0 , source});                         
    while(!s.empty()){
        pair <ll , int> p = *s.begin();        
        s.erase(s.begin());
        int x = p.second; 
        if( vis[x] ) continue;                  
         vis[x] = true;
        for(int i = 0; i < vec[x].size(); i++){
            int e = vec[x][i].second;
            ll w = vec[x][i].first;
            if(dist[x] + w < dist[e]  ){            
                dist[e] = dist[x] + w;
                s.insert({dist[e],  e} );           
            }
        }
    }
}
void dijkstra2(int source){
    memset(vis, false , sizeof vis);            
    dist2[source] = 0;
    multiset < pair < ll , int > > s;       
    s.insert({0 , source});                         
    while(!s.empty()){
        pair <ll , int> p = *s.begin();        
        s.erase(s.begin());
        int x = p.second; 
        //int wei = p.first;
        if( vis[x] ) continue;                  
         vis[x] = true;
        for(int i = 0; i < vecd[x].size(); i++){
            int e = vecd[x][i].second;
            ll w = vecd[x][i].first;
            if(dist2[x] + w < dist2[e] ){            
                dist2[e] = dist2[x] + w;
                s.insert({dist2[e],  e} );           
            }
        }
    }
}
void dijkstra3(int source){
    memset(vis, false , sizeof vis);            
    dist3[source] = 0;
    multiset < pair < ll , int > > s;       
    s.insert({0 , source});                         
    while(!s.empty()){
        pair <ll , int> p = *s.begin();        
        s.erase(s.begin());
        int x = p.second; 
        //int wei = p.first;
        if( vis[x] ) continue;                  
         vis[x] = true;
        for(int i = 0; i < vec[x].size(); i++){
            int e = vec[x][i].second;
            ll w = vec[x][i].first;
            if(dist3[x] + w < dist3[e]  ){            
                dist3[e] = dist3[x] + w;
                s.insert({dist3[e],  e} );           
            }
        }
    }
}
void dijkstra4(int source){
    memset(vis, false , sizeof vis);            
    dist4[source] = 0;
    multiset < pair < ll , int > > s;       
    s.insert({0 , source});                         
    while(!s.empty()){
        pair <int , int> p = *s.begin();        
        s.erase(s.begin());
        int x = p.second; 
        if( vis[x] ) continue;                  
         vis[x] = true;
        for(int i = 0; i < vecd[x].size(); i++){
            int e = vecd[x][i].second;
            ll w = vecd[x][i].first;
            if(dist4[x] + w < dist4[e] ){            
                dist4[e] = dist4[x] + w;
                s.insert({dist4[e],  e} );           
            }
        }
    }
}
int main() {
    int n,m,source,dest;
    cin>>n>>m>>source>>dest;
    for(int i=1;i<=n+2;i++){
        vis[i]=0;
        dist[i]=1e9;
        dist2[i]=1e9;
        dist3[i]=1e9;
        dist4[i]=1e9;
    }

    for(int i=0;i<m;i++){
        int x,y;
        ll wgt;
        cin>>x>>y>>wgt;
        vec[x].push_back(make_pair(wgt,y));
        vecd[y].push_back(make_pair(wgt,x));
    }
    dijkstra(source);
    dijkstra2(dest);
    dijkstra3(dest);
    dijkstra4(source);

    ll mn = 1e9;
    for(int i=1;i<=n;i++){
        if(i!=source && i!=dest){
            //cout<<i<<' '<<dist[source]<<' '<<dist4[source]<<' '<<dist2[dest]<<' '<<dist3[dest]<<endl;
            mn = min(mn, dist[i] + dist4[i] + dist2[i] + dist3[i]);
        }
    }
    if(mn == 1e9){
        cout<<"-1";
    }
    else {
        cout<<mn;
    }
    return 0;
}

