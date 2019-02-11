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
unordered_map<ll,ll> mp1,arr;
ll n,k;
ll root(ll x){
    while(arr[x] != x){
        arr[x] = arr[arr[x]];
        x = arr[x];
    }
    return x;
}
void uniwg(ll x,ll y){
    ll root_x = root(x);
    ll root_y = root(y);
    if(root_x  == root_y)
        return;
    if(mp1[root_x]>mp1[root_y]){
        arr[root_y] = root_x;
        mp1[root_x]+=mp1[root_y];
    }
    else {
        arr[root_x] = root_y;
        mp1[root_y]+=mp1[root_x];
    }
    
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>n>>k;
    ll  ct=n;
    for(ll i=0;i<k;i++){
        ll x,y;
        cin>>x>>y;
        if(mp1[x]==0){
            arr[x]=x;
            mp1[x]=1;
        }
        if(mp1[y]==0){
            arr[y]=y;
            mp1[y]=1;
        }
        if(root(x)!=root(y)){
        	ct--;
        }
        uniwg(x,y);
    }
    cout<<ct<<endl;
    return 0;
}