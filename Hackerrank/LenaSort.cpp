/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
#define MAX 100005
ll mini[MAX],maxi[MAX];
ll minx(ll a,ll b){
    return a<b?a:b;
}
void search(int val,int len,ll z){
    if(len==0)return;
    if(len==1){
        cout<<val+1;
        return;
    }
    int a,b,m;
    int h = (len+1)/2;
    int l = 1;
    z-=(len-1);
    while(l<=h){
        m = (l+h)/2;
        a = m-1;
        b = len-m;
        if(mini[a]+mini[b]>z)l=m+1;
        else if(maxi[a]+maxi[b]<z)h=m-1;
        else break;
    }
    int ca=mini[a];
    int cb=mini[b];
    z-= mini[a]+mini[b];
    if(z!=0){
        int p = min(maxi[a]-ca,z);
        ca+=p;
        z-=p;
    }
    if(z!=0){
        int p =min(maxi[b]-cb,z);
        cb+=p;
        z-=p;
    }
    cout<<val+m;
    search(val,a,ca);
    search(val+m,b,cb);

}
int main()
{
    mini[0]=0;
    for(int i=1;i<MAX;i++){
        mini[i] = (i-1) + mini[(i-1)/2] + mini[i-1-(i-1)/2];
        maxi[i] = (ll)i*(i-1)/2;
    }
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(b<mini[a] || b>maxi[a]){
            cout<<-1;
        }
        else {
            search(0,a,b);
        }
        cout<<endl;
    }
}