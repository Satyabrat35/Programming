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
const int MAX = 1005;
const ll MOD = 1e9 + 7;
int arr[MAX][MAX];
bool vis[MAX];
vector<int> vec[MAX];
/*void initialize(){
    for(int i=1;i<=MAX;i++){
        arr[i]=i;
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
void kruskal(pair<ll,pair<int,int>> p[]){
    int x,y;
    ll cost,minCost=0;
    for(int i=0;i<m;i++){
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x)!=root(y)){
            sp.insert(make_pair(x,y));
            sp.insert(make_pair(y,x));
            uniwg(x,y);
        }
    }
}*/
void initialize(){
    for(int i=0;i<MAX;i++){
        vis[i] = 0;
        vec[i].clear();
    }
}
void dfs(int x,int cost){
    vis[x]=1;
    for(int i=0;i<vec[x].size();i++){
        int p = vec[x][i];
        if(vis[p]==0 && arr[x][p]<cost){
            dfs(p,cost);
        }
    }
}
int main() {
    int t;
    cin>>t;
    while(t--){
    int n,m,q,no=0;
    initialize();
    memset(arr,0x3f,sizeof(arr));
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,wgt;
        cin>>x>>y>>wgt;
        vec[x].push_back(y);
        vec[y].push_back(x);
        arr[x][y] = wgt;
        arr[y][x] = wgt;
    }
    cin>>q;
    for(int i=0;i<q;i++){
        int p,z;
        cin>>p>>z;
        dfs(p,arr[p][z]);
        if(vis[z]==1){
            no++;
    }
    memset(vis,0,sizeof(vis));
    }
    int yes = q - no;
    int temp = __gcd(yes,q);
    cout<<yes/temp<<'/'<<q/temp<<endl;
    }
    return 0;
}