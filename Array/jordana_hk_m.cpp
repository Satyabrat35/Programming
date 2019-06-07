/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
 typedef long long  int ll;
 typedef unsigned long long int ull;
set<int> s1,s2;
map<int,int> mp1,mp2;
set<int>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define xyz  ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int main()
{       xyz;
        int n;
        cin>>n;
        ll sum=0,mx=-1;
        int a[n],b[n];
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
            if(i==0)
            {
                b[i] = a[i];
            }
            else {
                b[i]+=b[i-1] + a[i];
            }
        }
        //for(int i=0;i<n;i++)
          //  cout<<b[i]<<' ';
        for(int i=0;i<n;i++){
               // cout<<b[i]*(sum-b[i])<<' ';
            mx = max(b[i]*(sum-b[i]),mx);
        }
        cout<<mx;
    return 0;
}
