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
int binary(int l,int r,ll key,ll a[]){
    int mxm =-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid]>key){
            r = mid - 1;
        }
        else if(a[mid]==key){
            return mid;
        }
        else {
            if(mid>mxm){
                mxm = mid;
            }
            l = mid+1;
        } 
    }
    return mxm;
}
int main() {
    int t;
    cin>>t;
    while(t--){
    int n;
    ll x;
    cin>>n>>x;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int pos = binary(0,n-1,x,a);
    cout<<pos<<endl;
    }
    return 0;
}