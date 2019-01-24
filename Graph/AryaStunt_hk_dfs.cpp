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
bool vis[10005];
int val[10005];
ll sum=0,mxm=0,id=-1;
vector<int> v[10005];
void dfs(int x){
    for(int i=0;i<v[x].size();i++){
        int y = v[x][i];
        if(vis[y]==0){
            sum+=val[y];
            if(mxm<val[y]){
                mxm=val[y];
                id=y;
            }
            if(mxm==val[y] && id>y){
                id=y;
            }
            vis[y]=1;
            dfs(y);
        }
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    ll kill=0,inj=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            sum=val[i];
            mxm=val[i];
            id=i;
            vis[i]=1;
            dfs(i);
            s1.insert(id);
            kill += mxm;
            inj += (sum-mxm);
        }
    }
    cout<<kill<<' '<<inj<<endl;
    for(it=s1.begin();it!=s1.end();++it){
        cout<<*it<<' ';
    }
    return 0;
}