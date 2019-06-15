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
set<pair<int,int>> sp;
set<pair<int,int>>::reverse_iterator it;
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> vec[300005];
    int sz[n+1];
    memset(sz,0,sizeof(sz));
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
        sz[x]++;
        sz[y]++;
    }
    for(int i=1;i<=n;i++){
        sp.insert(make_pair(sz[i],i));
    }
    int ans = 0;
    int x,y;
    while(!sp.empty()){
        it = sp.rbegin();
        x = it->second;
        y = it->first;
        it++;
        sp.erase(make_pair(y,x));
        sz[x]=0;
        for(int i=0;i<vec[x].size();i++){
            int p = vec[x][i];
            if(sz[p]>0) {
                sp.erase(make_pair(sz[p],p));
            }
            sz[p]--;

            if(sz[p]>0) {
                sp.insert(make_pair(sz[p],p));
            }
        }
        ans++;
    }
    cout<<ans;
    return 0;
}