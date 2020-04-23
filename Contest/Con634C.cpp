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
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int dist = 0;
    int mxcount = 0;
    map<int,int> mp;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(mp[a[i]]==0)dist++;
        mp[a[i]]++;
        mxcount = max(mxcount,mp[a[i]]);
    }
    int val = max(min(dist-1, mxcount), min(dist, mxcount-1));
    
    
    cout<<val<<endl;
}
}