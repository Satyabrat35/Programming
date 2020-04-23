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
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<int> vec(201,0);
    int a[n];
    int ans = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        vec[a[i]]++;
        ans = max(ans,vec[a[i]]);
    }
    for(int i=1;i<=200;i++){
        vector<int> ves(201);
        for(int j=0;j<=200;j++)ves[j]=vec[j];
        int l = -1;
        int r = n;
        while (ves[i]>=2)
        {
            for(int j=l+1;j<n;j++){
                ves[a[j]]--;
                if(a[j]==i){l=j;break;}
            }
            for(int j=r-1;j>=0;j--){
                ves[a[j]]--;
                if(a[j]==i){r=j;break;}
            }
            for(int j=1;j<=200;j++){
                //cout<<ves[i]<<' ';
                ans = max(ans, vec[i]-ves[i]+ves[j]);
            }
        }
        
    }
    cout<<ans<<endl;
    
}
return 0;
}