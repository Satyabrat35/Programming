/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
//map<int,int> mp1;
//set<int> s1;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
const ll MAX = 1e9+7;
ll calc(vector<ll> arr,ll m,ll n){
    ll rooms[n+1];
    memset(rooms,0,sizeof(rooms));
    rooms[0]=1;
    for(ll i=0;i<m;i++){
        for(ll j=arr[i];j<=n;j++){
            rooms[j] = (rooms[j]+(rooms[j-arr[i]]%MAX))%MAX;
        }
    }
    return (rooms[n]%MAX);
}
int main() {
    ll m,n;
    cin>>m>>n;
    vector<ll> vec;
    for(ll i=0;i<m;i++){
        ll x;
        cin>>x;
        vec.push_back(x);
    }
    cout<<calc(vec,m,n)<<endl;
    return 0;
}