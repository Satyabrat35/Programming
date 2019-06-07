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
const int MX = 100005;
int main() {
    int n,k;
    cin>>k>>n;
    ll arr[n+1],pre[n+1]={0},post[n+1]={0};
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1] + arr[i];
        post[i] = post[i-1] + arr[n-i+1];
    }
    ll mx = 0;
    for(int i=0;i<=k;i++){
        if(mx<pre[i]+post[k-i]){
            mx = pre[i] + post[k-i];
        }
    }
    return 0;
}