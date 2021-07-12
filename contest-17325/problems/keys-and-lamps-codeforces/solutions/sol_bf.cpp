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
	int un=n;
	for(int i=0;i<m&&un;i++)
	{
		auto x=lightLamps({i});
		if(x.size())
		{
			pos[x[0]]=i;
			un--;
		}
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
