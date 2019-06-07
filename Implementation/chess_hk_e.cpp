/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
 typedef long long  int ll;
 typedef unsigned long long int ull;
//map<char,int> mp1,mp2;
set<int> s1,s2;
set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int bd[11][11];
int fd(int x,int y,int n)
{
int temp = 0;
if(n==0)
    return 0;
if(x>10 || x<1 || y>10 || y<1)
    return 0;
if(bd[x][y]==1 && n==1)
    return 0;
if(n==1){
    temp = 1;
    bd[x][y] = 1;
}
return temp + fd(x-2,y-1,n-1) + fd(x-1,y-2,n-1) + fd(x-2,y+1,n-1) + fd(x-1,y+2,n-1) + fd(x+1,y-2,n-1) + fd(x+2,y-1,n-1) + fd(x+2,y+1,n-1) + fd(x+1,y+2,n-1);
}
int main()
{
    int x,y,n;
    cin>>x>>y>>n;
    cout<<fd(x,y,n+1);
    return 0;
}
