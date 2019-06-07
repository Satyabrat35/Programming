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
int arr[MAX],sz[MAX];
//pair<ll,pair<int,int>> p[MAX];
int n,m,q;
void initialize(){
    for(int i=1;i<=MAX;i++){
        arr[i]=i;
        sz[i]=0;
    }
}
int root(int x){
    while(arr[x] != x){
        arr[x] = arr[arr[x]];
        x = arr[x];
    }
    return x;
}
bool ateallmybeans(pair<ll ,pair<int,int>> &a,pair<ll,pair<int,int>> &b){
    if(a.first == b.first){
        if(a.second.first == b.second.first){
            return a.second.second >= b.second.second;
        }
        else {
            return a.second.first > b.second.first;
        }
    }
    return a.first < b.first;
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
ll kruskal(pair<ll,pair<int,int>> p[]){
    int x,y;
    ll cost,minCost=0;
    for(int i=0;i<m;i++){
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x)!=root(y)){
            minCost+=cost;
            sz[x]++;
            sz[y]++;
            uniwg(x,y);
        }
    }
    return minCost;
}
int main() {
    int t;
    cin>>t;
    while(t--){
    cin>>n>>m;
    pair<ll,pair<int,int>> p[m+1];
    initialize();
    for(int i=0;i<m;i++){
        int x,y,c,d;
        ll wgt;
        cin>>x>>y>>wgt;
        c = min(x,y);
        d = max(x,y);
        p[i] = make_pair(wgt,make_pair(c,d));
    }
    sort(p,p+m,ateallmybeans);
    // for(int i=0;i<m;i++){
    //     cout<<p[i].first<<' '<<p[i].second.first<<' '<<p[i].second.second<<endl;
    // }
    ll minCost = kruskal(p);
    cout<<minCost<<endl;
    for(int i=1;i<=n;i++){
        cout<<sz[i]<<' ';
    }
    cout<<endl;
    }
    return 0;
}