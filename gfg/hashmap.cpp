/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;

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
    int n,k;
    cin>>n>>k;
    int a[n];
    map<int,int> mp1;
    map<int,int>::reverse_iterator rit;
    for(int i=0;i<n;i++)
        {
            cin>>a[i];
            //mp1[a[i]]++;
        }
    for(int i=0;i<k;i++){
        mp1[a[i]]++;
    }
    rit = mp1.rbegin();
    cout<<rit->first<<' ';
    int start = 0;
    for(int i=k;i<n;i++){
        mp1[a[i]]++;
        mp1[a[start]]--;
        if(mp1[a[start]]==0){
            mp1.erase(a[start]);
        }
        rit = mp1.rbegin();
        cout<<rit->first<<' ';
        start++;
    }
    cout<<endl;
    }
    return 0;
}