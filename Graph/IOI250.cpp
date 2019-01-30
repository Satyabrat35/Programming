/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
//map<ll,ll> mp1;
//set<int> s1;
//set<int>::iterator it;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
const int MAX = 100005;
int arr[1005],val[1005][1005],res[1005][1005];
pair<ll,pair<int,int>> p[MAX];
vector<int> vec[1005];
bool vis[1005];
int n,m,q,start;
void dfs(int x,int tot){
    vis[x]=1;
    res[start][x]=tot;
    for(int i=0;i<vec[x].size();i++){
        if(vis[vec[x][i]]==0){
            dfs(vec[x][i],val[x][vec[x][i]] + tot);
        }
    }
}
void initialize(int n,bool vis[]){
    for(int i=1;i<=n+1;i++){
        arr[i]=i;
        vec[i].clear();
        vis[i]=0;
    }
}
int root(int x){
    while(arr[x] != x){
        arr[x] = arr[arr[x]];
        x = arr[x];
    }
    return x;
}
bool find(int x,int y){
    if(root(x)==root(y))
        return true;
    else
        return false;
}
void uniwg(int x,int y){
    int root_x = root(x);
    int root_y = root(y);
    
    arr[root_x] = arr[root_y];
    
}
void kruskal_man(pair<int,pair<int,int>> p[]){
    int x,y;
    for(int i=0;i<m;i++){
        x = p[i].second.first;
        y = p[i].second.second;
        if(root(x)!=root(y)){
            vec[x].push_back(y);
            vec[y].push_back(x);
            val[x][y] = p[i].first;
            val[y][x] = p[i].first;
            uniwg(x,y);
        }
    }
}
int main() {
    int t;
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
    cin>>n>>m>>q;
    //bool vis[n+1];
    initialize(n,vis);
    pair<int,pair<int,int>> p[m+1];
    for(int i=0;i<m;i++){
        int x,y,wgt;
        scanf("%d %d %d",&x,&y,&wgt);
        p[i]=make_pair(wgt,make_pair(x,y));
    }
    printf("Case: %d",h);
    sort(p,p+m);
    kruskal_man(p);
    for(int i=1;i<=n;i++){
        start = i;
        dfs(i,0);
        memset(vis,0,sizeof(vis));
    }
    for(int i=0;i<q;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",res[x][y]);
    }
    }
    return 0;
}