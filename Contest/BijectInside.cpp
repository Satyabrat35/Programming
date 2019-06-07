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
const ll M = 1e9+7;
map<ll, ll> F;
map<ll, ll> P;
ll fibo(ll n) {
	if (F.count(n)) return F[n];
	ll k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (fibo(k)*fibo(k) + fibo(k-1)*fibo(k-1)) % M;
	} else { // n=2*k+1
		return F[n] = (fibo(k)*fibo(k+1) + fibo(k-1)*fibo(k)) % M;
	}
}
ll power(ll y) 
{ 
    if(P[y]!=0){
        return P[y];
    }
    ll res = 1;    
    ll x = 2;
    
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % M; 
  
        y = y>>1; 
        x = (x*x) % M;   
    } 
    P[y] = res;
    return res; 
} 
ll fast_pow(ll base, ll n) 
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    ll halfn=fast_pow(base,n/2);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}
ll findMMI_fermat(ll n)
{
    return fast_pow(n,M-2);
}
int main() {
    P[0]=1;
    P[1]=2;
	F[0]=F[1]=1;
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a = ((power(n)%M) - (fibo(n)%M) + M)%M;
        ll b = power(n)%M;
        ll c = findMMI_fermat(b);
        
        //cout<<fibo(n)<<endl;
        //cout<<a<<endl;
        //cout<<b<<endl;
        //cout<<c<<endl;
        cout<<(c*a)%M<<endl;
    }
    return 0;
}
//ans=( 2^n-fib(n) )/(2^n)
