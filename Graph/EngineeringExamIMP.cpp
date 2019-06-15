/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
//map<int,int> mp1;
set<int> s1;
//set<int>::iterator it;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
const int MAX = 100005;
vector<pair<ll,int> > vec[MAX];
ll dist[MAX];

void dijkstra(int n){
    //memset(vis, false , sizeof vis);
    for(int i=0;i<=n+1;i++){
        dist[i]=1e9+7;
    }  
    multiset < pair < ll , int > > s;       
    for(auto it=s1.begin();it!=s1.end();++it){
        dist[*it]=0;
        s.insert(make_pair(0,*it));
    }                        
    while(!s.empty()){
        pair <ll , int> p = *s.begin();        
        s.erase(s.begin());
        int x = p.second;
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
int main() {
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    for(int i=0;i<m;i++){
        int x,y;
        ll wgt;
        cin>>x>>y>>wgt;
        vec[x].push_back(make_pair(wgt,y));
        vec[y].push_back(make_pair(wgt,x));
    }
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        s1.insert(x);
    }
    dijkstra(n);
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        if(s1.count(x)){
            cout<<"0"<<endl;
        }
        else {
            if(dist[x]==1e9+7){
                cout<<"-1"<<endl;
            }
            else {
                cout<<dist[x]<<endl;
            }
            
        }
    }
    return 0;
}