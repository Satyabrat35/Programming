/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
//map<int,int> mp1;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int main() {
    int x,y,z;
    char s;
    cin>>y>>s>>z;
    cin>>x;
    int x1,x2,x3,x4;
    x1 = y%10;
    x2 = y/10;
    x3 = z%10;
    x4 = z/10;
int dist = x1+x2+x3+x4;
int f = ceil(dist/x) + 1;
int q = abs(f*x - dist);
int ct = 0;
int f2 = 14-x3-x4;
//cout<<dist<<' '<<f<<' '<<q<<' '<<f2<<endl;
if(q<f2){
    if(q<=(9-x3)){
        cout<<q;
    }
    else {
        ct+=q-9+x3;
        dist = q - x1+x2+x3+ct;
        cout<<(ct-1)*10 + dist + 10-x3<<endl;
    }
}
else {
    ct += q-f2;
    if(ct==1){
        cout<<(ct)*59 + 59 - z<<endl;
    }
    else {
        cout<<(ct-1)*60 + 59 + 59 -z<<endl;
    }

}
// for(int i1=x2;i1<=1;i1++){
//     for(int i2=x1;i2<=9;i2++){
//         for(int i3=x4;i3<=5;i3++){
//             for(int i4=x3;i4<=9;i4++){

//             }
//         }
//     }
// }
return 0;

}