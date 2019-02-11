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
#define rf(i,n) for(int i=n-1;i>=0;i--)
int main() {
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    ll arr[n+1],dep[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i]>>dep[i];
        dep[i]=dep[i]-1;
    }
    sort(arr,arr+n);
    sort(dep,dep+n);
    int i=1,j=0;
    int max_theory=1,in_theory=1;
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            in_theory++;
            if(in_theory>max_theory){
                max_theory=in_theory;
            }
            i++;
        }
        else {
            in_theory--;
            j++;
        }
    }
    cout<<max_theory<<endl;
    
    }
    return 0;
}