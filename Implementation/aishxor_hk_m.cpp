/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
 typedef long long  int ll;
 typedef unsigned long long int ull;
//map<char,int> mp1,mp2;
set<int> s1,s2;
set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int main()
{
    int n,q;
    cin>>n;
    int a[n+1],b[n+1],c[n+1];
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i])
            b[i]++;
        else
            c[i]++;
    }
    for(int i=2;i<=n;i++){
        b[i]+=b[i-1];
        c[i]+=c[i-1];
    }
    cin>>q;
    while(q){
        int l,r,ct,ct2;
        cin>>l>>r;
        if(l-1!=0){
            ct = c[r] - c[l-1];
            ct2 = b[r] - b[l-1];
            if(ct2%2==0){
                cout<<"0"<<' ';
            }
            else {
                cout<<"1"<<' ';
            }
            cout<<ct<<endl;
        }
        else {
            ct = c[r];
            ct2 = b[r];
            if(ct2%2==0){
                cout<<"0"<<' ';
            }
            else {
                cout<<"1"<<' ';
            }
            cout<<ct<<endl;
        }
        q--;
    }
    return 0;
}
