/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
map<int,int> mp1;
set<int> s1;
//set<int>::iterator it;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
const int MAX = 1000005;
vector<pair<int,int> > vec[MAX];
int dist[MAX],dist2[MAX];
bool vis[MAX];
void init(int n){
    for(int i=0;i<=n;i++){
        dist[i]=1e7;
        vis[i]=0;
        dist2[i]=1e7;
    }
}
void dijkstra(int source,int exp_time){
    //memset(vis, false , sizeof vis);            
    dist[source] = 0;
    multiset < pair < int , int > > s;       
    s.insert({0 , source});                         
    while(!s.empty()){
        pair <int , int> p = *s.begin();        
        s.erase(s.begin());
        int x = p.second; 
        int wei = p.first;
        if( vis[x] ) continue;                  
         vis[x] = true;
        for(int i = 0; i < vec[x].size(); i++){
            int e = vec[x][i].second;
            int w = vec[x][i].first;
            if(dist[x] + w < dist[e]  ){            
                dist[e] = dist[x] + w;
                if(dist[e]<=exp_time){
                    if(s1.count(e)){
                        mp1[e]++;
                    }
                }
                s.insert({dist[e],  e} );           
            }
        }
    }
}
void dijkstra2(int source){
    memset(vis, false , sizeof vis);            
    dist2[source] = 0;
    multiset < pair < int , int > > s;       
    s.insert({0 , source});                         
    while(!s.empty()){
        pair <int , int> p = *s.begin();        
        s.erase(s.begin());
        int x = p.second; 
        int wei = p.first;
        if( vis[x] ) continue;                  
         vis[x] = true;
        for(int i = 0; i < vec[x].size(); i++){
            int e = vec[x][i].second;
            int w = vec[x][i].first;
            if(dist2[x] + w < dist2[e] ){            
                dist2[e] = dist2[x] + w;
                s.insert({dist2[e],  e} );           
            }
        }
    }
}
int main() {
    int n,m,k,exp_time;
    cin>>n>>m>>k>>exp_time;
    init(n);
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        s1.insert(x);
    }
    for(int i=0;i<m;i++){
        int x,y,wgt;
        cin>>x>>y>>wgt;
        vec[x].push_back({wgt,y});
        vec[y].push_back({wgt,x});
    }
    int my_house,fraand;
    cin>>fraand>>my_house;
    dijkstra(my_house,exp_time);
    if(dist[fraand]==1e7){
        cout<<"-1";
        return 0;
    }
    dijkstra2(fraand);
    int mn = 1e7;
    for(auto it=s1.begin();it!=s1.end();it++){
        if(mp1[*it]!=0 && dist2[*it]!=1e7){
            mn = min(dist[*it] + dist2[*it],mn);
        }
    }
    if(mn ==1e7){
        cout<<"-1";
    }
    else {
        cout<<mn;
    }
    return 0;

}