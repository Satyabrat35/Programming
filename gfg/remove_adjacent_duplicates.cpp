/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
typedef unsigned int ul;
//map<int,int> mp1;
//set<int> s1;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
/* 
void rev(int n,int pos,int val,bool flag){
    if(val==n && pos!=0){
        return;
    }
    else {
        cout<<val<<' ';
        if(val>0 && flag==false){
            rev(n,pos+1,val-5,flag);
        }
        else if(val>0 && flag==true){
            rev(n,pos+1,val+5,flag);
        }
        else {
            flag = true;
            rev(n,pos+1,val+5,flag);
        }
    }
}*/

/*
int main() {
     int t;
    cin>>t;
    while(t--)
    {
        int r,c;
        cin>>r>>c;
        int dp[r][c];
        for(int i=0;i<c;i++)
        {
            dp[0][i]=1;
        }
        for(int i=0;i<r;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];

            }
            }
        cout<<dp[r-1][c-1];
        cout<<endl;
        }    
	return 0;
}*/
int main() {
    int t;
    cin>>t;
    while(t--){
    string s;
    stack<int> ss;
    cin>>s;
    zz:
    string q;
    ss.push(0);
    	for(int i=1;i<s.size();)
	    {
	        if(!ss.empty() and ss.top()+1==i and s[ss.top()]==s[i] )
	        {
	            while(i< s.size() and s[ss.top()]==s[i])
	            {
	                i++;
	            }
	            ss.pop();
	        }
	        else
	        {
	            ss.push(i);
	            i++;
	        }
	    }
    while(!ss.empty()){
        q.push_back(s[ss.top()]);
        ss.pop();
    }
    reverse(q.begin(),q.end());
    if(q==s){
        cout<<q;
    }
    else {
        s=q;
        q.clear();
        goto zz;
    }
    cout<<endl;
    }
    return 0;
}