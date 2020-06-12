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
#define f(i,n)  for(ll i=0;i<n;i++)
#define rf(i,n) for(ll i=n-1;i>=0;i--)
const int mx = 100002;
int q;
vector<string> ss(mx);
vector<char> vec;
void dfs(int i, int a, int b, int c){
    if(a<0||b<0||c<0)return;
    if(i==q){
        cout<<"Yes"<<endl;
        f(i,q)cout<<vec[i]<<endl;
        exit(0);
    }
    if(ss[i]=="AB"){
        vec.push_back('A');
        dfs(i+1,a+1,b-1,c);
        vec.pop_back();
        vec.push_back('B');
        dfs(i+1,a-1,b+1,c);
        vec.pop_back();
    } else if(ss[i]=="AC"){
        vec.push_back('A');
        dfs(i+1,a+1,b,c-1);
        vec.pop_back();
        vec.push_back('C');
        dfs(i+1,a-1,b,c+1);
        vec.pop_back();
    } else {
        vec.push_back('C');
        dfs(i+1,a,b-1,c+1);
        vec.pop_back();
        vec.push_back('B');
        dfs(i+1,a,b+1,c-1);
        vec.pop_back();
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin>>q;
    int a,b,c;
    cin>>a>>b>>c;
    f(i,q)cin>>ss[i];
    dfs(0,a,b,c);
    cout<<"No"<<endl;
}