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
        //vector<pair<int,int>> vec;
        int a[n],b[n];
        bool f = true;
        int mxp=-1;
        int mxl=-1;
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i];
            if(mxp<=a[i]){
                mxp=a[i];
            }
            if(mxl<=b[i]){
                mxl=b[i];
            }
            if(mxp>a[i] || mxl>b[i]){
                f = false;
            }
            if(mxp<mxl || a[i]<b[i]){
                f = false;
            }
            if(i){
                int diff = a[i]-a[i-1];
                int diff2 = b[i]-b[i-1];
                if(diff2>diff){
                    f=false;
                }
            }
        }
        if(f){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}