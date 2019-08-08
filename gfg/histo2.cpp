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
            vector<ll> vec(n);
            for(int i=0;i<n;i++){
                cin>>vec[i];
            }
            stack<ll> s;
            int i=0,cur;
            ll area,max_area=-1;
            while(i<=n){
                if(i==n){
                    while(!s.empty()){
                        cur = s.top();
                        s.pop();
                        if(s.empty()){
                            area = vec[cur]*i;
                            if(area>max_area){
                                max_area = area;
                            }
                        }
                        else {
                            area = vec[cur]*(i-s.top()-1);
                            if(area>max_area){
                                max_area = area;
                            }
                        }
                    }
                }
                else {
                    if(s.empty()||vec[i]>=vec[s.top()])
                        s.push(i);
                    else {
                        while(!s.empty() && vec[s.top()] >= vec[i]){
                            cur = s.top();
                            s.pop();
                            if(s.empty()){
                                area = vec[cur]*i;
                                if(area>max_area){
                                    max_area = area;
                                }
                            }
                            else {
                                area = vec[cur]*(i-s.top()-1);
                                if(area>max_area){
                                    max_area = area;
                                }
                            }
                        }
                        s.push(i);
                    }
                }
                i++;
            }
            cout<<max_area<<endl;
        }
        return 0;
    }