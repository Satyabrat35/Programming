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
int vis[100001];
ll val[100001];
int ans1=100001;
ll source_val=0,source;
vector<int> v[100001];
void dfs(int x,ll sum,int ct){
    if(vis[x]){
        return;
    }
    vis[x]=1;
    if(sum >= source_val)
    {
        ans1 = min(ans1,ct);
    }
    
    for(int i=0;i<v[x].size();i++){
        int p = v[x][i];
        if(vis[p] == 0){
            dfs(p,sum+val[p],ct+1);
        }
    }
}
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    while(q--){
        cin>>source>>source_val;
        dfs(source,val[source],1);
        if(ans1==100001)
            ans1=-1;
        cout<<ans1<<endl;
        ans1=100001;
        memset(vis,0,sizeof(vis));
    }
    return 0;
}