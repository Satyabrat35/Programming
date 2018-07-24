#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
unsigned long long n,m,flag=0,i=0;
cin>>n>>m;

for(int i=62;i>=0;i--)
{
if(m&((unsigned long long int )1<<i))
{
if(flag==0)
cout<<"("<<n<<"<<"<<i<<")";
else
cout<<" + ("<<n<<"<<"<<i<<")";
flag=1;
}
}
cout<<endl;
}
}