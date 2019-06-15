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
int arr[2] = {10,12};
int val[120];
int calc(int n){
    if(val[n]!=-1){
        return val[n];
    }
    int rooms[n+1];
    for(int i=1;i<=n;i++){
        rooms[i] = 1e6;
    }
    rooms[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++){
            if(arr[j]<=i){
                int x = rooms[i - arr[j]];
                if(x!=1e6 && x+1<rooms[i]){
                    rooms[i]=x+1;
                }
            }
        }
    }
    if(rooms[n]==1e6){
        val[n]=-1;
        return -1;
    }
    val[n] = rooms[n];
    return rooms[n];
}
int main() {
    memset(val,-1,sizeof(val));
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    cout<<calc(n)<<endl;
    }
    return 0;
}