/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long int ll;
typedef unsigned long long int ull;
map<int,int> mp1;
//set<int> s1,s2;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
const int MX = 1005;
pair<int,pair<int,int>> vec[MX];
long double dist(int x,int y){
    long double q = (vec[x].second.first - vec[y].second.first)*(vec[x].second.first - vec[y].second.first) + (vec[x].second.second - vec[y].second.second)*(vec[x].second.second - vec[y].second.second);
    return sqrt(q);
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<2*n;i++){
        int x,y;
        cin>>x>>y;
        vec[i] = make_pair(0,make_pair(x,y));
    }
    
    long double sum = 1e7;
    int ct1=0,ct2=0;
    for(int j=0;j<2*n;j++){
        long double ans = 0;
        long double ct=10000;
        int pos=-1,i=j;
        ct1=0;
    while(ct1<2*n){
        ct2=0;
        ct=10000;
        pos=-1;
        if(i==2*n){
            i=0;
        }
        int k=i+1;
        while(ct2<2*n){
            if(k==2*n){
                k=0;
            }
            //cout<<"hola!"<<' '<<dist(i,k)<<' ';
            if(dist(i,k)<ct && k!=i && vec[i].first!=1 && vec[k].first!=1){
                ct = dist(i,k);
                pos = k;   
            }
            k++;
            ct2++;
        }
        //cout<<ct<<' '<<pos<<endl;
        if(ct!=10000){
            ans+=ct;
        }
        vec[i].first = 1;
        vec[pos].first = 1;
        i++;
        ct1++;
    }
    sum=min(sum,ans);
    for(int l=0;l<2*n;l++){
        vec[l].first=0;
    }
    }
    cout<<fixed<<setprecision(6)<<sum<<endl;
    return 0;
}