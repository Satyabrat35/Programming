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
int main()
{
    int n,m;
    cin>>n>>m;
    ll q[n],mx=-1,sum=0;
    for(int i=0;i<n;i++){
        cin>>q[i];
        if(q[i]>mx){
            mx=q[i];
        }
        sum+=q[i];
    }
    ll lo=mx,up=sum;
    
    while(lo<up){
        ll mid=(lo+up)/2;
        ll sm=0;int dv=1;
        for(int i=0;i<n;i++){
            if((sm+q[i])<=mid){
                sm+=q[i];
            }
            else {
                sm=q[i];
                dv++;
            }
        }
        if(dv<=m){
            up=mid;
        }
        else {
            lo=mid+1;
        }
    }
    cout<<lo;
    return 0;
}