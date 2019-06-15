/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
map<int,int> mp1;
//set<int> s1,s2;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
const int MAX = 1000010;
int main() {
    int t;
    cin>>t;
    while(t--){
    int n,r,m;
    cin>>n>>r>>m;
    bool f = true;
    vector<int> vec[MAX];
    for(int i=0;i<r;i++){
        int x,y;
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    bool vis[MAX];
    int gaurd[MAX],lev[MAX];
    for(int i=1;i<=n;i++){
        vis[i]=0;
        gaurd[i]=0;
        lev[i]=0;
    }
    for(int k=0;k<m;k++){
        int x,strength;
        cin>>x>>strength;
        queue<int> q;
        q.push(x);
        lev[x]=0;
        vis[x]=1;
        while(!q.empty()){
            int a = q.front();
            if(gaurd[a]==1){
            	f = false;
            	break;
            }
            if(lev[a]>strength){
            	break;
            }
            q.pop();
            for(int i=0;i<vec[a].size();i++){
                if(vis[vec[a][i]]==0){
                    lev[vec[a][i]]=lev[a]+1;
                    if(lev[vec[a][i]]<=strength){
                    	vis[vec[a][i]]=1;
                    }
                    q.push(vec[a][i]);
                }
            }
            gaurd[a]=1;
        }
        if(!f){
        	break;
        }
    }
    
    for(int i=1;i<=n;i++){
        if(gaurd[i]==0 || vis[i]==0){
            f = false;
            break;
        }
    }
    if(f){
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
    //cout<<endl;
}
    return 0;
}