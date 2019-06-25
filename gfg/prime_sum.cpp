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
const ll M = 1e6+1;
vector<ll> prime;
vector<ll> isprime(M,true);
vector<ll> SPF(M);
vector<ll> st;
void sieve(){
    isprime[0]=isprime[1]=false;
    for(ll i=2;i<M;i++){
        if(isprime[i]){
            prime.push_back(i);
            SPF[i] = i;
        }
        for(ll j=0;j < (ll)prime.size() && i*prime[j] < M && prime[j]<=SPF[i];j++){
            isprime[i*prime[j]] = false;
            SPF[i*prime[j]] = prime[j];
        }
    }
}
int main() {
    sieve();
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    ll ss = 0;
    for (int i=0; i<prime.size() && prime[i] <= n ; i++) 
        {
            ss+=prime[i];
        }
    cout<<ss<<endl;    
    }
    return 0;

}