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
const int MXM = 1e6+2;
int arr[MXM];
int binary(int l,int h,int key,int index){
    while(l<=h){
        int mid = (l+h)/2;
        if(arr[mid]>key){
            index = mid;
            l=mid+1;
        }
        else if(arr[mid]<key){
            h=mid-1;
        }
        else {
            index = mid;
            return index;
        }
    }
    return index;
}
int main() {
    int n,q;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=n-2;i>=0;i--){
        arr[i]+=arr[i+1];
    }
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        int k = binary(0,n-1,x,-1);
        if(k!=-1){
        if(k%2==0){
            cout<<"A"<<endl;
        }
        else {
            cout<<"B"<<endl;
        }
        }
    }
    return 0;
}