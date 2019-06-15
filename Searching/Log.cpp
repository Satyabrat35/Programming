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
const ll MXM = 1e10+9;
double binary(int l,int h,int n,double key,int index){
    while(l<=h){
        int mid = (l+h)/2;
        double xxx = n*log10(mid);
        if(xxx>key){
            index = mid;
            h = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    return index;
}
int main() {
    int n;
    cin>>n;
    double prod=0;
    int mxm=-1;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        if(mxm<x){
            mxm=x;
        }
        prod += log10(x);
    } 
    int pos = binary(1,mxm,n,prod,2);
    cout<<pos<<endl;
    return 0;
}