#include "testlib.h"
#include "bits/stdc++.h"

using namespace std;

int N[4]={100000,6,1000,100000};
int n,t;
int mna,mxa;

void print(vector<int> v)
{
	/*for(int i=0;i<v.size();i++)
		swap(v[i],v[rnd.next(0,i)]);*/
	t--;
	cout << v.size() << endl;
	for(int i=0;i<v.size();i++)
		cout << v[i] << " \n"[i==v.size()-1];
}

void genRand(int n)
{
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		int x=rnd.next(mna,mxa);
		v.push_back(x);
	}
	print(v);
}

void genEq(int n,int x)
{
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		v.push_back(x);
	}
	print(v);
}

void genDif(int n)
{
	set<int> ss; vector<int> v;
	for(int i=0;i<n;i++)
	{
		int x=rnd.next(mna,mxa);
		if(ss.find(x)!=ss.end()) x=rnd.next(mna,mxa); 
		v.push_back(x);
		ss.insert(x); 
	}
	print(v);
}

void genSpecial1(int n)
{
	vector<int> v;
	for(int i=0;i<n-1;i++)
		v.push_back(i%mxa);
	v.push_back(mxa);
	print(v);
}

void genSpecial2(int n)
{
	vector<int> v;
	for(int i=0;i<n-1;i++)
		v.push_back((mxa-i)%mxa);
	v.push_back(mna);
	print(v);
}

void genSpecial3(int n)
{
	vector<int> v;
	int z=(mxa-mna)/n;
	for(int i=0;i<n;i++)
		v.push_back((mna+i*z)%mxa);
	print(v);
}

void genSpecial4(int n)
{
	vector<int> v;
	for(int i=0;i<n;i++)
		v.push_back(i?mna:mxa);
	print(v);
}

int main(int argc, char ** argv){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    registerGen(argc,argv,1);

    int task = atoi(argv[1]);
    

    t=20;
    cout << t  << endl;
    
    n=N[task-1];
    if(task==1)
    	mna=-100,mxa=100;
    else if(task==2)
    	mna=0,mxa=8;
    else
    	mna=-1e6,mxa=1e6;
    if(task!=1) genDif(n); genDif(n-1); // 2
    genEq(n,0); genEq(n,mna); genEq(n,mxa); genEq(n,rnd.next(mna,mxa)); // 4
    genSpecial1(n); genSpecial2(n); genSpecial3(n); // 3
    genSpecial1(n-1); genSpecial2(n-1); genSpecial3(n-1); // 3
    if(task!=1) genDif(3); // 1
    genSpecial4(n); // 1
    while(t)
   		genRand(rnd.next((task==1?500:3),n));
    return 0;
}
