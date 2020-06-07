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
#define f(i,n)  for(ll i=0;i<n;i++)
#define rf(i,n) for(ll i=n-1;i>=0;i--)

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    int n,m;
    cin>>n>>m;
    int h[n];
    f(i,n)cin>>h[i];
    vector<int> vec[n+2];
    set<pair<int,int>> ss;
    f(i,m){
        int a,b;
        cin>>a>>b;
        a-=1;
        b-=1;
        if(ss.find({min(a,b),max(a,b)})!=ss.end())continue;
        ss.insert({min(a,b),max(a,b)});
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    int ct=0;
    f(i,n){
        if(vec[i].size()==0)ct++;
        else {
            bool f = true;
            for(int j=0;j<vec[i].size();j++){
                if(h[i]<=h[vec[i][j]]){f=false;break;}
            }
            if(f){ct++;}
        }
    }
    cout<<ct<<endl;

}