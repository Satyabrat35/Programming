

    #include <bits/stdc++.h>
    using namespace std;
    const int N = 1000005;
    int sbit[N];
    int a[N];
    int sum[N];
    int func(int n)
    {
    	int cnt=0;
    	while(n)
    	{
    		n=n&(n-1);
    		cnt++;
    	}
    	return cnt;
    }
    void pre()
    {
    	for(int i=0;i<N;i++)
    	{
    		sbit[i]=func(i);
    	}
    }
    void calSum(int n)
    {
    	sum[0]=a[0];
    	for(int i=1;i<=n;i++)
    	{
    		sum[i]=sum[i-1]+sbit[a[i]];
    	}
    }
    bool check(int n,int x,int k)
    {
    	for(int i=0;i<=n-x;i++)
    	{
    		if((sum[i+x]-sum[i])>=k)
    		{
    			return true;
    		}
    	}
    	return false;
    }
    int main()
    {
    	pre();
    	//FILE *fin = freopen("input.txt","r",stdin);
        //FILE *fout = freopen("output.txt","w",stdout);
        int n,q,k;
        scanf("%d%d",&n,&q);
        a[0]=0;
        for(int i=1;i<=n;i++)
        {
        	scanf("%d",&a[i]);
        }
        calSum(n);
        while(q--)
        {
        	scanf("%d",&k);
        	int lo,mid,hi,ans;
        	lo=1;
        	hi=n;
        	ans=-1;
        	while(hi-lo>=0)
        	{
        		mid=(lo+hi)/2;
        		if(check(n,mid,k))
        		{
        			ans=mid;
        			hi=mid-1;
        		}
        		else
        		{
        			lo=mid+1;
        		}
        	}
        	printf("%d\n",ans);
        }
    	return 0;
    }

