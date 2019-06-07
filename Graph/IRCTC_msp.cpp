/**************erik****************/
// Start dijk from intermediate station
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
vector<pair<ll,int> > vec[MAX];
int dist[MAX];
bool vis[MAX];
int parent[MAX];
stack<int> q;

void dijkstra(int source){            
    dist[source] = 0;
    multiset < pair < int , int > > s;       
    s.insert({0 , source});                         
    while(!s.empty()){
        pair <int , int> p = *s.begin();        
        s.erase(s.begin());
        int x = p.second; 
        if( vis[x] ) continue;                  
        vis[x] = true;
        for(int i = 0; i < vec[x].size(); i++){
            int e = vec[x][i].second;
            int w = vec[x][i].first;
            if(dist[x] + w < dist[e]  ){   
                parent[e]=x;         
                dist[e] = dist[x] + w;
                s.insert({dist[e],  e} );           
            }
        }
    }
}
void par_chk(int source,int dest){
    if(parent[dest]!=source){
        q.push(parent[dest]);
        par_chk(source,parent[dest]);
    }
}
int main() {
    int t;
    cin>>t;
    while(t--){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        dist[i]=1e9;
        vis[i]=0;
        vec[i].clear();
    }
    for(int i=0;i<k;i++){
        int x,y;
        int wgt;
        cin>>x>>y>>wgt;
        vec[x].push_back({wgt,y});
        vec[y].push_back({wgt,x});
    }
    int so,de,inter;
    cin>>so>>inter>>de;
    dijkstra(inter);
    if(dist[so]!=1e9 && dist[de]!=1e9){
        cout<<dist[so]+dist[de]<<endl;
        par_chk(so,de);
        cout<<dist[de]<<endl;
        cout<<so<<' ';
        while(!q.empty()){
            cout<<q.top()<<' ';
            q.pop();
        }
        printf("%d\n",de);
    }
    else {
           cout<<"No Train Found."<<endl;
        }
    }
    return 0;

}