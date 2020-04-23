/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;

#define maxm(a,b,c)  max(a,max(c,b))

#define minm(a,b,c)  min(a,min(c,b))

#define f(i,n)  for(int i=1;i<n;i++)

#define rf(i,n) for(int i=n-1;i>=0;i--)

 

int main()

{

    int t;

    cin>>t;

    while(t--){

        int n,k;

        cin>>n>>k;
        vector<int> a(n);

        for(int i=0;i<n;i++)cin>>a[i];

        vector<int> vec(2 * k + 1);
		for (int i = 0; i < n / 2; ++i) {
			++vec[a[i] + a[n - i - 1]];
		}
		vector<int> pref(2 * k + 2);
		for (int i = 0; i < n / 2; ++i) {
			int l1 = 1 + a[i], r1 = k + a[i];
			int l2 = 1 + a[n - i - 1], r2 = k + a[n - i - 1];
			++pref[min(l1, l2)];
			--pref[max(r1, r2) + 1];
		}
		for (int i = 1; i <= 2 * k + 1; ++i) {
			pref[i] += pref[i - 1];
		}
		int ans = 1e9;
		for (int sum = 2; sum <= 2 * k; ++sum) {
			ans = min(ans, (pref[sum] - vec[sum]) + (n / 2 - pref[sum]) * 2);
		}
		cout << ans << endl;
    }
    return 0;

}