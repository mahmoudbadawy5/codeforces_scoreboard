#include <bits/stdc++.h>

using namespace std;

void WA()
{
	exit(0);
}

vector<int> lightLamps(vector<int> switches){
	cout << switches.size() << endl;
	for(int i:switches)
		cout << " " << i;
	cout << endl;
	int x;
	cin >> x;
	if(x==-1) WA();
	vector<int> v;
	for(int i=0;i<x;i++)
	{
		int z;
		cin >> z;
		v.push_back(z);
	}
	return v;
}

vector<int> guessSwitches(int n,int m)
{
	vector<int> pos(n,0);
	for(int i=0;i<7;i++)
	{
		vector<int> q;
		for(int j=0;j<m;j++)
		{
			if(j&(1<<i))
				q.push_back(j);
		}
		if(!q.size()) break;
		vector<int> l=lightLamps(q);
		for(int x:l)
			pos[x]|=(1<<i);
	}
	return pos;
}

int main()
{
	int t;
	assert(scanf("%d",&t)==1);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		vector<int> ans=guessSwitches(n,m);
		cout << -1 << endl;
		for(int i:ans)
			cout << " " << i;
		cout << endl;
		int x;
		cin >> x;
		if(x==-1) WA();
	}
}
