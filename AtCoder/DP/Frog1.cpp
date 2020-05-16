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
const int MXM = 100005;
int dp[MXM];
int solve(int a[],int x,int n){
   int zz,yy;
    if(x>=n){
        return INT_MAX;
    }
  	if(x== n-1){
    	return 0;
    }
  	if(dp[x]!=-1){
      return dp[x];
    }
   
        if(x+2 < n){
          	zz = solve(a,x+1,n)+abs(a[x]-a[x+1]);
          	yy = solve(a,x+2,n) + abs(a[x+2] - a[x]);
        } else {
            zz = solve(a,x+1,n)+abs(a[x]-a[x+1]);
          	yy = INT_MAX;
        }
    return dp[x] = min(zz,yy);
}
int main()
{
  int n;
 cin>>n;
  int a[n+1];
 for(int i=0;i<n;i++){
     cin>>a[i];
 }
 memset(dp, -1, sizeof(dp));
 int v = solve(a,0,n);
 cout<<dp[0]<<endl;
 return 0;
}