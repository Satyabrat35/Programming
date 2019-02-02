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
const int MAX = 10005;
int arr[MAX];
int val[MAX][MAX];
int parent[MAX];
pair<int,pair<int,int>> p[MAX];
pair<int,int> sp[MAX];
vector<int> vec[MAX];
bool vis[MAX];
queue<int> q;
int n,m,start,dest,value,ct=0;
void initialize(int n){
    for(int i=1;i<=n;i++){
        arr[i]=i;
    }
}
void dfs(int x){
    vis[x]=1;
    for(int i=0;i<vec[x].size();i++){
        if(vis[vec[x][i]]==0){
            parent[vec[x][i]]=x;
            dfs(vec[x][i]);
        }
    }
}
void par_chk(int source,int dest){
    if(parent[dest]!=source){
        int zz = parent[dest];
        sp[ct] = make_pair(zz,val[zz][dest]);
        ct++;
        par_chk(source,zz);
    }
}
int root(int x){
    while(arr[x] != x){
        arr[x] = arr[arr[x]];
        x = arr[x];
    }
    return x;
}
bool find(int x,int y){
    if(root(x)==root(y))
        return true;
    else
        return false;
}
void uniwg(int x,int y){
    int root_x = root(x);
    int root_y = root(y);
    
    arr[root_x] = arr[root_y];
    
}
void kruskal(){
    int x,y;
    for(int i=0;i<m;i++){
        x = p[i].second.first;
        y = p[i].second.second;
        if(root(x)!=root(y)){
            vec[x].push_back(y);
            vec[y].push_back(x);
            val[x][y] = p[i].first;
            val[y][x] = p[i].first;
            uniwg(x,y);
        }
    }
}
int main() {
    cin>>n>>m;
    initialize(n);
    memset(vis,0,sizeof(vis));
    for(int i=0;i<m;i++){
        int x,y,wgt;
        cin>>x>>y>>wgt;
        p[i] = make_pair(wgt,make_pair(x,y));
    }
    sort(p,p+m);
    reverse(p,p+m);
    kruskal();
    cin>>start>>dest>>value;
    vis[start]=0;
    dfs(start);
    par_chk(start,dest);
    int mn = 1e9;
    cout<<start<<" ";
    for(int i=ct-1;i>=0;i--){
        int stop1 = sp[i].first;
        int valz = sp[i].second;
        mn = min(valz,mn);
        cout<<stop1<<" ";
    }
    cout<<dest<<endl;
    mn--;
    float qz = (float)value / (float)mn;
    cout<<ceil(qz);
    return 0;
}