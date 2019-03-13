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
    bool ispal(string s){
        int l = 0;
        int h = s.length() - 1;
        while(h>l){
            if(s[l++]!=s[h--]){
                return false;
            }
        }
        return true;
    }
            int pal(vector<string> vec,int n){
            int ct=0;
            for(int i=1;i<=n;i++){
                if(!vec[i].empty()){
                bool f = true;
                int l = 0;
                int h = vec[i].length() - 1;
                while(h>l){
                    if(vec[i][l++]!=vec[i][h--]){
                        f=false;
                        break;
                    }
                }
                if(f){
                    ct++;
                }
                else {
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
            int sx = pal(vec,n);
           // cout<<sx<<endl;
            while(q--){
                int x;
                scanf("%d",&x);
                if(x==1){
                    int y,z;
                    cin>>y>>z;
                    int q2 = ((~z)&p)+ (z&(~p));
                    int q1 = ((~p)&y)+ (p&(~y));
                    if(q1<=0){
                    	q1=1;
                    }
                    if(q2<=0){
                    	q2=0;
                    }
                    bool f = ispal(vec[q1]);
                    if(ispal(vec[q2])){
                        sx--;
                    }
                    vec[q1].append(vec[q2]);
                    vec[q2].clear();
                    bool f2 = ispal(vec[q1]);
                    if(f2==true && f==true){
                        cout<<sx<<endl;
                    }
                    else if(f2==true && f==false){
                        sx++;
                        cout<<sx<<endl;
                    }
                    else if(f2==false && f==true){
                        sx--;
                        cout<<sx<<endl;
                    }
                    else {
                        cout<<sx<<endl;
                    }
                }
                else {
                    string c;
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
                    bool f = ispal(vec[q1]);
                    int l = vec[q1].length();
                    if(q2 >= l){
                        vec[q1].append(c);
                    }
                    else {
                        vec[q1].insert(q2,c);
                    }
                    bool f2 = ispal(vec[q1]);
                    if(f2== true && f==true){
                        cout<<sx<<endl;
                    }
                    else if(f2==true && f==false){
                        sx++;
                        cout<<sx<<endl;
                    }
                    else if(f2==false && f==true){
                        sx--;
                        cout<<sx<<endl;
                    }
                    else {
                        cout<<sx<<endl;
                    }
                }
                p = sx;
                //cout<<p<<endl;
            }
         return 0;
        }