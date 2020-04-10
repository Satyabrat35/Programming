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
int main()
{
    int n;
    cin>>n;
    vector<ll> vec(n+1,0);
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        vec[i+1]=vec[i]+a[i];
    }
    set<ll> ss={0};
    int a1=0;int b1=0;
    ll ct = 0;
    while(a1<n){
        while(b1<n && !ss.count(vec[b1+1])){
            b1+=1;
            ss.insert(vec[b1]);
        }
        //cout<<a1<<' '<<b1;
        ct+=b1-a1;
        ss.erase(vec[a1]);
        a1+=1;
    }
    //cout<<endl;
    cout<<ct<<endl;
    return 0;
}