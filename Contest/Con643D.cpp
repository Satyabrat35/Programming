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
ll rou(ll n){
    int mn=11;
    int mx=-1;
    ll k = n;
    while(k>0){
        int z = k%10;
        mn = min(mn,z);
        mx = max(mx,z);
        k/=10;
    }
    return (n + mx*mn);
}
int main()
{
    
        int n,k;
        cin>>n>>k;
        vector<int> vec;
        if(n>=k){
            cout<<"NO"<<endl;
            
        }
        int p = n-1;
        int sum = 0;
        for(int i=1;i<=(n-1);i++){
            vec.push_back(i);
            sum+=i;
        }
        if(k - sum <= (n-1)){
            cout<<"NO"<<endl;
            //continue;
        }
        cout<<"YES"<<endl;
        vec.push_back(k - sum);
        for(int i=0;i<vec.size();i++)cout<<vec[i]<<' ';
        cout<<endl;
        cout<<sum<<endl;
        
    
}