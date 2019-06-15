#include<bits/stdc++.h>
using namespace std;
void calc_span(int a[],int n,int s[])
{
stack<int>st;
st.push(0);
s[0]=1;
cout<<s[0]<<" ";
for(int i=1;i<n;i++)
{
while(!st.empty()&&a[st.top()]<=a[i])
st.pop();
s[i]=(st.empty())?(i+1):(i-st.top());
cout<<s[i]<<" ";
st.push(i);
}
}
int main()
{
int n,t,i;
cin>>t;
while(t--)
{
cin>>n;
int a[n],s[n];
for(i=0;i<n;i++)
cin>>a[i];
calc_span(a,n,s);
cout<<endl;
}
return 0;
}