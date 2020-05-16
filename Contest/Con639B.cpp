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
            int n;
            cin>>n;
            int p;
            p = floor((-1 + sqrt(1 + 24*n))/6);
            int ct = 0;
            while(n>1){
                int z = floor(2*p + 3*p*(p-1)/2);
                n-=z;
                p = floor((-1 + sqrt(1 + 24*n))/6);
                ct++;
            }
            cout<<ct<<endl;
            
        }
    }