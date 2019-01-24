/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
map<int,int> mp1;
//set<int> s1;
//set<int>::iterator it;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
vector<int> vec[1005];
int risk[1005];
bool vis[1005];
int mxm = 1007;
void dfs(int x){
    vis[x]=1;
    if(mxm>=risk[x]){
        mxm = risk[x];
        mp1[mxm]++;
    }
    for(int i=0;i<vec[x].size();i++){
        if(vis[vec[x][i]]==0){
            dfs(vec[x][i]);
        }
    }
}
int main() {
    int n,q;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>risk[i];
    }
    cin>>q;
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    memset(vis,0,sizeof(vis));
    ll ans = 1;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            mp1.clear();
            mxm = 1007;
            dfs(i);
            ans = ans * mp1[mxm];
            ans = ans%1000000007;
            //cout<<i<<' '<<mxm<<' '<<mp1[mxm]<<endl;
        }
    }
    cout<<ans%1000000007<<endl;
    return 0;
}