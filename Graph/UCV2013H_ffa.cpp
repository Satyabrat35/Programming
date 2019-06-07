/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int arr[252][252];
bool vis[252][252];
int main() {
    int n,m;
    cin>>n>>m;
    while(n && m){
    vector<pair<int,int>> vec;
    map<int,int> mp1;
    set<int> s1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            vis[i][j]=0;
            if(arr[i][j]){
                vec.push_back({i,j});
            }
        }
    }
    int ct=0;
    int mxm = 0;
    int q1[4]={-1,0,0,1};
    int q2[4]={0,-1,1,0};
    int ans = 0;
    for(int i=0;i<vec.size();i++){
        int i1 = vec[i].first;
        int i2 = vec[i].second;
        if(vis[i1][i2]==0){
            vis[i1][i2]=1;
            ct=1;
            queue<pair<int,int>> q;
            q.push({i1,i2});
            while(!q.empty()){
                
                int x1 = q.front().first;
                int x2 = q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int x3 = x1+q1[j];
                    int x4 = x2+q2[j];
                    if((x3>0 && x3<=n) && (x4>0 && x4<=m) && vis[x3][x4]==0){
                        if(arr[x3][x4]==1){
                            vis[x3][x4]=1;
                            ct++;
                            q.push({x3,x4});
                        }
                    }
                }
            }
            mp1[ct]++;
            s1.insert(ct);
        } 
    }
    for(auto it=s1.begin();it!=s1.end();++it){
        ans+=mp1[*it];
    }
    cout<<ans<<endl;
    for(auto it=s1.begin();it!=s1.end();++it){
        cout<<*it<<' '<<mp1[*it]<<endl;
    }
    cin>>n>>m;
    }
    return 0;
    
}