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
int arr[100005];
int sz[100005];
int n,k;
void initialize(int n){
    for(int i=1;i<=n;i++){
        arr[i]=i;
        sz[i]=1;
    }
}
int root(int x){
    while(arr[x] != x){
        //arr[x] = arr[arr[x]];
        x = arr[x];
    }
    return x;
}
void uniwg(int x,int y){
    int root_x = root(x);
    int root_y = root(y);
    if(root_x  == root_y)
        return;
    if(sz[root_x]>sz[root_y]){
        arr[root_y] = root_x;
        sz[root_x]+=sz[root_y];
        //cout<<x<<' '<<arr[root_x]<<' '<<sz[root_x]<<endl;
        //cout<<y<<' '<<arr[root_y]<<' '<<sz[root_y]<<endl;
    }
    else {
        arr[root_x] = root_y;
        sz[root_y]+=sz[root_x];
        //cout<<x<<' '<<arr[root_x]<<' '<<sz[root_x]<<endl;
        //cout<<y<<' '<<arr[root_y]<<' '<<sz[root_y]<<endl;
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
    /*for(int i=1;i<=n;i++){
        s1.insert(arr[i]);
        mp1[arr[i]]++;
    }*/
    ll val = 1,mod = 1e9+7;
    for(int i=1;i<=n;i++){
    	if(arr[i]==i){
        	val =(val%mod)*(sz[i]%mod)%mod;
    	}
    }
    cout<<val%mod;
    return 0;
}