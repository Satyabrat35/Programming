#include<bits/stdc++.h>
using namespace std;
int main()
 {
     int t;
     cin>>t;
     while(--t>=0){
         int n;
         cin>>n;
         string s;
         unordered_map<string,int> m;
         for(int i=0;i<n;i++){
             cin>>s;
             m[s]++;
         }
         cin>>s;
         //cout<<s<<endl;
         n=s.length();
         //cout<<n<<endl;
         vector<bool> dp(n+1,false);
         dp[0]=true;
         string t1,t="";
         for(int i=1;i<=n;i++){
             t+=s[i-1];
             t1="";
             for(int j=i-1;j>=0;j--){
                t1=s[j]+t1;
                //cout<<m[t1]<<' ';
                if(m.find(t1)!=m.end() && dp[j]){
                    dp[i]=true;
                   // break;
                } 
             }
         }
         
         if(dp[n]){
             cout<<"1"<<endl;
         }
         else{
             cout<<"0"<<endl;
         }
     }
	
	return 0;
}