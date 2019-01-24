/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
 typedef long long  int ll;
 typedef unsigned long long int ull;
map<int,int> mp1;
//set<int> s1,s2;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int keys[100002];

int main(){
    int key,n,val;
    cin>>key>>val;
    cin>>n;
    int a[n];
    memset(keys,-1,sizeof(keys));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    queue <int> q;
    q.push(key);
    keys[key]=0;
    while(!q.empty()){
        ll f=q.front();
        //cout<<f<<' '<<keys[f]<<endl;
        q.pop();
        if(val==f){
            break;
        }
        for(int i=0;i<n;i++){
            ll z=f*a[i];
            z=z%100000;
            if(keys[z] == -1){
                keys[z]=keys[f]+1;
                //cout<<z<<' '<<keys[z]<<endl;
                q.push(z);
            }
        }
    }
    cout<<keys[val];
    return 0;

}