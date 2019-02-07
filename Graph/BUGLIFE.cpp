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
const int MAX = 1000005;
int main() {
    int t;
    cin>>t;
    int ct=0;
    while(t--){
    ct++;
    int n,m;
    cin>>n>>m;
    vector<int> vec[n+1];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    int lev[n+1];
    bool vis[n+1];
    for(int i=1;i<=n;i++){
        lev[i]=-1;
        vis[i]=0;
    }
    bool f=true;
    for(int j=1;j<=n;j++){
    if(!vis[j]){
        queue<int> q;
        q.push(j);
        lev[j]=1;
        while(!q.empty()){
            int a = q.front();
            q.pop();
            vis[a]=1;
            for(int i=0;i<vec[a].size();i++){
                int y = vec[a][i];
                if(lev[y]==-1){
                    lev[y]=!lev[a];
                }
                else if(lev[y]==lev[a]){
                    f = false;
                    break;
                }
                if(!vis[y]){
                    q.push(y);
                }
            }
            if(!f){
                break;
            }
    }
    }
    }
    cout<<"Scenario #"<<ct<<':'<<endl;
    if(f){
        cout<<"No suspicious bugs found!"<<endl;
    }
    else {
        cout<<"Suspicious bugs found!"<<endl;
    }
    }
    return 0;
}