#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int arr[N],pxor[N];
int andt[N][20],ort[N][20];
int lg2[N];
vector<int> pos[(1<<20)+5];
int vis[(1<<20)+5];
int n,a,o,x;
int tc;

int getand(int l,int r)
{
	int sz=lg2[(r-l+1)];
	return andt[l][sz]&andt[r-(1<<sz)+1][sz];
}

int getor(int l,int r)
{
	int sz=lg2[(r-l+1)];
	return ort[l][sz]|ort[r-(1<<sz)+1][sz];
}

int get(int l,int r,int v)
{
	if(vis[v]!=tc)
		return 0;
	if(l>r) return 0;
	int a=lower_bound(pos[v].begin(),pos[v].end(),l)-pos[v].begin();
	int b=upper_bound(pos[v].begin(),pos[v].end(),r)-pos[v].begin();
	return max(b-a,0);
}

int main()
{
	int t;
	scanf("%d",&t);
	lg2[1]=0;
	for(int i=2;i<N;i++)
	{
		lg2[i]=lg2[i-1];
		if(1<<(lg2[i]+1)==i)
			lg2[i]++;
	}
	while(t--)
	{
		tc++;
		scanf("%d %d %d %d",&n,&a,&o,&x);
		int cx=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			pxor[i]=arr[i];
			if(i) pxor[i]^=pxor[i-1];
			if(vis[pxor[i]]!=tc) pos[pxor[i]].clear();
			vis[pxor[i]]=tc;
			pos[pxor[i]].push_back(i);
		}
		for(int i=0;i<n;i++)
		{
			andt[i][0]=ort[i][0]=arr[i];
			for(int j=1;j<20;j++)
				andt[i][j]=ort[i][j]=0;
		}
		for(int i=1;i<20;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(j+(1<<i)>n) break;
				andt[j][i]=(andt[j][i-1]&andt[j+(1<<(i-1))][i-1]);
				ort[j][i]=(ort[j][i-1]|ort[j+(1<<(i-1))][i-1]);
			}
		}
		long long tot=0;
		for(int i=0;i<n;i++)
		{
			if((arr[i]|o)!=o) continue;
			if((arr[i]&a)!=a) continue;
			int la=i,ra=i,lo=i,ro=i;
			int st=i,en=n-1,ans=n;
			while(st<=en)
			{
				int mid=(st+en)/2;
				if(getand(i,mid)<=a)
				{
					ans=mid; en=mid-1;
				}
				else
					st=mid+1;
			}
			la=ans;
			if(getand(i,ans)!=a) continue;
			st=la,en=n-1,ans=-1;
			while(st<=en)
			{
				int mid=(st+en)/2;
				if(getand(i,mid)==a)
				{
					ans=mid; st=mid+1;
				}
				else
					en=mid-1;
			}
			ra=ans;
			st=i,en=n-1,ans=n;
			while(st<=en)
			{
				int mid=(st+en)/2;
				if(getor(i,mid)>=o)
				{
					ans=mid; en=mid-1;
				}
				else
					st=mid+1;
			}
			if(getor(i,ans)!=o) continue;
			lo=ans;
			st=lo,en=n-1,ans=-1;
			while(st<=en)
			{
				int mid=(st+en)/2;
				if(getor(i,mid)==o)
				{
					ans=mid; st=mid+1;
				}
				else
					en=mid-1;
			}
			ro=ans;
			int l=max(la,lo),r=min(ra,ro);
			tot+=get(l,r,(i?pxor[i-1]^x:x));
		}
		printf("%lld\n",tot);
	}
}