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
bool ateallmybeans(pair<int,int> &a, pair<int,int> &b){
    if(a.second == b.second){
        return a.first>b.first;
    }
    return a.second>b.second;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector <int> v[1002];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        vector <pair<int, int>> vec;
        for(int j=0;j<v[i].size();j++){
            int a = v[i][j];
            int b = arr[a-1];
            vec.push_back(make_pair(a,b));
        }
        sort(vec.begin(),vec.end(),ateallmybeans);
        if(vec.size()>=k){
            cout<<vec[k-1].first<<endl;
        }
        else {
            cout<<"-1"<<endl;
        }
    }
    
    return 0;
}