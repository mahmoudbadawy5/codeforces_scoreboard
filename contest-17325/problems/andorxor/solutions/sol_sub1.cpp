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
			for(int j=i;j<n;j++)
			{
				int ca=arr[i],co=arr[i],cx=0;
				for(int k=i;k<=j;k++)
				{
					ca&=arr[k]; co|=arr[k]; cx^=arr[k];
				}
				if(ca==a&&co==o&&cx==x) ans++;
			}
		}
		printf("%d\n",ans);
	}
}