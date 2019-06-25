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
set<string> ss;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
void permute(string s1,string s2){
    if(s1.size()==0){
        ss.insert(s2);
    }
    for(int i=0;i<s1.size();i++){
        permute(s1.substr(1),s2 + s1[0]);
        rotate(s1.begin(),s1.begin()+1,s1.end());
    }
}
int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        permute(s,"");
        for(auto it=ss.begin();it!=ss.end();++it){
            cout<<*it<<' ';
        }
        ss.clear();
        cout<<endl;
    }
    return 0;
}