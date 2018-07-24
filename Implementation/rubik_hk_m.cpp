#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map<char,int> mp1,mp2;
set<string> s1,s2;
typedef long long int ll;

int main()
{int n,r,c;
cin>>n>>r>>c;
int a[n+1][n+1];
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
     cin>>a[i][j];
    }
}
for(int i=0;i<r;i++){
    int x;
    cin>>x;
    int temp = a[x][n];
    for(int j=n;j>1;j--){
        a[x][j]=a[x][j-1];
    }
    a[x][1]=temp;
}
for(int i=0;i<c;i++){
    int x;
    cin>>x;
    int temp = a[n][x];
    for(int j=n;j>1;j--){
        a[j][x] = a[j-1][x];
    }
    a[1][x]=temp;
}
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        cout<<a[i][j]<<" ";
    }
    cout<<endl;
}

return 0;
}
