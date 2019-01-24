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
vector<int> v[100005];
bool vis[100005];
int ed, ver,f_ed=0,f_ver=0;
float mxm=0;
void dfs(int x){
    vis[x]=1;
    ed+=v[x].size();
    ver+=1;
    for(int i=0;i<v[x].size();i++){
        if(vis[v[x][i]]==0){
            dfs(v[x][i]);
        }
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bool grt = false;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            ed=0;ver=0;
            dfs(i);
            float a,b;
            a=ed/2;b=ver;
            if(mxm < float(a/b)){
                f_ed = ed/2;
                f_ver = ver;
                mxm = float(a/b);
                if(mxm>float(1)){
                    grt = true;
                }
            }
            //cout<<i<<' '<<ed/2<<' '<<ver<<endl;
        }
    }
    if(m==0){
        cout<<"0/1";
        return 0;
    }
    if(!grt && f_ed!=f_ver){
        cout<<f_ed<<'/'<<f_ver;
    }
    else if(!grt && f_ed==f_ver){
        cout<<"1/1";
    }
    else {
        cout<<">1";
    }
    return 0;
}