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
int main()
{
	int t;cin>>t;
	while(t--){
	    int n,count=0,mx=0,flag=1;cin>>n;
	    vector<int>a(n),vis(n+1),vis1(n+1),mm(n+1),ans;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    for(int i=0;i<n;i++){
	        vis[a[i]]++;
	        if(vis[a[i]]==2)count++;
	        if(vis[a[i]]==3){flag=0;break;}
	    }
	    mm[n-1]=a[n-1];
	    for(int i=n-2;i>=0;i--){
	        mm[i]=max(a[i],mm[i+1]);
	    }
	    if(flag==0){
	        cout<<0<<endl;continue;
	    }
	    for(int i=0;i<n;i++){
            vis1[a[i]]++;
	        if(vis1[a[i]]==2)break;
            mx=max(mx,a[i]);
            if(vis[a[i]]==2){
                count--;
            }
            if(count==0 and mx==i+1 and mm[i+1]==n-i-1){
        	   ans.push_back(i);
            }
            vis[a[i]]--;
        }
	    cout<<ans.size()<<endl;
	    for(auto x:ans){
	        cout<<x+1<<" "<<n-x-1<<endl; 
	    }
	}
    

}