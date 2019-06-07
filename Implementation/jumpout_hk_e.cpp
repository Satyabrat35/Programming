/**************erik****************/
#include<bits/stdc++.h>
using namespace std;
 typedef long long int ll;
//map<char,int> mp1,mp2;
//set<string> s;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=0;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
//multiset<ll> ms;
//multiset<ll>::iterator t;
int main()
{int n;
cin>>n;
int a[n],mn=1e4+1;
for(int i=1;i<=n;i++)
    {cin>>a[i];
    if(i+a[i]>n)
    {
        mn=min(mn,i);
    }
    }
    cout<<mn;
return 0;
}
