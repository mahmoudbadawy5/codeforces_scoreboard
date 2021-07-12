#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t,st;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",n);
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			printf("%d ",x);
		}
		puts("");
		for(int i=0;i<n;i++)
			printf("%d %d\n",i+1,i+1);
	}
}