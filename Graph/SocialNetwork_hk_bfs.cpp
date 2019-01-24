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
int main() {
    int n,e;
    cin>>n>>e;
    vector <int> v[n+1];
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int quer;
    cin>>quer;
    while(quer--){
        vector<int> vec(n+1,-1); // intialize with -1
        queue <int> q;
        int a,t,ct=0;
        cin>>a>>t;
        vec[a]=0;
        q.push(a);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int i=0;i<v[x].size();i++){
                if(vec[v[x][i]]==-1){
                    vec[v[x][i]] = vec[x] + 1;
                    if(vec[v[x][i]] == t){
                        ct++;
                    }
                    q.push(v[x][i]);
                }
            }
        }
        cout<<ct<<endl;

    }
    return 0;
}