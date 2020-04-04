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
//set<string> ss;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
const int mxm = 1e6+1;
vector<int> vec[mxm];
void cal(int n){
vec[0].push_back(0);
vec[1].push_back(0);
if(vec[n].size()!=0){
    return;
}
for(int i=2;i<=12;i++){
    int ct = 0;
    int x = i;
    while(x%2==0){
        ct+=2;
        x/=2;
    }
    for(int j=3;j<=sqrt(x);j+=2){
        while(x%j==0){
            ct+=j;
            x=x/j;
        }
    }
    if(x>2){
        ct+=x;
    }
    cout<<i<<' '<<ct<<' ';
    vec[i].push_back(ct);
}
}
int main() {
	// your code goes here
	cal(10);
	cout<<vec[12][0];
	return 0;
}