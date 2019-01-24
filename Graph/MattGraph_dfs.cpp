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
set<int>::iterator it;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
bool vis[100005];
vector<int> vec[100005];
void dfs(int x){
    for(int i=0;i<vec[x].size();i++){
        int y = vec[x][i];
        if(vis[y]==0){
            vis[y]=1;
            dfs(y);
        }
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    int node;
    cin>>node;
    vec[node].clear();
    vis[node]=1;
    vis[0]=1;
    dfs(0);
    bool flag = true;
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            flag=false;
        }
    }
    if(flag==true){
        cout<<"Connected";
    }
    else {
        cout<<"Not Connected";
    }
    return 0;
}