/**************erik****************/
#include "stdc++.h"
//#include <bits/stdc++.h>
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
#define f(i,n)  for(ll i=0;i<n;i++)
#define rf(i,n) for(ll i=n-1;i>=0;i--)
int main()
{
    int n;
    cin>>n;
    int a[n],pre[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    pre[0]=a[0];
    //rng[0]=1;
    for(int i=1;i<n;i++) {
        pre[i] = a[i]+pre[i-1];
        //rng[i] = pre[i] - a[i] + 1;
        //cout<<pre[i]<<' '<<rng[i]<<endl;
    }
    int m;
    cin>>m;
    for (int i=0;i<m;i++) {
        int x;
        cin>>x;
        int l=0,r=n-1;
        while (l<=r) {
            int mid = (l+r)/2;
            if ((mid==0 && pre[mid]>=x) || (pre[mid]>=x && pre[mid-1]<x)) {
                cout<<mid+1<<endl;
                break;
            }
            if(pre[mid]<x){
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
    }
    return 0;
}
