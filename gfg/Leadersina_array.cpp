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
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int main()
{
        int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
    int a[n],b[n];
    bool find[n] = {0};
    find[n-1] = 1;
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
    b[n-1] = a[n-1];
	for(int i=n-2;i>=0;i--){
        if(a[i]>=b[i+1]){
            find[i]=1;
        }
        b[i] = max(a[i],b[i+1]);
           
    }
    for(int i=0;i<n;i++){
        if(find[i]){
            cout<<a[i]<<' ';
        }
    }
    cout<<endl;
    }
	return 0;
}