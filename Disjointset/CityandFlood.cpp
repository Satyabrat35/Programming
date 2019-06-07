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
//set<int>::iterator it;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int arr[100005],size[100005];
int n,k;
void initialize(int n){
    for(int i=1;i<=n;i++){
        arr[i]=i;
    }
}
int root(int i){
    while(arr[i] != i){
        arr[i]=arr[arr[i]];
        i=arr[i];
    }
    return i;
}
void wgtun(int x,int y){
    int root_x = root(x);
    int root_y = root(y);
    arr[root_y] = arr[root_x];
}
int main(){
    cin>>n>>k;
    initialize(n);
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        wgtun(x,y);
    }
    int ct=0;
    for(int i=1;i<=n;i++){
        if(arr[i]==i)
            ct++;
    }
    cout<<ct;
    return 0;
}