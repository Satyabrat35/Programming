<<<<<<< HEAD
    /**************erik****************/
    #include<bits/stdc++.h>
    #include <cstdio>
    #include <iostream>
    #include <algorithm>
    using namespace std;
    typedef long int ll;
    typedef unsigned long long int ull;
    map<int,int> mp1;
    //set<int> s1,s2;
    //set<char>::iterator t;
    #define maxm(a,b,c)  max(a,max(c,b))
    #define minm(a,b,c)  min(a,min(c,b))
    #define f(i,n)  for(int i=1;i<n;i++)
    #define rf(i,n) for(int i=n-1;i>=0;i--)
    const int MX = 3005;
    long double dp[MX];
    int n;
    long double hp[MX],x_co[MX],y_co[MX];
    long double dist(int x,int y){
        long double q = (x_co[x] - x_co[y])*(x_co[x] - x_co[y]);
        long double q2 = (y_co[x] - y_co[y])*(y_co[x] - y_co[y]);
        return sqrt(q+q2);
    }
    int main() {
        cin>>n;
        //double hp[n+1],x_co[n+1],y_co[n+1];
        x_co[0]=y_co[0]=hp[0]=0;
        for(int i=1;i<=n;i++){
            cin>>x_co[i]>>y_co[i]>>hp[i];
        }
        dp[1]=hp[1];
        for(int i=2;i<=n;i++){
        	dp[i]= -DBL_MAX;
        	
            for(int j=i-1;j>0;j--){
            	dp[i] = max(dp[i],dp[j]+hp[i]-dist(i,j));
            }
        }
        
        cout<<fixed<<setprecision(6)<<dp[n]<<endl;
        return 0;
    }
=======
/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long int ll;
typedef unsigned long long int ull;
map<int,int> mp1;
//set<int> s1,s2;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
const int MX = 3005;
double dp[MX];
int n;
double hp[MX],x_co[MX],y_co[MX];
double dist(int x,int y){
    double q = (x_co[x] - x_co[y])*(x_co[x] - x_co[y]) + (y_co[x] - y_co[y])*(y_co[x] - y_co[y]);
    return sqrt(q);
}
int main() {
    cin>>n;
    //double hp[n+1],x_co[n+1],y_co[n+1];
    for(int i=1;i<=n;i++){
        cin>>x_co[i]>>y_co[i]>>hp[i];
        dp[i]=0;
    }
    dp[1]=hp[1];
    dp[0]=0;
    int pos = 1;
    for(int i=2;i<=n;i++){
        if(dp[i-1] > dp[i-1]+hp[i]-dist(i,i)){
            dp[i] = dp[i-1];
        }
        else {
            //pos = i;
            dp[i] = dp[i-1] + hp[i] - dist(i,pos);
            pos=i;
        }
    }
    cout.precision(10);
    cout<<dp[n]<<endl;
    return 0;
}
>>>>>>> 4b9c8daf7684a885fd3fad7c44d0bba7a98d44cd
