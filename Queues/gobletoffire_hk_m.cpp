
/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
 typedef long long int ll;
//map<char,int> mp1,mp2;
//set<string> s;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
using namespace std;

int main()
{ int q;
    cin>>q;
    queue<int> qu[5],qu1;
    for(int i=0;i<q;i++){
        char c;
        int x,y;
        cin>>c;
        if(c=='E'){
            cin>>x>>y;
            if(qu[x].empty())
                qu1.push(x);
            qu[x].push(y);
        }
        else {
            int tp=qu1.front();
            cout<<tp<<' '<<qu[tp].front()<<endl;
            qu[tp].pop();
            if(qu[tp].empty())
                qu1.pop();
        }
    }
   return 0;
}
