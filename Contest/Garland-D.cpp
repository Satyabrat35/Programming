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
set<char> sr;
char arr[200005];
int main() {
    int t;
    cin>>t;
    char prev,next,curr;
    for(int i=0;i<t;i++){
        cin>>arr[i];
    }
    sr.insert('R');
    sr.insert('G');
    sr.insert('B');
    int ct=0;
    for(int i=0;i<t-1;i++){
        if(arr[i]==arr[i+1] && i!=t-2){
            sr.erase(arr[i]);
            sr.erase(arr[i+2]);
            arr[i+1] = *(sr.begin());
            sr.insert(arr[i+2]);
            sr.insert(arr[i]);
            ct++;
        }
        else if(arr[i]==arr[i+1]){
            sr.erase(arr[i]);
            arr[i+1] = *(sr.begin());
            sr.insert(arr[i]);
            ct++;
        }
    }
    cout<<ct<<endl;
    for(int i=0;i<t;i++){
        cout<<arr[i];
    }
    return 0;
}