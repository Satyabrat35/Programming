#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,m;
        cin>>n>>m;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(j>=a[i-1]){
                    dp[i][j] = dp[i-1][j]+dp[i-1][j-a[i-1]];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        cout<<dp[n][m];
	}
	return 0;
}