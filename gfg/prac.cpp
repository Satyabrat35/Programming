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
        int n,e;
        cin>>n>>e;
        vector<int> v[n+1];
        for(int i=0;i<e;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        int q;
        cin>>q;
        while(q--){
            int a,t;
            cin>>a>>t;
            int ct=0;
            vector<int> vec(n+1,-1);
            queue<int> q;
            q.push(a);
            vec[a]=0;
            while(!q.empty()){
                int z = q.front();
                q.pop();
                for(int i=0;i<v[z].size();i++){
                    if(vec[v[z][i]]==-1){
                        vec[v[z][i]]=vec[z]+1;
                        if(vec[v[z][i]]==t){
                            ct++;
                        }
                        q.push(v[z][i]);
                    }
                }
            }
            cout<<ct;
        }
    }