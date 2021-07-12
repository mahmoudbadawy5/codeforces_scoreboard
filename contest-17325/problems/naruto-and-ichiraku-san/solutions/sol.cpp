#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;

long long arr[N];
int n;
long long ans[N];

int main()
{
	int t,st;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&ans[i]);
		}
		// 0 + 1 = ans[0]
		// 1 + 2 = ans[1]
		// 0 + 1 + 2 = ans[2]
		arr[2]=ans[2]-ans[0];
		arr[0]=ans[2]-ans[1];
		arr[1]=ans[0]-arr[0];
		for(int i=3;i<n;i++)
		{
			// ans[i]=arr[i]+arr[i-1]
			arr[i]=ans[i]-arr[i-1];
		}
		printf("%d\n",n);
		for(int i=0;i<n;i++)
			printf("%lld%c",arr[i]," \n"[i==n-1]);
		printf("1 2\n2 3\n1 3\n");
		for(int i=3;i<n;i++)
			printf("%d %d\n",i,i+1);
	}
}