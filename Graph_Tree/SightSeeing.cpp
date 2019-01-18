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
vector<int> v[100009];
bool vis[100009];
int val[100009];
int h_max;

void dfs(int x,int start){
    vis[x]=1;
    h_max = max(h_max,val[x]-val[start]);
    for(int i=0;i<v[x].size();i++){
        if(vis[v[x][i]]==0){
            dfs(v[x][i],start);
        }
    }
}
int main (){
    int t;
    cin>>t;
    while(t--){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        v[i].clear();
        vis[i]=0;
    }
    h_max=0;
    vector<pair<int,int>> hgt;
    for(int i=1;i<=n;i++){
        cin>>val[i];
        hgt.push_back(make_pair(val[i],i));
    }
    sort(hgt.begin(),hgt.end());
    
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    
    
    for(int i=0;i<hgt.size();i++){
    	int start = hgt[i].second;
    	if(vis[start]==0){
    		dfs(start,start);
    	}
    }
    cout<<h_max<<endl;
}
    return 0;

}