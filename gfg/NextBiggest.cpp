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
            int n;
            cin>>n;
            stack<ll> s1,s2;
            ll arr[n];
            for(int i=0;i<n;i++){
                cin>>arr[i];
            }
            s1.push(arr[n-1]);
            s2.push(-1);
            int mx = arr[n-1];
            for(int i=n-2;i>=0;i--){
                if(arr[i]<s1.top()){
                    s2.push(s1.top());
                    s1.push(arr[i]);
                }
                else {
                    if(arr[i]>mx){
                        mx=arr[i];
                        s2.push(-1);
                        while(!s1.empty()){
                        s1.pop();
                    }
                    }
                    else {
                        while(arr[i]>s1.top()){
                            s1.pop();
                        }
                        s2.push(s1.top());
                    }
                    //mx = arr[i];
                    s1.push(arr[i]);
                }
            }
            while(!s2.empty()){
                cout<<s2.top()<<' ';
                s2.pop();
            }        
            cout<<endl;
        }
        return 0;
    }