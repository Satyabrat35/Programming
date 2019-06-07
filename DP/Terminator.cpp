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
int lcs(int a[],int b[],int n){
    int arr[1001][1001]={0};

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==b[j])
                arr[i][j] = arr[i-1][j-1] + 1;
            else if(arr[i-1][j]<arr[i][j-1])
                arr[i][j] = arr[i][j-1];
            else
                arr[i][j] = arr[i-1][j];
        }
    }
    return arr[n][n];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[1001]={0},b[1001]={0};
        int x,y;
        for(int i=1;i<=n;i++){
            cin>>x>>y;
            a[x]=i;
            b[y]=i;
        }
        cout<<lcs(a,b,n)<<endl;
    }
    return 0;
}