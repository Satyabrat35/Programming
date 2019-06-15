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
int main() {
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int a[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>0){
            sum+=a[i];
        }
    }
    if(sum==0){
    int tot_max=a[0];
    //int curr_max=a[0];
    for(int i=1;i<n;i++){
        tot_max = max(a[i],tot_max);
    }
    cout<<tot_max<<' '<<tot_max<<endl;
    }
    else {
        int max_so_far = 0;
        int max_end_here = 0;
        for(int i=0;i<n;i++){
            max_end_here+=a[i];
            if(max_end_here<0){
                max_end_here = 0;
            }
            else if(max_so_far < max_end_here){
                max_so_far = max_end_here;
            }
        }
        cout<<max_so_far<<' '<<sum<<endl;
    }
    }
    //cout<<tot_max<<endl;
    return 0;
}