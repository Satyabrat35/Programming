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
    vector<int> booth[2],tool[2];
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            booth[i].push_back(x);
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<n-1;j++){
            int x;
            cin>>x;
            tool[i].push_back(x);
        }
    }
    int t1[n],t2[n];
    t1[0]=booth[0][0];
    t2[0]=booth[1][0];
    for(int i=1;i<n;i++){
        t1[i]=min(t1[i-1] + booth[0][i],t2[i-1] + booth[0][i]+ tool[1][i-1]);
        t2[i]=min(t2[i-1] + booth[1][i],t1[i-1] + booth[1][i]+ tool[0][i-1]);
    }
    int ans = min(t1[n-1],t2[n-1]);
    //cout<<t1[n-1]<<' '<<t2[n-1]<<endl;
    cout<<ans<<endl;
    }
    return 0;
}