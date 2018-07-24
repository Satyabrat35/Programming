#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map<char,int> mp1,mp2;
set<string> s1,s2;
typedef long long int ll;

int main()
{int n;
cin>>n;
ll a[n],b[n],mx=-1,my=-1;
memset(b,0,sizeof(b));
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n;i++){
    if(mx<=a[i]){
        mx=a[i];
        b[i]=1;
    }
}
for(int i=n-1;i>=0;i--){
    if(my<=a[i]){
        my=a[i];
        b[i]=1;
    }
}
for(int i=0;i<n;i++){
    if(b[i]==1){
        cout<<i+1<<' ';
    }
}
return 0;
}
