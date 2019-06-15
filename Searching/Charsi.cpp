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
ll des[45000];
ll binary(int l,int h,ll key){
    while(l<=h){
        int mid = (l+h)/2;
        if(des[mid]<key){
            l=mid+1;
        }
        else if(des[mid]>key){
            h=mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
int main() {
    int k = 45000;
    des[0]=0;
    for(int i=1;i<k;i++){
        des[i] = (i*(i+1))/2;
    }
    ll n;
    cin>>n;
    int i = 1;
    while(des[i]<(n/2)){
        ll x = des[i];
        ll y = n - des[i];
        int p = sqrt(2*n);
        int l = 0, h=p;
        int pos = binary(l,h,y);
        if(pos==-1){
            i++;
        }
        else{
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}