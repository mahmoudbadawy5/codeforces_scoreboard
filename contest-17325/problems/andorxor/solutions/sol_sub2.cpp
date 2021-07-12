#include <bits/stdc++.h>

using namespace std;

int n,a,o,x;
int arr[100005];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d",&n,&a,&o,&x);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			int ca=arr[i],co=arr[i],cx=0;
			for(int j=i;j<n;j++)
			{
				ca&=arr[j]; co|=arr[j]; cx^=arr[j];
				if(ca==a&&co==o&&cx==x) ans++;
			}
		}
		printf("%d\n",ans);
	}
}