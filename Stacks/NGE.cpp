/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
 typedef long long  int ll;
//map<char,int> mp1,mp2;
//set<string> s;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int main()
{   int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int b[n],c[n];
    stack<int> s;
    s.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!s.empty()){
            if(a[s.top()]<a[i]){
                int pos = s.top();
                b[pos]=i+1;
                s.pop();
            }
            else
                break;
        }
        s.push(i);
    }
    while(!s.empty()){
        int pos = s.top();
        b[pos]=-1;
        s.pop();
    }
    s.push(0);
    for(int j=1;j<=n-1;j++){
        while(!s.empty()){
            if(a[s.top()]<a[j]){
                int pos = s.top();
                c[pos] = j+1;
                s.pop();
            }
            else
                break;
        }
        s.push(j);
    }
    while(!s.empty()){
        int pos = s.top();
        c[pos]=-1;
        s.pop();
    }
    for(int i=0;i<n;i++){
        cout<<c[i]+b[i]<<' ';
    }
    return 0;
}
