/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
//set<int> s1,s2;
//map<int,int> mp1,mp2;
//set<int>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define xyz  ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int main()
{
    xyz;
    string s;
    vector<int> pos;
    cin>>s;
    int l = s.length();
    int x=-1,ct=0;
    for(int i=0;i<l;i++){
        if(x<s[i]){
            x=s[i];
        }
    }
    for(int i=0;i<l;i++){
        if(x==s[i]){
            ct++;
            pos.push_back(i);
        }
    }
    if(ct==1){
        int p = pos[0];
        for(int i=p;i<l;i++){
            cout<<s[i];
        }
        for(int i=0;i<p;i++){
            cout<<s[i];
        }
    }
    else {
        
    }

    return 0;
}