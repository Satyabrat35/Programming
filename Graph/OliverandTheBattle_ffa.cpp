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
int main() {
    int t;
    cin>>t;
    while(t--){
    int n,m;
    cin>>n>>m;
    int arr[n+2][m+2];
    bool vis[n+2][m+2];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            vis[i][j]=0;
        }
    }
    int ct=0,ans=-1;
    int mxm = 0;
    int q1[8]={-1,-1,-1,0,0,1,1,1};
    int q2[8]={-1,0,1,-1,1,-1,0,1};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j]==1 && vis[i][j]==0){
            ct++;
            vis[i][j]=1;
            mxm = 1;
            queue<pair<int,int>> q;
            q.push({i,j});
            while(!q.empty()){
                int x1 = q.front().first;
                int x2 = q.front().second;
                q.pop();
            for(int k=0;k<8;k++){
                int q3 = q1[k]+x1;
                int q4 = q2[k]+x2;
                if((q3>0 && q3<=n) && (q4>0 && q4<=m) && vis[q3][q4]==0){
                    if(arr[q3][q4]==1){
                        vis[q3][q4]=1;
                        mxm++;
                        q.push({q3,q4});
                    }
                }
            }
        }
        }
        ans = max(ans,mxm);
        mxm=0;
        }
    }
    
    cout<<ct<<' '<<ans<<endl;
    }
    return 0;

}