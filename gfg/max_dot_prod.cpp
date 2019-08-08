    /**************erik****************/
    #include<bits/stdc++.h>
    #include <cstdio>
    #include <iostream>
    #include <algorithm>
    using namespace std;
    typedef long long  int ll;
    typedef unsigned long long int ull;
    typedef unsigned int ul;
    //map<int,int> mp1;
    //set<int> s1;
    //set<char>::iterator t;
    #define maxm(a,b,c)  max(a,max(c,b))
    #define minm(a,b,c)  min(a,min(c,b))
    #define f(i,n)  for(int i=1;i<n;i++)
    #define rf(i,n) for(int i=n-1;i>=0;i--)
    int n,m;
    ll dp[1005][1005];
    ll cal(int a[],int b[],int i,int j){
        if(i<0 || i>n || j<0 || j>m)return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i>j){
            dp[i][j] = max(a[i-1]*b[j-1]+cal(a,b,i-1,j-1), cal(a,b,i-1,j));
        }
        if(i==j){
            dp[i][j] = cal(a,b,i-1,j-1) + a[i-1]*b[j-1];
        }
        return dp[i][j];
    }
    int main(){
        int t;
        cin>>t;
        while(t--){
            
            cin>>n>>m;
            int a[n],b[m];
            for(int i=0;i<n;i++)cin>>a[i];
            for(int j=0;j<m;j++)cin>>b[j];
            memset(dp,-1,sizeof(dp));
            cout<<cal(a,b,n-1,m-1)<<endl;
        }
        return 0;
    }