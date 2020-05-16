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
int solve(int a[],int x,int n,int k){
    if(x>=n){
        return INT_MAX;
    }
  	if(x== n-1){
    	return 0;
    }
  	if(dp[x]!=-1){
      return dp[x];
    }
  int p = INT_MAX;
  for(int i=1;i<=k;i++){
  	int z;
    if(x+i >= n){
    	z = INT_MAX;
    }
    else {
      	z = solve(a,x+i,n,k) + abs(a[x]-a[x+i]);
    }
    p = min(p,z);
  }
  return dp[x] = p;
   
}
int main()
{
  int n,k;
 cin>>n>>k;
  int a[n+1];
 for(int i=0;i<n;i++){
     cin>>a[i];
 }
 memset(dp, -1, sizeof(dp));
 int v = solve(a,0,n,k);
 cout<<dp[0]<<endl;
 return 0;
}