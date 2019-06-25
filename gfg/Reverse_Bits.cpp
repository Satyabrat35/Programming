/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
typedef unsigned int ul;
//map<int,int> mp1;
//set<int> s1;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
ul bitreverse(ul n){
    ul count = sizeof(n)*8 - 1;
    ul rev = n;
    n >>= 1;
    while(n){
        rev <<=1;
        rev |=  n & 1;
        n >>= 1;
        count--;
    } 
    rev <<= count;
    return rev;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        ul n;
        cin>>n;
        cout<< bitreverse(n)<<endl;
    }
    return 0;
}