/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
//set<int> s1,s2;
//map<int,int> mp1,mp2;
//set<int>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define xyz  ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
void comlps(char s[],int x){
    int len=0,i=1;
    int lps[x+1];
    lps[0]=0;
    while(i<x){
        if(s[i]==s[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else {
            if(len!=0){
                len=lps[len-1];
            }
            else {
                lps[i]=0;
                i++;
            }
        }
    }
    int j;
    for(j=i-1;j>=0;j--){
        if(lps[j]==1){
            break;
        }
    }
    if(lps[x-1]%j==0 && lps[x-1]!=0){
        cout<<j<<endl;
    }
    else {
        cout<<x<<endl;
    }
}
int main()
{
    int t;
    cin>>t;
    char s[100001];
    while(t--){
        cin>>s;
        int x = strlen(s);
        comlps(s,x);
    }
    return 0;
}