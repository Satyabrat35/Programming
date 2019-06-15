/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
map<int,int> mp1;
//set<int> s1,s2;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int main() {
    ll n;
    cin>>n;
    ll arr[n+10];
    ll evct[n+10] = {0};
    ll odct[n+10] = {0};
    ll ans = 0,diff=0;
    odct[0]=1; // since diff is initially zero so odct[0]=1
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]%2!=0){
            diff++;
        }
        else {
            diff--;
        }
        if(diff<0){
            ans+=evct[-diff];
            evct[-diff]++;
        }
        else {
            ans+=odct[diff];
            odct[diff]++;
        }
    }
    cout<<ans<<endl;
}