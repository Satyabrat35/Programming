#include <iostream>
#include <set>
#include <bits/stdc++.h>
using namespace std;
map<char,int> mp1,mp2;
std::set<char> s1,s2;
typedef long long int ll;
int main() {
    int t;
    cin>>t;
    while(t){
int b;
cin>>b;
ll psum=1,nsum=1;
for(int i=1;i<=b;i++){
char a;
int x;
cin>>a;
if(a=='+'){
    cin>>x;
    //cout<<"gh";
    psum = max(psum,max(psum+x,nsum+x));
    nsum = min(nsum,min(psum+x,nsum+x));
    //cout<<psum<<' '<<nsum<<endl;
}
if(a=='-'){
    cin>>x;
    //cout<<"gh";
    psum = max(psum,max(psum-x,nsum-x));
    nsum = min(nsum,min(psum-x,nsum-x));
    //cout<<psum<<' '<<nsum<<endl;
}
if(a=='/'){
    cin>>x;
    psum = max(psum,max(psum/x,nsum/x));
    nsum = min(nsum,min(psum/x,nsum/x));
    //cout<<psum<<' '<<nsum<<endl;
}
if(a=='*'){
    cin>>x;
    psum = max(psum,max(psum*x,nsum*x));
    nsum = min(nsum,min(psum*x,nsum*x));
    //cout<<psum<<' '<<nsum<<endl;
}
if(a=='N'){
        //cout<<"gh";
    psum = max(psum,max(-psum,-nsum));
    //psum = max(psum,-nsum);
    nsum = min(nsum,min(-psum,-nsum));
    //cout<<psum<<' '<<nsum<<endl;
}
}
cout<<max(psum,nsum)<<endl;
t--;
    }

return 0;
}
