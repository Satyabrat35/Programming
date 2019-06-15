/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
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
    int n,k;
    cin>>n>>k;
    ll val[n+1],sum[n+1];
    bool f = true;
    for(int i=1;i<=n;i++){
        cin>>val[i];
        if(val[i]>0){
            f = false;
        }
    }
    if(f){
        cout<<"0"<<endl;
        continue;
    }
    for(int i=1;i<=n;i++){
        if(i==1){
            if(val[i]<0)
                sum[i]=0;
            else
            {
                sum[i]=val[i];
            }
        }
        else if(i<=k+1 && i!=1){
            if(val[i]>sum[i-1])
                sum[i] = val[i];
            else
                sum[i] = sum[i-1];
        }
        else {
            if(val[i] + sum[i-k-1] > sum[i-1])
                sum[i]=sum[i-k-1] + val[i];
            else
                sum[i]=sum[i-1];
        }
    }
    cout<<sum[n]<<endl;
    }
    return 0;
}