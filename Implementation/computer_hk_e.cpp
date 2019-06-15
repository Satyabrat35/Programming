/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
 typedef long long  int ll;
//map<char,int> mp1,mp2;
//set<string> s;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
ll bs(ll x)
{
ll l = 1;
ll r = sqrt(x);
while(l<r){
    ll m = (l+r)/2;
    ll k = (int)log2(x/m) + 1;
    ll k1 = (int)log2(m) + 1;
    //cout<<k<<k1<<' ';
    if(k>k1){
        l = m+1;
    }
    if(k<=k1){
        //tot=l;
        r=m;
    }
}
ll k = (int)log2(x/l) + 1;
ll k1 = (int)log2(l) + 1;
if(k<=k1)
    return l;
else
    return l+1;
}
int main()
{ int t;
cin>>t;
while(t){
    ll a;
    cin>>a;
ll p = bs(a);
cout<<a-p+1<<endl;
t--;
}

    return 0;
}
