/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
typedef unsigned int ul;
//map<int,int> mp1;
//set<int> s1;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
string convertStackToString(stack<char> st)
{
    string str="";
    while(!st.empty())
    {
        char ch = st.top();
        st.pop();
        str+=ch;
    }
    reverse(str.begin(),str.end());
    return str;
}

string solver(string str)
{
    stack<char> st;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]!=']')
            st.push(str[i]);
        else 
        {
            string tempStr = "";
            while(!st.empty() && st.top()!='[')
            {
                char ch = st.top();
                st.pop();
                tempStr+=ch;
            }
            reverse(tempStr.begin(),tempStr.end());
            st.pop();
            string count = "";
            while(!st.empty() && isdigit(st.top()))
            {
                count+=st.top();
                st.pop();
            }
            reverse(count.begin(),count.end());
            int times = stoi(count);
            for(int i=0;i<times;i++)
            {
                for(int j=0;j<tempStr.length();j++)
                {
                    st.push(tempStr[j]);
                }
            }
        }
    }
    return convertStackToString(st);
}

int main() 
{
    int t;
    cin>>t;
    
    while(t--)
    {
        string str;
        cin>>str;
        cout<<solver(str)<<endl;
    }
    
    return 0;
}