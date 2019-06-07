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
const int MAX = 3000005;
vector<int > vec[MAX];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        if(x==1){
            int y,z;
            cin>>y>>z;
            vec[y].push_back(z);
            vec[z].push_back(y);
        }
        else {
            int y;
            cin>>y;
            if(vec[y].size()==0){
                cout<<"0"<<endl;
                continue;
            }
            else {
            int dis[n+1];
            bool vis[n+1];
            for(int i=1;i<=n+1;i++){
                vis[i]=0;
                dis[i]=0;
            }
            queue<int> q;
            q.push(y);
            dis[y]=0;
            while(!q.empty()){
                int a = q.front();
                vis[a]=true;
                q.pop();
                for(int i=0;i<vec[a].size();i++){
                    if(vis[vec[a][i]]==0){
                        dis[vec[a][i]]=dis[a] + 1;
                        q.push(vec[a][i]);
                        vis[vec[a][i]]=true;
                    }
                }
            }
            int pos = max_element(dis+1,dis+n+1) - dis;
            cout<<dis[pos]<<endl;
        }
        }
    }
    return 0;
}