/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
//map<ll,ll> mp1;
set<int> s1;
//set<int>::iterator it;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int arr[100005];
int sz[100005];
bool mark[100005];
int n,k;
void initialize(int n){
    for(int i=1;i<=n;i++){
        arr[i]=i;
        sz[i]=1;
        mark[i]=false;
    }
}
int root(int x){
    while(arr[x] != x){
        //arr[x] = arr[arr[x]];
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
    if(root_x  == root_y)
        return;
    if(sz[root_x]>sz[root_y]){
        arr[root_y] = root_x;
        sz[root_x]+=sz[root_y];
    }
    else {
        arr[root_x] = root_y;
        sz[root_y]+=sz[root_x];
    }
}
int main() {
    cin>>n>>k;
    initialize(n);
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        uniwg(x,y);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        if(!find(x,y)){
            continue;
        }
        else {
            int z = root(x);
            if(s1.count(x)==0){
                s1.insert(x);
                sz[z]--;
            }
            if(s1.count(y)==0){
                s1.insert(y);
                sz[z]--;
            }
            mark[x]=true;
        }
    }
    int mxm = 0;
    for(int i=1;i<=n;i++){
        int z = root(i);
        if(mark[z]==false){
            mxm = max(mxm,sz[z]);
        }
    }
    cout<<mxm;
    return 0;
}   