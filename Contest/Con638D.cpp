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
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        vector<int> vec;
        int n;
        cin>>n;
        for(int i=1;i<=n;i*=2){
            vec.push_back(i);
            n-=i;
        }
        if(n>0){
            vec.push_back(n);
            sort(vec.begin(),vec.end());
        }
        cout<<vec.size()-1<<endl;
        for(int i=1;i<vec.size();i++){
            cout<<vec[i]-vec[i-1]<<' ';
        }
        cout<<endl;
    }
    return 0;
}