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
char g1[] = {'G','R','B'};
char g2[] = {'R','G','B'};
char g3[] = {'G','B','R'};
char g4[] = {'B','R','G'};
char g5[] = {'R','B','G'};
char g6[] = {'B','G','R'};
int n;
int check(string g,string q){
    int ct=0;
    for(int i=0;i<n;i++){   
        if(g[i]!=q[i]){
            ct++;
        }
    }
    return ct;
}
int main() {
    cin>>n;
    string s,r1,r2,r3,r4,r5,r6;
    cin>>s;
    for(int i=0;i<n;i++){
        r1+=g1[i%3];
        r2+=g2[i%3];
        r3+=g3[i%3];
        r4+=g4[i%3];
        r5+=g5[i%3];
        r6+=g6[i%3];
    }
    int mn = n+1,ans;
    if(check(r1,s)<mn){
        ans = 1;
        mn = check(r1,s);
    }
    if(check(r2,s)<mn){
        ans = 2;
        mn = check(r2,s);
    }
    if(check(r3,s)<mn){
        ans = 3;
        mn = check(r3,s);
    }
    if(check(r4,s)<mn){
        ans = 4;
        mn = check(r4,s);
    }
    if(check(r5,s)<mn){
        ans = 5;
        mn = check(r5,s);
    }
    if(check(r6,s)<mn){
        ans = 6;
        mn = check(r6,s);
    }
    cout<<mn<<endl;
    if(ans==1){
        cout<<r1;
    }
    else if(ans==2){
        cout<<r2;
    }
    else if(ans==3){
        cout<<r3;
    }
    else if(ans==4){
        cout<<r4;
    }
    else if(ans==5){
        cout<<r5;
    }
    else {
        cout<<r6;
    }
    return 0;
}