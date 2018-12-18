/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
 typedef long long  int ll;
 typedef unsigned long long int ull;
map<int,int> mp1;
//set<int> s1,s2;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> v[n];
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v[x].push_back(i);
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        if(v[x].size() > v[y].size()){
            for(int i=0;i<v[y].size();i++){
                int lo=v[x].begin();
                int up=v[x].end();
            }
        }
    }
}