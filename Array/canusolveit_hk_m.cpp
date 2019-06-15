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
        int t;
        cin>>t;
        while(t){
            int n;
            cin>>n;
            int a[n],mc=-1e6,mb=-1e6,mnc=1e6,mnb=1e6;
            for(int i=0;i<n;i++){
                cin>>a[i];
                if((a[i]-i)>mc)
                    mc = a[i] - i;
                if((a[i]-i)<mnc)
                    mnc = a[i] - i;
                if((a[i]+i)>mb)
                    mb = a[i] + i;
                if((a[i]+i)<mnb)
                    mnb = a[i] + i;
            }
            ll mx = max(mc-mnc,mb-mnb);
            cout<<mx<<endl;
            t--;
        }
    return 0;
}
