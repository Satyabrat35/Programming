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
int calc(string vec){
    int mxm = 0,ct = 0,a = 0;
    int start = 0,end = 0, s=0;
    for(int i=0;i<vec.size();i++){
        if(vec[i]=='A'){
            ct=ct-1;
            a++;
        }
        else {
            ct++;
        }
        if(ct<0){
            ct=0;
            s = i+1;
        }
        else if(mxm<ct){
            mxm=ct;
            start = s;
            end = i;
        }
    }
    //cout<<start<<' '<<end<<endl;
    if(a==vec.size()){
        return vec.size()-1;
    }
    int hog = 0,hoa = 0;
    for(int i=start;i<=end;i++){
        if(vec[i]!='A'){
            hog++;
        }
        else {
            hoa++;
        }
    }
    return a - hoa + hog;
    
}
int main() {
    int t;
    cin>>t;
    while(t--){
    string s;
    cin>>s;
    cout<<calc(s)<<endl;
    }
    return 0;
}