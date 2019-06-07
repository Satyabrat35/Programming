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
const ll MOD = 1e9 + 7;
int arr[MAX];
//pair<ll,pair<int,int>> p[31320];
int n,m,q;
void initialize(){
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
ll kruskal(pair<ll,pair<int,int>> p[]){
    int x,y;
    ll cost,minCost=1;
    for(int i=0;i<m;i++){
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x)!=root(y)){
            minCost = (cost*minCost)%MOD;
            minCost = minCost%MOD;
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
    initialize();
    pair<ll,pair<int,int>> p[m+1];
    int x,y;
    ll wgt;
    for(int i=0;i<m;i++){
        cin>>x>>y>>wgt;
        p[i] = make_pair(wgt,make_pair(x,y));
    }
    sort(p,p+m);
    ll minCost = kruskal(p);
    cout<<minCost%MOD<<endl;
    }
    return 0;
}