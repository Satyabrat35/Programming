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
void computelps(string pat,int m,int* lps);
bool kmp(string pat,string txt){
    int m=pat.length();
    int n=txt.length();
    int lps[m];
    computelps(pat,m,lps);
    int i=0,j=0;
    bool f = false;
    while(i<n){
        if(pat[j]==txt[i]){
            i++;
            j++;
        }
        if(j==m){
            f=true;
            break;
            j=lps[j-1];
        }
        else if(i<n && pat[j]!=txt[i]){
            if(j!=0){
                j=lps[j-1];
            }
            else {
                i = i + 1;
            }
        }
    }
    return f;
}
void computelps(string pat,int m,int* lps){
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<m){
        if(pat[i]==pat[len]){
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
}
int main()
{
    xyz;
    string txt;
    cin>>txt;
    int n,ct=0;
    cin>>n;
    for(int i=0;i<n;i++){
        string pat;
        cin>>pat;
        bool k = kmp(pat,txt);
        if(k==true){
            ct++;
        }
    }
    cout<<ct;
    return 0;

}