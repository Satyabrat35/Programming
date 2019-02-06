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
const int MAX = 100005;
vector<pair<int,int> > vec[MAX];
ll dist[MAX];
bool vis[MAX];
void dijkstra(int source){            
    dist[source] = 0;
    multiset < pair < ll , int > > s;       
    s.insert({0 , source});                         
    while(!s.empty()){
        pair <ll , int> p = *s.begin();        
        s.erase(s.begin());
        int x = p.second; 
        // if( vis[x] ) continue;                  
        // vis[x] = true;
        for(int i = 0; i < vec[x].size(); i++){
            int e = vec[x][i].second;
            int w = vec[x][i].first;
            if(w==1){
                if(dist[x]%2==0 && dist[e]>dist[x]+1){
                    dist[e] = dist[x]+2; //if wgt is odd but arrival time is even
                    s.insert({dist[e],e});
                }
                else if(dist[x]%2!=0 && dist[e]>dist[x]+1){
                    dist[e] = dist[x]+1;
                    s.insert({dist[e],e});
                }
            }
            else if(w==0){
                if(dist[x]%2==0 && dist[e]>dist[x]+1){
                    dist[e] = dist[x]+1;
                    s.insert({dist[e],e});
                }
                else if(dist[x]%2!=0 && dist[e]>dist[x]+1){
                    dist[e] = dist[x]+2; // if wgt is even but arrival time is odd
                    s.insert({dist[e],e});
                }
            }
        }
    }
}

/*void dfs(int x,ll timed,int n){
    vis[x]=1;
    tot = timed;
    if(vis[n]){
        //cout<<x<<"*"<<timed+1<<endl;
        return;
    }
    if(timed%2==0){
        if(vec[x][0].size()!=0){
            bool f = true;
        for(int i=0;i<vec[x][0].size();i++){
            int y = vec[x][0][i];
            if(vis[y]==0){
                f = false;
                //cout<<y<<'*'<<timed+1<<endl;
                dfs(y,timed+1,n);
            }
        }
        if(f){
            //cout<<x<<"*"<<timed+1<<endl;
            dfs(x,timed+1,n);
        }
        }
        else {
            //cout<<x<<"*"<<timed+1<<endl;
            dfs(x,timed+1,n);
        }
    }
    else {
        if(vec[x][1].size()!=0){
            bool f = true;
        for(int i=0;i<vec[x][1].size();i++){
            int y = vec[x][1][i];
            if(vis[y]==0){
                f = false;
                //cout<<y<<' '<<timed+1<<endl;
                dfs(y,timed+1,n);
            }   
        }
        //cout<<x<<"*"<<timed+1<<endl;
            dfs(x,timed+1,n);
        }
        else {
            //cout<<x<<"*"<<timed+1<<endl;
            dfs(x,timed+1,n);
        }
    }
}*/
int main() {
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        vec[x].push_back({0,y});
        vec[y].push_back({1,x});
    }
    for(int i=1;i<=n+1;i++){
        dist[i]=1e12;
        vec[i].clear();
    }
    dist[1]=0;
    dijkstra(1);
    cout<<dist[n]<<endl;
    for(int i=0;i<q;i++){
        ll tt;
        cin>>tt;
        if(tt<dist[n]){
            cout<<"FML"<<endl;
        }
        else {
            cout<<"GGMU"<<endl;
        }
    }
    //cout<<tot;
return 0;
}