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
const int MAX = 200005;
int arr[MAX];
pair<ll,pair<int,int>> p[MAX];
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
    ll cost,minCost=0;
    for(int i=0;i<m;i++){
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x)!=root(y)){
            minCost+=cost;
            uniwg(x,y);
        }
    }
    return minCost;
}
int main() {
    cin>>q;
    while(q--){
    cin>>n>>m;
    pair<ll,pair<int,int>> p[MAX];
    initialize();
    ll sum=0;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        p[i] = make_pair(abs(y-x),make_pair(x,y));
        sum+=abs(x-y);
    }
    sort(p,p+m);
    reverse(p,p+m);
    ll minCost = kruskal(p);
    ll cnt = 0;
    for(int i=1;i<=n;i++){
    	if(arr[i]==i){
    		cnt++;
    	}
    }
    cout<<sum-minCost+cnt-1<<endl;
    }
    return 0;
}