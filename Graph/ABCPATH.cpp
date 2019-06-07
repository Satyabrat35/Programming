/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
//map<int,int> mp1;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
char arr[51][51];
bool vis[51][51];
int mxm = 0;
int n,m;

void dfs(int pos1,int pos2,int lgt){
    mxm = max(mxm,lgt);
    int q1[8]={-1,-1,-1,0,0,1,1,1};
     int q2[8]={-1,0,1,-1,1,-1,0,1};
    for(int i=0;i<8;i++){
        int q3 = q1[i]+pos1;
        int q4 = q2[i]+pos2;
        if((q3>0 && q3<=n) && (q4>0 && q4<=m) && vis[q3][q4]==0){
            if(arr[q3][q4] == arr[pos1][pos2]+1){
                vis[q3][q4]=1;
                dfs(q3,q4,lgt+1);
            }
        }
    }
}
int main() {
    //init();
    int cc=1;
    cin>>n>>m;
    while(n&&m){
    mxm=0;
    set<pair<int,int>> s1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            vis[i][j]=0;
            if(arr[i][j]=='A'){
                s1.insert({i,j});
            }
        }
    }
    for(auto it=s1.begin();it!=s1.end();++it){
        int qq1 = (*it).first;
        int qq2 = (*it).second;
        vis[qq1][qq2]=1;
        dfs(qq1,qq2,1);
    }
    printf("Case %d: %d\n",cc,mxm);
    cc++;
    cin>>n>>m;
    }
    return 0;
}