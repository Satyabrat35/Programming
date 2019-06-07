/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long int ll;
typedef unsigned long long int ull;
map<int,int> mp1;
//set<int> s1,s2;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n+1][3];
        int dp[n+1][3];
        for(int i=0;i<n;i++){
            cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        }
        dp[0][0] = arr[0][0];
        dp[0][1] = arr[0][1];
        dp[0][2] = arr[0][2];
        for(int i=1;i<n;i++){
            for(int j=0;j<3;j++){
                dp[i][j] = arr[i][j] + min(dp[i-1][(j+2)%3],dp[i-1][(j+1)%3]);
            }
        }
        cout<<minm(dp[n-1][0],dp[n-1][1],dp[n-1][2])<<endl;
    }
    return 0;
}