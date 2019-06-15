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
const int MAX = 100005;
set<pair<int,int>> sp;
int arr[MAX];
pair<ll,pair<int,int>> p[MAX];
int n,m,q;
void initialize(int n){
    for(int i=1;i<=n+1;i++){
        arr[i]=i;
    }
}
int root(int x){
    while(arr[x] != x){
        arr[x] = arr[arr[x]];
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
    
    arr[root_x] = arr[root_y];
    
}
void kruskal_man(pair<ll,pair<int,int>> p[]){
    int x,y;
    int cost;
    for(int i=0;i<m;i++){
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x)!=root(y) && cost==3){
            sp.insert(make_pair(min(x,y),max(x,y)));
            uniwg(x,y);
        }
        else if(root(x)!=root(y) && cost==1){
            sp.insert(make_pair(min(x,y),max(x,y)));
            uniwg(x,y);
        }
        else {
            continue;
        }
    }
    //return minCost;
}
void kruskal_woman(pair<ll,pair<int,int>> p[]){
    int x,y;
    int cost;
    for(int i=0;i<m;i++){
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x)!=root(y) && cost==3){
            sp.insert(make_pair(min(x,y),max(x,y)));
            uniwg(x,y);
        }
        else if(root(x)!=root(y) && cost==2){
            sp.insert(make_pair(min(x,y),max(x,y)));
            uniwg(x,y);
        }
        else {
            continue;
        }
    }
    //return minCost;
}
int main() {
    cin>>n>>m;
    initialize(n);
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        p[i] = make_pair(z,make_pair(x,y));
    }
    bool con = true;
    sort(p,p+m);
    reverse(p,p+m);
    kruskal_man(p);
    int l = root(1);
    for(int i=1;i<=n;i++){
        if(l!=i && root(i)!=l){
            con = false;
            break;
        }
    }
    initialize(n);
    kruskal_woman(p);
    /*for(auto it=sp.begin();it!=sp.end();++it){
        cout<<it->first<<' '<<it->second<<endl;
    }*/
    l = root(1);
    for(int i=1;i<=n;i++){
        if(l!=i && root(i)!=l){
            con = false;
            break;
        }
    }
    if(con){
        cout<<m-sp.size()<<endl;
    }
    else {
        cout<<"-1"<<endl;
    }
    return 0;
}