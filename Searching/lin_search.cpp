/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
 typedef long long  int ll;
 typedef unsigned long long int ull;
map<int,int> mp1;
//set<int> s1,s2;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int main()
{
    int n,ct[26];
    memset(ct,0,sizeof(ct));
    cin>>n;
    char a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        //ct[a[i]-'a']++;
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                for(int k=i+1;k<j;k++){
                    ans+=ct[a[k]-'a'];
                }
            }
        }
        ct[a[i]-'a']++;
    }
    cout<<ans;

    return 0;
}