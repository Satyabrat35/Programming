#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool pal(string z){
    int l = 0;
    int h = z.size()-1;
    while(l<h){
        if(z[l++]!=z[h--]){
            return false;
        }
    }
    return true;
}
int sub(string s, int n){
    int l = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<=n-i;j++){
            string k = s.substr(i,j);
            if(pal(k)==true){
                int q = k.size();
                l = max(l , q);
            }
        }
    }
    return l;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    cout<<sub(s,s.size())<<endl;
	}
	return 0;
}