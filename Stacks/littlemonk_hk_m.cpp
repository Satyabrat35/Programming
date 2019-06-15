/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
 typedef long long  int ll;
//map<char,int> mp1,mp2;
//set<string> s;
#define maxm(a,b,c)  max(a,max(c,b))
#define xyz  ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int main()
{xyz;
    int n,sz=0,mx=0,ng=0;
    cin>>n;
    stack<int> stk,stk1;
    ll a[n+1];
    for(int i=0;i<n;i++)
        {cin>>a[i];
          if(a[i]<0)
            ng++;
        }
        if(ng==n){
        cout<<"0";
        return 0;
    }
    if(a[0]<0){
        if(n%2==0)
            cout<<n-2;
        else
            cout<<n-1;
        return 0;
    }

    for(int i=0;i<n;){
        if(a[i]>0)
            {stk.push(a[i]);
            if(i!=sz)
                sz=0;
            i++;
            }
        else if(a[i]<0 && !stk.empty()){
            if(a[i] == -stk.top())
            {
                sz+=2;
                mx = max(sz,mx);
                stk.pop();
                i++;
            }
            else {
                    i+=stk.size();
                    sz=0;
            }
        }
          }
    if(stk.empty())
        cout<<n;
    else
        cout<<mx;
    return 0;
}
