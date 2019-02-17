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
const int MAX = 1e6+1;
//vector<bool> prime={true};
vector<int> vec;
void SieveOfEratosthenes() 
{  bool prime[MAX]; 
   memset(prime, true, sizeof(prime));
   
  
    for (int p=2; p*p<=MAX; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=MAX; i += p) 
                {prime[i] = false;} 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=MAX; p++) 
       if (prime[p]) 
        {
            vec.push_back(p);
        }
} 
int cou(int n){
    int i=0;
    for(i=0;;i++){
        if(vec[i]>=n){
            break;
        }
    }
    int table[n+1];
    memset(table,0,sizeof(table));
    table[0]=1;
    for(int k=0;k<i;k++){
        for(int j=vec[k];j<=n;j++){
            table[j]+=table[j-vec[k]];
        }
    }
    return table[n];
}
int main() {
    SieveOfEratosthenes();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<cou(n)<<endl;
    }
    /*for(int i=0;i<100;i++){
        cout<<vec[i]<<' ';
    }*/
    return 0;
}