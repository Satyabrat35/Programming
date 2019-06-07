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
const int MAX = 100005;
vector<pair<int,pair<int,ll>> > vec[MAX];
vector<pair<ll,ll> > dist;
int st=0;
int parent[MAX];
bool vis[MAX];
void par_chk(int source,int dest){
    if(parent[dest]!=source){
        st++;
        cout<<parent[dest]<<"->";
        par_chk(source,parent[dest]);
    }
}
void dijkstra(int source,int dest,int k){
    memset(vis,0,sizeof(vis));
    dist[source].first = 0;
    multiset<pair<int,int> > s;
    s.insert({0,source});
    parent[source]=0;
    while(!s.empty()){
        pair<int,int> p = *(s.begin());
        s.erase(s.begin());
        int x = p.second;
        /*if(x == dest){
            return;
        }*/
        if(vis[x]){
            continue;
        }
        vis[x]=1;
        for(int i=0;i<vec[x].size();i++){
            int e = vec[x][i].first;
            int wt = vec[x][i].second.second;
            int tm = vec[x][i].second.first;
            if(dist[x].first + wt <dist[e].first){
                dist[e].first = dist[x].first + wt;
                parent[e]=x;
                dist[e].second = dist[x].second + tm;
                s.insert({dist[e].first,e});
            }
            else if(dist[x].first + wt == dist[e].first){
                if(dist[e].second<tm){
                   dist[e].second = tm; 
                }
            }
        }
    }
}
int main() {
    int n,m,k;
    cin>>k>>n>>m;
    if(m > n*(n-1)/2){
        cout<<"Error";
        return 0;
    }
    for(int i=0;i<=n+1;i++){
        dist.push_back({1e9,0});
    }
    for(int i=0;i<m;i++){
        int so,de,t,cost;
        cin>>so>>de>>t>>cost;
        ll wgt = t*k + cost;
        vec[so].push_back({de,{t,wgt}});
        vec[de].push_back({so,{t,wgt}});
    }
    int so,de;
    cin>>so>>de;
    if(so>n || so<1 || de>n || de<1){
        cout<<"Error";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
	    for(ll j=0;j<vec[i].size();j++)
	    {
	        if(i!=so and vec[i][j].first!=so)
	        {
	            vec[i][j].second.first++;
	            vec[i][j].second.second+=k;
	        
	        }
	    
	    }
	}
    dijkstra(so,de,k);
    if(dist[de].first==1e9){
        cout<<"Error";
        return 0;
    }
    cout<<so<<"->";
    par_chk(so,de);
    cout<<de<<' '<<st+2<<' ';
    cout<<dist[de].first;
    
    return 0;
}