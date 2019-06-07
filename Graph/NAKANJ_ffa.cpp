/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
//map<int,int> mp1;
//set<int> s1,s2;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int main() {
    vector<pair<int,int>> vec[80][80];
    int a[9][9],dist[9][9];
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            if(i-2>0 && j-1>0){
                vec[i][j].push_back({i-2,j-1});
            }
            if(i-2>0 && j+1<9){
                vec[i][j].push_back({i-2,j+1});
            }
            if(i+2<9 && j-1>0){
                vec[i][j].push_back({i+2,j-1});
            }
            if(i+2<9 && j+1<9){
                vec[i][j].push_back({i+2,j+1});
            }
            if(i-1>0 && j-2>0){
                vec[i][j].push_back({i-1,j-2});
            }
            if(i+1<9 && j-2>0){
                vec[i][j].push_back({i+1,j-2});
            }
            if(i-1>0 && j+2<9){
                vec[i][j].push_back({i-1,j+2});
            }
            if(i+1<9 && j+2<9){
                vec[i][j].push_back({i+1,j+2});
            }
            dist[i][j]=501;
        }
    }
    int t;
    cin>>t;
    while(t--){
    string b,c;
    cin>>b>>c;
    int x1,x2,y1,y2;
    x1 = b[0]-96;
    x2 = b[1]-48;
    y1 = c[0]-96;
    y2 = c[1]-48;
    //cout<<x1<<' '<<x2<<endl;
    queue<pair<int,int>> q;
    q.push({x1,x2});
    dist[x1][x2]=0;
    while(!q.empty()){
        int z1 = q.front().first;
        int z2 = q.front().second;
        q.pop();
        for(int i=0;i<vec[z1][z2].size();i++){
            int z3 = vec[z1][z2][i].first;
            int z4 = vec[z1][z2][i].second;
            if(dist[z3][z4] > dist[z1][z2] + 1){
                dist[z3][z4] = dist[z1][z2]+1;
                q.push({z3,z4});
            }
        }
    }
    cout<<dist[y1][y2]<<endl;
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            dist[i][j]=501;
        }
    }
    }
return 0;
}