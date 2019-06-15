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
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int dp[3][n+1];
    for(int i=0;i<=2;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=0;
        }
    }
    if(arr[0]==2 || arr[0]==3)
        dp[2][0]=1;
    
    if(arr[0]==1 || arr[0]==3)
        dp[1][0]=1;
    
    for(int i=1;i<n;i++){
        dp[0][i]=maxm(dp[1][i-1],dp[0][i-1],dp[2][i-1]);
        if(arr[i]==1 || arr[i]==3){
            dp[1][i]=max(dp[2][i-1] + 1,dp[0][i-1]+ 1);
        }
        if(arr[i]==2 || arr[i]==3){
           dp[2][i]=max(dp[1][i-1] + 1,dp[0][i-1]+ 1);
        }
        
        //cout<<dp[0][i]<<' '<<dp[1][i]<<' '<<dp[2][i]<<endl;
    }
    cout<< n-maxm(dp[1][n-1],dp[0][n-1],dp[2][n-1])<<endl;
    return 0;
}