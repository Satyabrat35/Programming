/**************erik****************/
#include<bits/stdc++.h>
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
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
long long a[300001];
long long b[300001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
    
    for (long long c = 0LL; c < t; c++) {
        long long n;
        cin >> n;
        
        for (long long i = 0LL; i < n; i++) {
            long long a_i, b_i;
            cin >> a_i >> b_i;
            a[i] = a_i;
            b[i] = b_i;
        }
        
        long long s = 0LL;
        for (long long i = 0LL; i < n; i++) {
            long long j = i == 0LL ? n - 1 : i - 1;
            s += max(0LL, a[i] - b[j]);
        }
 
        long long ans = -1;
        for (long long i = 0; i < n; i++) {
            long long j = i == 0 ? n - 1 : i - 1;
            long long cans = s - max(0LL, a[i] - b[j]) + a[i];
            
            if (ans == -1) {
                ans = cans;
            } else {
                ans = min(ans, cans);
            }
        }
        
        cout << ans << endl;
    }
}