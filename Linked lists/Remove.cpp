/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
typedef unsigned int ul;
map<int,int> mp1;
//set<int> s1;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int main() {
    int t;
    cin>>t;
    while(t--){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int nw,pos;
    pos=1;
    stack<int> st;
    st.push(0);
    for(int i=1;i<n;i++){
        int crr = a[i];
        if(!st.empty()){
            nw = st.top();
            st.pop();
        
        while(a[nw]<crr){
            a[nw]=-1;
            k-=1;
            if(k==0){
                pos=0;
                break;
            }
            if(!st.empty()){
                nw = st.top();
                st.pop();
            }
            else {
                break;
            }
        }
            if(pos==0){
                break;
            }
            if(a[nw]>=crr){
                st.push(nw);
            }   
        }
        st.push(i);
        
    }
    for(int i=0;i<n-k;i++){
        if(a[i]!=-1){
            cout<<a[i]<<' ';
        }
    }
    cout<<endl;
    }
    return 0;
}