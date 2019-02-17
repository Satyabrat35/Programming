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
const int MAX = 100005;
int dp[MAX];
int arr[MAX];
int n,l,r,value;
int calc(int x){
    if(x>=100001)
        return 0;
    if(dp[x]!=-1)
        return dp[x];
    return dp[x] = max(calc(x+1) , x*arr[x]+calc(x+value+1));
}
int main() 
{ 
    int t;
    cin>>t;
    while(t--){
    cin>>n>>l>>r;
    int val[n+1];
    for(int i=0;i<=n+2;i++){
        arr[i]=0;
        dp[i]=-1;
    }
    //memset(arr,0,sizeof(arr));
    for(int i=0;i<n;i++){
        cin>>val[i];
        arr[val[i]]++;
    }
    //memset(dp,-1,sizeof(dp));
    value = min(l,r);
    cout<<calc(0)<<endl;
    }
	return 0; 
} 
