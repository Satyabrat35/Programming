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
#define f(i,n)  for(ll i=0;i<n;i++)
#define rf(i,n) for(ll i=n-1;i>=0;i--)
#define PI 3.14159265
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    int a,b,h,m;
    cin>>a>>b>>h>>m;
    double ang = (double)abs(m*6 - h*30 - m/2);
    //cout<<ang<<' ';
    cout.precision(10);
    if(ang==0){
        cout<<double(b-a)<<endl;
    }
    else {
        double gg = 2*cos(ang * PI / 180.0)*a*b;
        //cout<<gg<<' ';
        double ans = (double)(a*a + b*b - gg);
        cout<<sqrt(ans)<<endl;
    }
}