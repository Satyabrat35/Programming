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
    char arr[n+2][m+2];
    int dist[n+2][m+2];
    vector<pair<int,int>> vec;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            dist[i][j]=100000;
            if(arr[i][j]=='1'){
                dist[i][j]=0;
                vec.push_back({i,j});
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j]=='0'){
                for(int it=0;it<vec.size();it++){
                    int q1 = abs(i - vec[it].first);
                    int q2 = abs(j - vec[it].second);
                    dist[i][j] = min(dist[i][j],q1+q2);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<dist[i][j]<<' ';
        }
        cout<<endl;
    }
    }
    return 0;
}