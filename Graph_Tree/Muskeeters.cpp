/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
//map<int,int> mp1;
//set<int> s1;
//set<int>::iterator it;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
vector<int> vec[4005];
bool vis[4005][4005];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
        vis[x][y]=true;
        vis[y][x]=true;
    }
    ll ans = 1e6;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(vis[i][j]){
                for(int k=j+1;k<=n;k++){
                    if(vis[i][k] && vis[j][k]){
                        ll x = vec[i].size() + vec[j].size() + vec[k].size() - 6;
                        ans = min(x,ans);
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}