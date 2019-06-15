/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
//set<int> s1;
//set<int>::iterator it;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
const int MAX = 100005;
int arr[100005];
int sz[100005];
set<pair<int,int>> s1;
int n,k;
void initialize(int n){
    for(int i=1;i<=n;i++){
        arr[i]=i;
        sz[i]=1;
        s1.insert({sz[i],i});
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
        s1.erase({sz[root_x],root_x});
        s1.erase({sz[root_y],root_y});
        arr[root_y] = root_x;
        sz[root_x]+=sz[root_y];
        s1.insert({sz[root_x],root_x});
    }
    else {
        s1.erase({sz[root_x],root_x});
        s1.erase({sz[root_y],root_y});
        arr[root_x] = root_y;
        sz[root_y]+=sz[root_x];
        s1.insert({sz[root_y],root_y});
    }
}
int main() {
    cin>>n>>k;
    initialize(n);
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        uniwg(x,y);
        auto it = s1.end();
        --it;
        auto ti = s1.begin();
        cout<<(*it).first - (*ti).first<<endl;
    }
    return 0;
}