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
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int pk[n];
        pk[0]=0;
        pk[n-1]=0;
        for(int i=1;i<(n-1);i++){
            if(a[i-1]<a[i] && a[i]>a[i+1]){
                pk[i]=1;
            } else {
                pk[i]=0;
            }
        }
        int pref[n];
        pref[0]=0;
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+pk[i];
        }
        //cout<<endl;
        int peaks = 0;
        int st = 0;
        for(int i=0;i<n;){
            int x;
            if(i+k-1<n){
                if(!i){
                    x = pref[i+k-1];
                    if(pk[i+k-1]==1)x-=1;
                    if(peaks<x){
                        peaks = x;
                        st = i;
                    }
                } else {
                    x = pref[i+k-1] - pref[i-1];
                    if(pk[i+k-1]==1)x-=1;
                    if(pk[i]==1)x-=1;
                    if(peaks<x){
                        peaks = x;
                        st = i;
                    }
                }
            }
            i++;
        }
        cout<<peaks+1<<' '<<st+1<<endl;

    }
    return 0;
}