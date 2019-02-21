/**************erik****************/
    #include<bits/stdc++.h>
    #include <cstdio>
    #include <iostream>
    #include <algorithm>
    using namespace std;
    typedef long long  int ll;
    typedef unsigned long long int ull;
    //set<int> s1;
    //set<int>::iterator it;
    #define maxm(a,b,c)  max(a,max(c,b))
    #define minm(a,b,c)  min(a,min(c,b))
    #define f(i,n)  for(int i=1;i<n;i++)
    #define rf(i,n) for(int i=n-1;i>=0;i--)
    
    int pal(vector<string> vec,int n,map<string,int> mp1){
        int ct=0;
        for(int i=1;i<=n;i++){
            if(!vec[i].empty()){
            string ss = vec[i];
            reverse(vec[i].begin(),vec[i].end());
            if(ss == vec[i]){
                ct++;
                mp1[ss]=1;
            }
            else {
                mp1[ss]=-1;
                continue;
            }
            }
        }
        return ct;
    }
    int main() {
        int n,q;
        cin>>n>>q;
        vector<string> vec;
        vec.push_back("0");
        for(int i=1;i<=n;i++){
            string ss;
            cin>>ss;
            vec.push_back(ss);
        }
        int p=0;
        map<string,int> mp1;
        int sx = pal(vec,n,mp1);
       // cout<<sx<<endl;
        while(q--){
            int x;
            cin>>x;
            if(x==1){
                bool f = true;
                int y,z;
                cin>>y>>z;
                string ss;
                int q2 = ((~z)&p)+ (z&(~p));
                int q1 = ((~p)&y)+ (p&(~y));
                if(q1<=0){
                	q1=1;
                }
                if(q2<=0){
                	q2=0;
                }
                if(mp1[vec[q1]]==1){
                    f = true;
                }
                else if(mp1[vec[q1]]==-1){
                    f = false;
                }
                else {
                ss = vec[q1];
                reverse(vec[q1].begin(),vec[q1].end());
                if(ss == vec[q1]){
                    f=true;
                }
                else {
                    f = false;
                }
                reverse(vec[q1].begin(),vec[q1].end());
                }
                if(mp1[vec[q2]]==1){
                    sx--;
                }
                else if(mp1[vec[q2]]==-1){
                    sx=sx;
                }
                else if(mp1[vec[q2]]==0){
                string ss2 = vec[q2];
                reverse(vec[q2].begin(),vec[q2].end());
                if(ss2 == vec[q2]){
                    sx--;
                }
                reverse(vec[q2].begin(),vec[q2].end());
                }
                
                vec[q1].append(vec[q2]);
                vec[q2].clear();
                ss = vec[q1];
                reverse(vec[q1].begin(),vec[q1].end());
                if(ss == vec[q1] && f==true){
                    cout<<sx<<endl;
                }
                else if(ss == vec[q1] && f==false){
                    sx++;
                    cout<<sx<<endl;
                }
                else if(ss != vec[q1] && f==true){
                    sx--;
                    cout<<sx<<endl;
                }
                else {
                    cout<<sx<<endl;
                }
                reverse(vec[q1].begin(),vec[q1].end());
            }
            else {
                string c,ss;
                bool f = true;
                int y,z;
                cin>>y>>z>>c;
                int q2 = ((~z)&p)+ (z&(~p));
                int q1 = ((~p)&y)+ (p&(~y));
                q2--;
                if(q1<=0){
                	q1=1;
                }
                if(q2<=0){
                	q2=0;
                }
                if(mp1[vec[q1]]==1){
                    f = true;
                }
                else if(mp1[vec[q1]]==-1){
                    f = false;
                }
                else {
                ss = vec[q1];
                reverse(vec[q1].begin(),vec[q1].end());
                if(ss == vec[q1]){
                    f=true;
                }
                else {
                    f = false;
                }
                int l = vec[q1].length();
                if(q2 >= l){
                    vec[q1].append(c);
                }
                else {
                    vec[q1].insert(q2,c);
                }
                ss = vec[q1];
                reverse(vec[q1].begin(),vec[q1].end());
                if(ss == vec[q1] && f==true){
                    cout<<sx<<endl;
                }
                else if(ss == vec[q1] && f==false){
                    sx++;
                    cout<<sx<<endl;
                }
                else if(ss != vec[q1] && f==true){
                    sx--;
                    cout<<sx<<endl;
                }
                else {
                    cout<<sx<<endl;
                }
                reverse(vec[q1].begin(),vec[q1].end());
            }
            p = sx;
            //cout<<p<<endl;
        }
     return 0;
    }