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

// int solve(int dp[], int x,int n,int l){
//     if(x>=n){
//         return 0;
//     }
  	
//   int zz,yy;
//   if(l==0){
//   	zz = solve(dp,x+1,n,1) + a[x][0];
//     yy = solve(dp,x+1,n,2) + a[x][0];
//   } else if(l==1){
//   	 zz = solve(dp,x+1,n,0) + a[x][1];
//     yy = solve(dp,x+1,n,2) + a[x][1];
//   } else {
//   	 zz = solve(dp,x+1,n,1) + a[x][2];
//     yy = solve(dp,x+1,n,0) + a[x][2];
//   }

//   return dp[x] = max(zz,yy);
// }
int main()
{
  int n;
 cin>>n;
  int a[n][3];
 for(int i=0;i<n;i++){
     for(int j=0;j<3;j++){
     	cin>>a[i][j];
     }
 }
 int dp[n][3];
 for(int i=0;i<n;i++){
   if(!i){
   	dp[i][0]=a[i][0];
    dp[i][1]=a[i][1];
    dp[i][2]=a[i][2];
   } else {
   	dp[i][0] = a[i][0] + max(dp[i-1][1], dp[i-1][2]);
    dp[i][1] = a[i][1] + max(dp[i-1][0], dp[i-1][2]);
    dp[i][2] = a[i][2] + max(dp[i-1][1], dp[i-1][0]);
   }
 }
 cout<<maxm(dp[n-1][0],dp[n-1][1],dp[n-1][2])<<endl;
 return 0;
}