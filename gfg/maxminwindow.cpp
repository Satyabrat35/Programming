/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
typedef unsigned int ul;
//map<int,int> mp1;
//set<int> s1;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int main() {
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int a[n+1][n+1];
    int mx = -1;
    for(int i=0;i<n;i++){
        cin>>a[0][i];
        if(mx<a[0][i]){
            mx = a[0][i];
        }
    }
    a[0][n]=mx;
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            a[i][j] = min(a[i-1][j], a[i-1][j+1]);
        }
        mx=0;
        for(int j=0;j<n-i;j++){
            if(mx<a[i][j]){
                mx = a[i][j];
            }
        }
        a[i][n]=mx;
    }
    for(int i=0;i<n;i++){
        cout<<a[i][n]<<' ';
    }
    cout<<endl;
    }
    return 0;

}