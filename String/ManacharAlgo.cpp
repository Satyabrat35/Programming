/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
 typedef long long  int ll;
 typedef unsigned long long int ull;
//map<int,int> mp1;
//set<int> s1;
//set<string> ss;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
void longest_palindrome(string a, int n){
    map<int,int> m;

    int start = 0;
    int end = n;

    int s=start;
    int e=end-1;

    while(start<n){

        bool pl = true;


        if(s<e && a[s]==a[e]){
            s++;
            e--;
        }
        else if(s<e && a[s]!=a[e]){
            // plaindrome not found
            pl=false;
            end--;
            s=start;
            e=end;
            continue;
        }

        if(s>=e && pl){
            // it means we found a palindrome
            m.insert(make_pair(start,end));
            // research for another from start+1
            start++;
            end=n;

            s=start;
            e=end;
        }
    }

    int maxlength = INT_MIN;

    for(auto palindromes : m){

        int curl  = palindromes.second - palindromes.first;
        if(curl>maxlength){
            maxlength = curl;
            start = palindromes.first;
            end =  palindromes.second;
        }
    }

    for(int i=start; i<=end; i++){
        cout<<a[i];
    }

    cout<<endl;


}

int main() {
    int t;
    cin>>t;

    while(t--){
        string a;
        cin>>a;
        int n = a.length();
        longest_palindrome(a,n);
    }
    return 0;
}