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
ll arr[MX][MX];
int n,k;
int a[MX];
ll profit(int be,int en,int num){
    if(be>en){
        return 0;
    }
    if(num<=0){
        return 0;
    }
    if(arr[be][en]!=-1){
        return arr[be][en];
    }
    if(profit(be+1,en,num-1) + a[be] > profit(be,en-1,num-1) + a[en]){
        return arr[be][en] = profit(be+1,en,num-1) + a[be];
    }
    else {
        return arr[be][en] = profit(be,en-1,num-1) + a[en];
    }
}
int main() {
    cin>>k>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            arr[i][j]=-1;
        }
    }
    ll mxm = profit(0,n-1,k);
    cout<<mxm;
    return 0;
}