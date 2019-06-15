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
ll arr1[1000005];
ll arr2[1000005];
ll sz[1000005];
ll sz2[1000005];
ll n,m;
void initialize(int n){
    for(int i=1;i<=n;i++){
        arr1[i]=i;
        sz[i]=1;
    }
}
void initialize2(int m){
    for(int i=1;i<=m;i++){
        arr2[i]=i;
        sz2[i]=1;
    }
}
ll root1(ll x){
    while(arr1[x] != x){
        //arr[x] = arr[arr[x]];
        x = arr1[x];
    }
    return x;
}
ll root2(ll x){
    while(arr2[x] != x){
        //arr[x] = arr[arr[x]];
        x = arr2[x];
    }
    return x;
}
void uniwg(ll x,ll y){
    ll root_x = root1(x);
    ll root_y = root1(y);
    if(root_x  == root_y)
        return;
    if(sz[root_x]>sz[root_y]){
        arr1[root_y] = root_x;
        sz[root_x]+=sz[root_y];
    }
    else {
        arr1[root_x] = root_y;
        sz[root_y]+=sz[root_x];
    }
}
void uniwg2(ll x,ll y){
    ll root_x = root2(x);
    ll root_y = root2(y);
    if(root_x  == root_y)
        return;
    if(sz2[root_x]>sz2[root_y]){
        arr2[root_y] = root_x;
        sz2[root_x]+=sz2[root_y];
    }
    else {
        arr2[root_x] = root_y;
        sz2[root_y]+=sz2[root_x];
    }
}
int main(){
    cin>>n>>m;
    initialize(n);
    initialize2(m);
    int q1,q2,q3;
    cin>>q1;
    for(int i=0;i<q1;i++){
        ll x,y;
        cin>>x>>y;
        uniwg(x,y);
    }
    cin>>q2;
    for(int i=0;i<q2;i++){
        ll x,y;
        cin>>x>>y;
        uniwg2(x,y);
    }
    cin>>q3;
    ll ans = 0;
    vector<ll> vec[m+1];
    for(int i=0;i<q3;i++){
        ll x,y;
        cin>>x>>y;
        vec[root2(y)].push_back(root1(x)); // Loop hole here .. last 2 TCs failed
    }
    for(int i=1;i<=m;i++){
        ll z = root2(i);
        if(vec[z].size()!=0){
            ll p = root1(vec[z][0]);
            //cout<<z<<' '<<p<<' '<<vec[z][0]<<' '<<sz[p]<<endl;
            ans+= (n-sz[p]);
        }
        else {
            //cout<<z<<endl;
            ans+=n;
        }
    }
    cout<<ans;
    
    return 0;
}