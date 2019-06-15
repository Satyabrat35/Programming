/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
set<pii> s1;
set<pii>::iterator it1,it2;
//map<int,int> mp1;
//multiset<int> m1;
//typedef multiset<int>::iterator it;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int arr[100005];
int sz[100005];
int n,k;
void initialize(int n){
    for(int i=1;i<=n;i++){
        arr[i]=i;
        sz[i]=1;
        s1.insert(pii(sz[i],i));
        //m1.insert(1);
    }
}
int root(int x){
    while(arr[x] != x){
        //arr[x] = arr[arr[x]];
        x = arr[x];
    }
    return x;
}
bool find(int x,int y){
    if(root(x)==root(y))
        return true;
    else
        return false;
}
void uniwg(int x,int y){
    int root_x = root(x);
    int root_y = root(y);
    if(root_x  == root_y)
        return;
    if(sz[root_x]>sz[root_y]){
        // for(int i=0;i<sz[root_y];i++){
        //     std::pair<it,it> ret = m1.equal_range(sz[root_y]);
        //     m1.erase(ret.first);
        // }
        // for(int i=0;i<sz[root_x];i++){
        //     std::pair<it,it> ret = m1.equal_range(sz[root_x]);
        //     m1.erase(ret.first);
        // }
        s1.erase(pii(sz[root_x],root_x));
        s1.erase(pii(sz[root_y],root_y));
        arr[root_y] = root_x;
        sz[root_x]+=sz[root_y];
        s1.insert(pii(sz[root_x],root_x));
        
    }
    else {
        // for(int i=0;i<sz[root_y];i++){
        //     std::pair<it,it> ret = m1.equal_range(sz[root_y]);
        //     m1.erase(ret.first);
        // }
        // for(int i=0;i<sz[root_x];i++){
        //     std::pair<it,it> ret = m1.equal_range(sz[root_x]);
        //     m1.erase(ret.first);
        // }
        s1.erase(pii(sz[root_x],root_x));
        s1.erase(pii(sz[root_y],root_y));
        arr[root_x] = root_y;
        sz[root_y]+=sz[root_x];
        s1.insert(pii(sz[root_y],root_y));
    }
}
int main() {
    cin>>n>>k;
    initialize(n);
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        uniwg(x,y);
        it1 = s1.begin();
        it2 = s1.end();
        it2--;
        //cout<<(*it1).first<<' '<<(*it2).first<<endl;
        cout<<(*it2).first - (*it1).first<<endl;
    }
    return 0;
}