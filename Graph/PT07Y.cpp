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
int arr[100005];
int sz[100005];
int n,k;
bool f = true;
void initialize(int n){
    for(int i=0;i<=n;i++){
        arr[i]=i;
        sz[i]=0;
    }
}
int root(int x){
    while(arr[x] != x){
        //arr[x] = arr[arr[x]];
        x = arr[x];
    }
    return x;
}
void uniwg(int x,int y){
    int root_x = root(x);
    int root_y = root(y);
    if(arr[root_x] == arr[root_y]){
        f = false;
        return ;
    }
    arr[root_y] = arr[root_x];
    sz[y]++;
}
int main() {
    cin>>n>>k;
    if(n!=k+1){
        cout<<"NO"<<endl;
        return 0;
    }
    initialize(n);
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        uniwg(x,y);
    }
    
    for(int i=1;i<=n;i++){
        if(sz[i]>1){
            f = false;
            break;
        }
    }
    if(f){
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
}