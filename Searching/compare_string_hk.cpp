/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
 typedef long long  int ll;
 typedef unsigned long long int ull;
//map<int,int> mp1;
set<int> s1;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
    int n,q;
    cin>>n>>q;
    string a,b;
    cin>>a>>b;
    for(int i=0;i<n;i++){
        if(b[i]=='1' && a[i]=='0'){
            break;
        }
        else if(b[i]=='0' && a[i]=='1'){
            s1.insert(i);
        }
    }
    int cmp=0;
    for(int i=0;i<q;i++){
        int k;
        cin>>k;
        k--;
        if(s1.find(k) != s1.end())
            s1.erase(k);
        if(s1.size()==0)
            cmp=1;
        else
        {
            cmp=0;
        }
        if(cmp){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}