/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
typedef unsigned int ul;
map<int,int> mp1;
//set<int> s1;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int main() {
    int n;
    cin>>n;

    vector<int> vec(n);
    for(auto it = vec.begin(); it != vec.end(); ++it){
        cin>>*it;
    }
    auto it=vec.begin();
    vector<int>::iterator st,en;
    st = vec.end();
    en = vec.end();
    //int st,en;
    while(it!=vec.end()){
        if(*it%2==0){
            st=it;
        
        while(it!=vec.end() && *it%2==0){
            ++it;
        }
        en=it;
        reverse(st,en);
        }
        if(it!=vec.end()){
            ++it;
        }
    }
    for(auto itt = vec.begin(); itt != vec.end(); ++itt){
        cout<<*itt<<' ';
    }
    return 0;
}