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
void valid(int a[],int b[],int n){
    int ar[2] = {0};

    for(int i=0;i<n;i++){
        if(a[i]>b[i] && !ar[0]){
            cout<<"NO"<<endl;
            return;
        } 
        else if (a[i]<b[i] && !ar[1]){
            cout<<"NO"<<endl;
            return;
        }
        if(a[i]==-1){
            ar[0]=1;
        }
        if(a[i]==1){
            ar[1]=1;
        }
    }
    cout<<"YES"<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        valid(a,b,n);
    }
    return 0;
}