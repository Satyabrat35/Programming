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
    int main() {
        int t;
        cin>>t;
        while(t--){
            string s;
            //stack<char> s1,s2;
            cin>>s;
            int mxmx=-1;
            int l=0,r=0;
            for(int i=0;i<s.size();i++){
                if(s[i]=='('){
                    l++;
                }
                else {
                    r++;
                }
                if(l==r){
                    mxmx = max(mxmx,l*2);
                }
                else if(l<r){
                    l=r=0;
                }
            }
            l=0;r=0;
            for(int i=s.size()-1;i>=0;i--){
                if(s[i]==')'){
                    r++;
                }
                else {
                    l++;
                }
                if(l==r){
                    mxmx = max(mxmx,r*2);
                }
                else if(r<l){
                    l=r=0;
                }
            }
            cout<<mxmx<<endl;
        }
    return 0;
}