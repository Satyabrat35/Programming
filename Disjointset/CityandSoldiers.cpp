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
int n,k;
void initialize(int n){
    for(int i=1;i<=n;i++){
        arr[i]=i;
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
    arr[root_x] = root_y;
    //sz[root_y]+=sz[root_x];
}
int main()
{
    cin>>n>>k;
    initialize(n);
    while(k--){
        int q;
        cin>>q;
        if(q==1){
            int x,y;
            cin>>x>>y;
            uniwg(x,y);
        }
        else if(q==2){
            int x,y;
            cin>>x;
            y = root(x);
            arr[y]=arr[x]=x; // IMPORTANT
        }
        else {
            int x;
            cin>>x;
            cout<<root(x)<<endl;
        }
    }
    return 0;
}