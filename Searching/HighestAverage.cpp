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
int main() {
    int n;
    cin>>n;
    ll arr[n];
    double sm[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    sm[0] = (double)arr[0];
    ll  x = arr[0];
    for(int i=1;i<n;i++){
    x+=arr[i];
    sm[i] =  (double)x/(double)(i+1);
     //cout<<sm[i]<<endl;  
    }
    int q;
    cin>>q;
    while(q--){
        ll k;
        cin>>k;
        int l=0, h=n-1;
        int mid = (l+h)/2;
        while(l<=h){
            if(sm[mid]<k){
                l = mid+1;
            }
            else {
                h = mid-1;
            }
            mid=(l+h)/2;
        }
        cout<<h+1<<endl;
    }
    return 0;
}