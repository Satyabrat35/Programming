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
bool pal(string s){
    int l=0;
    int h=s.size()-1;
    while(h>l){
        if(s[l++] != s[h--]){
            return false;
        }
    }
    return true;
}
void sub(string s,int n){
    for(int i=0;i<n;i++){
        for(int len = 1;len<=n-i;len++){
            string z = s.substr(i,len);
            if(pal(z)==true){
                ss.insert(z);
            }
            }
        }
    }
int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        sub(s,s.size());
        cout<<ss.size()<<endl;
        ss.clear();
    }
    return 0;
}
