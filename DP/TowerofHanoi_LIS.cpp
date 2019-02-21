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
bool ateallmybeans(pair<ll,ll> &a,pair<ll,ll> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}
ll lis(int n,pair<ll,ll> p[]){
    ll list[n];
    ll mxmx=0;
    for(int i=0;i<n;i++){
        list[i] = p[i].second;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(p[i].second > p[j].second && p[i].first > p[j].first){
                ll x = p[i].second;
                if(list[i]<x+list[j]){
                    list[i]=x+list[j];
                }
            }
        }
        if(mxmx<list[i]){
            mxmx = list[i];
        }
    }
    return mxmx;
}
int main() {
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    pair<ll,ll> p[n];
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        p[i].first = x;
        p[i].second = y;
    }
    sort(p,p+n,ateallmybeans);
    /*for(int i=0;i<n;i++){
        cout<<p[i].first<<' '<<p[i].second<<endl;
    }*/
    cout<<lis(n,p)<<endl;
    }
    return 0;
}