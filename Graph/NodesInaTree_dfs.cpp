    #include<bits/stdc++.h>
    #define ll int
    #define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #define mp make_pair
    #define pb push_back
    #define nl "\n"
    #define lim 100005
    #define m 1000000007
    using namespace std;
    vector<ll> adj[100005];
    ll co[100005][26];
    string s;
    void dfs(ll u,ll parent)
    {
    	ll i;
    	for(ll i=0;i<26;i++)
    		co[u][i]=0;
    	co[u][s[u-1]-'a']++;
    	for(auto v:adj[u])
    	{
    		if(v==parent)
    			continue;
    		dfs(v,u);
    		for(i=0;i<26;i++)
    			co[u][i]+=co[v][i];
    	}
    }
    int main()
    {
    	boost
    	ll n,q,i,u,v;
    	cin >> n >> q;
    	cin >> s;
    	for(i=0;i<n-1;i++)
    	{
    		cin >> u >> v;
    		adj[u].pb(v);
    		adj[v].pb(u);
    	}
    	dfs(1,0);
    	while(q--)
    	{
    		char c;
    		cin >> u >> c;
    		cout << co[u][c-'a'] << "\n";
    	}
    }