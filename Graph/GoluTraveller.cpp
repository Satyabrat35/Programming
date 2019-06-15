/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;

//set<string> setter;
//set<int>::iterator it;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
//bool vis[10005];
//vector<string> vec;
int main() {
    ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
    int t;
    cin>>t;
    while(t--){
    map<string,int> mp2,mp3;
    map<string,string> mp1;
    int n;
    cin>>n;
    ll sum=0;
    string start;
    for(int i=0;i<(n-1);i++){
        string s1,s2;
        int x;
        cin>>s1>>s2>>x;
        mp2[s1]=x;
        sum+=x;
        mp1[s1]=s2;
        //setter.insert(s1);
        //setter.insert(s2);
        mp3[s1]++;
        mp3[s2]++;
    }
    for(map<string,int>::iterator tt=mp3.begin();tt!=mp3.end();++tt){
        if(tt->second == 1){
            if(mp2[tt->first]){
                start = tt->first;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        cout<<start<<' '<<mp1[start]<<' '<<mp2[start]<<endl;
        start = mp1[start];
    }
    cout<<sum;
    }
    return 0; 
}