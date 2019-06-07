/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;

//set<int> s1;
//set<int>::iterator it;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
const int MAX = 100005;
int arr[100005];
int sz[100005];
int n,k;
void initialize(){
    for(int i=1;i<=MAX;i++){
        arr[i]=i;
        sz[i]=1;
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
        arr[root_y] = root_x;
        sz[root_x]+=sz[root_y];
    }
    else {
        arr[root_x] = root_y;
        sz[root_y]+=sz[root_x];
    }
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
    cin>>k;
    int ct=1;
    initialize();
    unordered_map<string,int> mp1;
    for(int i=0;i<k;i++){
        string s1,s2;
        cin>>s1>>s2;
        if(mp1[s1]==0){
            mp1[s1]=ct;
            ct++;
        }
        if(mp1[s2]==0){
            mp1[s2]=ct;
            ct++;
        }
        uniwg(mp1[s1],mp1[s2]);
        cout<<sz[root(mp1[s1])]<<endl;
    }
    }
    return 0;
}