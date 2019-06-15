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
int comham(string s1,string s2){
    int i=0,ct=0;
    while(s1[i]!='\0'){
        if(s1[i]!=s2[i]){
            ct++;
        }
        i++;
    }
    return ct;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    vector<string> s;
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++){
        string b;
        cin>>b;
        s.push_back(b);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x = comham(s[i],s[j]);
            a[i]+=x;
            //cout<<s[i]<<' '<<x<<endl;
        }
    }
    int mn=1e5,pos=-1;
    for(int i=0;i<n;i++){
        //cout<<a[i]<<endl;
        if(mn>a[i]){
            mn=a[i];
            pos=i;
        }
    }
    cout<<s[pos];
    return 0;
}