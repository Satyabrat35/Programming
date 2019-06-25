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
//set<string> ss;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int lcs(string x,string y,int n,int m){
    int l[n+1][m+1];
    int maxm = 0;
    memset(l,0,sizeof(l[0][0])*(n+1)*(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1] == y[j-1]){
                l[i][j] = 1 + l[i-1][j-1];
                if(maxm<l[i][j]){
                    maxm = l[i][j];
                }
            }
        }
    }
    return maxm;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string x,y;
        cin>>x>>y;
        cout<<lcs(x,y,n,m)<<endl;
    }
    return 0;
}