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
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        stack<int> s;
        s.push(0);
        int S[n];
        S[0]=1;
        for(int i=1;i<n;i++){
            while(!s.empty() && arr[s.top()] <= arr[i]){
                s.pop();
            }
            if(s.empty()){
                S[i] = i+1;
            }
            else {
                S[i] = i-s.top();
            }
            s.push(i);
        }
        for(int i=0;i<n;i++){
            cout<<S[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}