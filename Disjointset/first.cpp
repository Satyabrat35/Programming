/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
map<ll,ll> mp1;
//set<int> s1;
//set<int>::iterator it;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int arr[1005];
int sz[1005];
int risk[1005];
int n,k;
void initialize(int n){
    for(int i=1;i<=n;i++){
        arr[i]=i;
        sz[i]=i;
    }
}
int root(int x){
    while(arr[x] != x){
        arr[x] = arr[arr[x]];
        x = arr[x];
    }
    return x;
}
bool find(int x,int y){
    if(root(x)==root(y))
        return true;
    else
        return false;
}
void uniwg(int x,int y){
    int root_x = root(x);
    int root_y = root(y);
    if(root_x  == root_y)
        return;
    if(sz[root_x]>sz[root_y]){
        if(risk[root_x]>=risk[root_y]){
            risk[root_x] = risk[root_y];
            mp1[root_x]+=mp1[root_y];
        }
        arr[root_y] = root_x;
        sz[root_x]+=sz[root_y];
        //cout<<x<<' '<<arr[root_x]<<' '<<sz[root_x]<<endl;
        //cout<<y<<' '<<arr[root_y]<<' '<<sz[root_y]<<endl;
    }
    else {
        if(risk[root_y]>=risk[root_x]){
            risk[root_y] = risk[root_x];
            mp1[root_y]+=mp1[root_x];
        }
        arr[root_x] = root_y;
        sz[root_y]+=sz[root_x];
        //cout<<x<<' '<<arr[root_x]<<' '<<sz[root_x]<<endl;
        //cout<<y<<' '<<arr[root_y]<<' '<<sz[root_y]<<endl;
    } 
}
int main() {
    cin>>n;
    initialize(n);
    for(int i=1;i<=n;i++){
        cin>>risk[i];
        mp1[i]=1;
    }
    cin>>k;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        uniwg(x,y);
    }
    for(int i=1;i<=n;i++){
        int z = root(i);
        cout<<z<<' '<<mp1[z]<<endl;
    }
    return 0;
}