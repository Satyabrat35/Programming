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
const int MAX = 200005;
vector<int> vec[MAX];
int mmmm=0;
int evct[MAX],odct[MAX];
int calc(int st,int en,int n,int ct){
    int x,y,z=0;
    if(en<=st)
        return z;
    if(st<0 || st>=n)
        return z;
    if(en>=n || en<0)
        return z;
    if(vec[st][en]!=-1)
        return vec[st][en];
    if(st!=0){
        x=odct[en]-odct[st-1];
        y=evct[en]-evct[st-1];
        if(x==y){
            z=1;
        }
    }
    else {
        x=odct[en];
        y=evct[en];
        if(x==y){
            z=1;
        }
    }
    mmmm+=z;
    //cout<<st<<' '<<en<<' '<<z<<endl;
    return vec[st][en] = max(calc(st+1,en,n,ct+z),calc(st,en-1,n,ct+z));
    
}
int main() {
    int n;
    cin>>n;
    ll arr[n+1];
    int odd=0,even=0;
    for(int i=0;i<n;i++){
        evct[i]=0;
        odct[i]=0;
        for(int j=0;j<n;j++){
            vec[i].push_back(-1);
        }
    }
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]%2==0){
            even+=1;
        }
        else {
            odd+=1;
        }
        evct[i]+=even;
        odct[i] = odct[i] + odd;
    }
    if(odct[n-1]==evct[n-1]){
        calc(0,n-1,n,1);
    }
    else {
        calc(0,n-1,n,0);
    }
    cout<<mmmm<<endl;
   
    return 0;


}