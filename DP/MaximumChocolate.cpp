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
const int MX = 1005;
int n;
int arr[MX][MX];
int vis[MX][MX];
int func(int x,int y,int z){
    if(x<1 || x>n || y<1 || y>n){
        return 0;
    }
    if(vis[x][y]!=0){
        return vis[x][y];
    }
    return vis[x][y] = maxm(arr[x][y]+ func(x+1,y+1,z),arr[x][y]+ func(x+1,y,z),arr[x][y]+ func(x+1,y-1,z));
    
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
            vis[i][j]=0;
        }
    }
    int mx = 0;
    for(int i=1;i<=n;i++){
        vis[1][i] = maxm(func(2,i-1,i)+arr[1][i],func(2,i,i)+arr[1][i],func(2,i+1,i)+arr[1][i]);
        mx = max(vis[1][i],mx);
    }
    cout<<mx<<endl;
    return 0;
}