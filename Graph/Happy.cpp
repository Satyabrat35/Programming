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
    int n,m;
    cin>>n>>m;
    vector<int> vec[n+1];
    vector<int> root(n+1,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        vec[x].push_back(y);
        //mp1[y]=x;
        vec[y].push_back(x);
    }
    bool vis[n+1];
    memset(vis,0,sizeof(vis));
    stack<int> s;
    s.push(1);
    vis[1]=1;
    while(!s.empty()){
        int x=s.top();
        s.pop();
        for(int i=0;i<vec[x].size();i++){
            if(vis[vec[x][i]]==0){
                mp1[vec[x][i]] = x;
                vis[vec[x][i]]=1;
                root[x]++;
                s.push(vec[x][i]);
            }
        }
    }
    int cal=0;
    for(int i=2;i<=n;i++){
        int x = mp1[i];
        if(root[i]>root[x])
            cal++;
    }
        cout<<cal;
    return 0;
}