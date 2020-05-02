/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <math.h>
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
const int N=50000;
int len;
int p[N];

int gcd(int a,int b){
    if(a==0)return b;
    return gcd(b%a, a);
}
int lcm(int a,int b){
    return (a*b)/gcd(a, b);
}
void build(int a, int b)
{
	len = a * b;
	p[0] = 0;
	for(int i = 1; i <= len; i++)
	{
		p[i] = p[i - 1];
		if((i % a) % b != (i % b) % a)
			p[i]++;
	}
}

long long query(long long l)
{
	long long cnt = l / len;
	int rem = l % len;
	return p[len] * 1ll * cnt + p[rem]; 
}

long long query(long long l, long long r)
{
	return query(r) - query(l - 1);
}

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int a, b, q;
		cin >> a >> b >> q;
		build(a, b);
		long long l, r;
		for(int j = 0; j < q; j++)
		{
			cin >> l >> r;
			cout << query(l, r) << " ";
		}
		cout << endl;
	}
}