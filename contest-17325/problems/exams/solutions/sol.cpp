#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int a[N],b[N],c[N];
int n;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(int i=0;i<n;i++) scanf("%d",&b[i]);
		for(int i=0;i<n;i++) scanf("%d",&c[i]);
		long long bans=0,ans=(1LL<<60);
		for(int i=0;i<n;i++)
		{
			bans+=1LL*max(50-a[i],0)*c[i];
			a[i]=max(a[i],50);
		}
		for(int i=0;i<n;i++)
		{
			if(b[i]<100)
				ans=min(ans,1LL*max((b[i]-a[i]+1),0)*c[i]);
		}
		if(ans==(1LL<<60))
			puts("-1");
		else
			printf("%lld\n",bans+ans);
	}
}