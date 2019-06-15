/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
//set<int> s1;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
double calc(double a[],double pos,int n){
    double x = 0;
    for(int i=0;i<n;i++){
        x+= 1/(pos-a[i]);
    }
    //cout<<x<<' ';
    return x;
}
double binary(double a[],double l,double r,int n){
    while(l<r){
        double mid = (l-r)*0.50 + r;
        double val = calc(a,mid,n);
        if(abs(val)<0.0000000000001){
            return mid;
        }
        else if(val>0){
            l = mid;
        }
        else {
            r = mid;
        }
    }
    return l;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        double a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=1;i<n;i++)
	    {
	        printf("%0.2f ", binary(a,a[i-1],a[i],n));
	    }
	    cout<<endl;
    }
    return 0;
}