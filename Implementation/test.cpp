/**************erik****************/
#include "stdc++.h"
//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long int ull;
//map<ll,ll> mp1;
//set<int> s1;
//set<int>::iterator it;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(ll i=0;i<n;i++)
#define rf(i,n) for(ll i=n-1;i>=0;i--)
ll chart(char a, char b, ll x, ll y) {
    if (b=='E') {
        if (a=='E') {
            return 0;
        }
        if (a=='W') {
            return min(2*x, 2*y);
        }
        if (a=='N') {
            return min(x, 3*y);
        }
        if (a=='S') {
            return min(3*x, y);
        }
    }
    if (b=='W') {
        if (a=='E') {
            return min(2*x, 2*y);
        }
        if (a=='W') {
            return 0;
        }
        if (a=='N') {
            return min(3*x, y);
        }
        if (a=='S') {
            return min(x, 3*y);
        }
    }
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string ss;
        cin>>ss;
        ll x,y;
        cin>>x>>y;
        ll pres[n], prew[n];
        for (int i=0;i<n;i++) {
            if (ss[i]=='E') pres[i]=0, prew[i]=2*min(x,y);
            else if (ss[i]=='W') pres[i]=2*min(x,y), prew[i]=0;
            else if (ss[i]=='N') pres[i]=min(x, 3*y), prew[i]=min(3*x, y);
            else if (ss[i]=='S') pres[i]=min(3*x, y), prew[i]=min(x, 3*y);
        }
        for(int i=1;i<n;i++) {
            pres[i]=pres[i-1]+pres[i];
        }
        for (int i=n-2;i>=0;i--) {
            prew[i]=prew[i]+prew[i+1];
        }
        ll sum=min(pres[n-1], prew[0]);
        for(int i=0;i<(n-1);i++) {
            ll cl=pres[i] + prew[i+1];
            sum=min(sum, cl);
        }
        cout<<sum<<endl;

    }
    return 0;
}