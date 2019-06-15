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
string s[9] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void append(string z,int arr[],int i,int n){
    if(i==n){
        cout<<z<<' ';
        return;
    }
    for(int j=0;j<s[arr[i]-2].size();j++){
        z+=s[arr[i]-2][j];
        append(z,arr,i+1,n);
        z.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int i=0;
        string z = "";
        append(z,arr,i,n);
    }
    return 0;
}