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
    int t;
    cin>>t;
    while(t--) {
        int n,c;
        cin>>n>>c;
        int x[n],k[n];
        ll dp[n][2];
        for(int i=0;i<n;i++) {
            cin>>x[i];
        }
        for(int i=0;i<n;i++) {
            cin>>k[i];
        }
        for (int i=0;i<n;i++) {
            if (i==0) {
                dp[i][0]=x[i];
                dp[i][1]=c + c*k[i];
            } else {
                dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + x[i];
                dp[i][1] = min(dp[i-1][0] + c + c*k[i], dp[i-1][1] + c);
            }
        }
        cout<<n<<' '<<min(dp[n-1][0], dp[n-1][1])<<endl;
    }
    return 0;
}
