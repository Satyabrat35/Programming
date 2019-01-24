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
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> v[n+1];
    vector<int> lv(n+1,-1);
    
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    queue<int> q;
    q.push(0);
    lv[0]=0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<v[x].size();i++){
            if(lv[v[x][i]]==-1){
                lv[v[x][i]] = lv[x] + 1;
                q.push(v[x][i]);
            }
        }
    }
    for(int i=1;i<n;i++){
        cout<<lv[i]<<endl;
    }
    return 0;

}