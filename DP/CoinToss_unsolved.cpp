/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
//map<int,int> mp1;
//set<int> s1,s2;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
const ll MAX = 1e18;
map<ll,ll> memo;

ll tribonacci(ll n){
    for(int i=4;i<=n;i++){
        memo[i]= ((memo[i-1]%1000000007) + (memo[i-2]%1000000007) + (memo[i-3]%1000000007)%1000000007);
    }
    return (memo[n]%1000000007);
}
int main() {
    memo[1]=2;
    memo[2]=4;
    memo[3]=7;
    int t;
    cin>>t;
    while(t--){
    ll n;
    cin>>n;
    cout<<tribonacci(n)<<endl;
    }
    return 0;
}