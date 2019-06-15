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
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x7,x3,x5,x2,y3,y5,y7,y2;
        x7 = n/7;
        y7 = n%7;
        x5 = y7/5;
        y5 = y7%5;
        x3 = y5/3;
        y3 = y5%3;
        x2 = y3/2;
        y2 = y3%2;
        //cout<<x7<<' '<<x5<<' '<<x3<<' '<<x2<<endl;
        if(n==1){
            cout<<"-1"<<endl;
            continue;
        }
        cout<<x7+x5+x3+x2+y2<<endl;
    }
    return 0;
}