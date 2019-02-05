/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
//map<int,int> mp1;
set<int> s1;
//set<int>::iterator it;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
queue<pair<ll,ll>> q;
bool vis[1000005];
int main() {
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;
    q.push({s,0});
    memset(vis,0,sizeof(vis));
    vis[s]=1;
    while(!q.empty()){
        ll flo = q.front().first;
        ll level = q.front().second;
        q.pop();
        if(flo == g){
            cout<<level<<endl;
            return 0;
        }
        if(flo+u<=f){
            if(vis[flo+u]==0){
                vis[flo+u]=1;
                q.push({flo+u,1+level});
            }
        }
        if(flo-d>0){
            if(vis[flo-d]==0){
                vis[flo-d]=1;
                q.push({flo-d,1+level});
            }
        }
    }
    cout<<"use the stairs"<<endl;
    return 0;
}