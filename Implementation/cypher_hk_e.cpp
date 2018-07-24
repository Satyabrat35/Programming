#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map<char,int> mp1,mp2;
set<string> s1,s2;
typedef long long int ll;

int main()
{string s;
cin>>s;
int k;
cin>>k;
int l = s.length();
for(int i=0;i<l;i++){
    int x = s[i];
    if(x>=65 && x<=90){
        char c = 65 + (x+k-65)%26;
        cout<<c;
    }
    else if(x>=97 && x<=122){
        char c = 97 + (x+k-97)%26;
        cout<<c;
    }
    else if(x>=48 && x<=57) {
        int y = k+s[i]-48;
        cout<<y%10;
    }
    else {
        cout<<s[i];
    }
}

return 0;
}
