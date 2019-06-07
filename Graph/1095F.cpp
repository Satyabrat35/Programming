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
ll ans=0;
int n;
void initialize(int n){
    for(int i=1;i<=n;i++){
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
void kruskal(int zz){
    int x,y;
    for(int i=0;i<zz;i++){
        x = p[i].second.first;
        y = p[i].second.second;
        if(root(x)!=root(y)){
            ans+=p[i].first;
            uniwg(x,y);
        }
    }
}
int main() {
    int k;
    cin>>n>>k;
    initialize(n);
    ll arr[n+1];
    ll wggt[n+1][n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    set<pair<int,int>> sp;
    for(int i=0;i<k;i++){
        int x,y;
        ll wgt;
        cin>>x>>y>>wgt;
        if(sp.count({min(x,y),max(x,y)})!=0){
            if(wggt[min(x,y)][max(x,y)] > wgt){
                wggt[min(x,y)][max(x,y)]=wgt;
            }
        }
        sp.insert({min(x,y),max(x,y)});
        wggt[min(x,y)][max(x,y)]=wgt;
    }
    int zz=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(sp.count({i,j})!=0){
                if(wggt[i][j] < arr[i]+arr[j]){
                    p[zz] = make_pair(wggt[i][j],make_pair(i,j));
                    zz++;
                }
                else {
                    p[zz] = make_pair(arr[i] + arr[j],make_pair(i,j));
                    zz++;
                }
            }
            else {
                p[zz] = make_pair(arr[i] + arr[j],make_pair(i,j));
                zz++;
            }
        }
    }
    sort(p,p+zz);
    kruskal(zz);
    cout<<ans<<endl;
    return 0;
}