/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
map<int,int> mp1;
//set<ll> s1;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
queue<pair<ll,ll>> q;
ll keys[100009];
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n,a,b,s,d;
    scanf("%d %d %d",&n,&a,&b);
    s=n*b;
    d=n*a + s;
    q.push({s,0});
    memset(keys,0,sizeof(keys));
    keys[s]=1;
    ll tot=0;
    while(!q.empty()){
        ll val = q.front().first;
        ll level = q.front().second;
        q.pop();
        if(level>=n){
            continue;
        }
        if(val+a<=d){
            if(keys[val+a]==0){
                keys[val+a]=1;
                q.push({val+a,1+level});
            }
        }
        if(val-b>=0){
            if(keys[val-b]==0){
                keys[val-b]=1;
                q.push({val-b,1+level});
            }
        }
    }
    for(ll i=0;i<=d;i++){
        tot+=keys[i];
    }
    cout<<tot<<endl;
    }
    return 0;
}