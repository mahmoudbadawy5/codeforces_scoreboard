#include "testlib.h"
#include "bits/stdc++.h"

using namespace std;

vector<int> ns;

void genNs(int mnN,int mxN,int sumN,int t)
{
    sumN=max(sumN,mxN+mnN*(t-1));
    sumN=min(1LL*sumN,1LL*mxN*t);
    int x=rnd.next(1,(sumN-t*mnN)/mxN);
    t-=x; sumN-=x*mxN;
    while(x--)
        ns.push_back(mxN);
    for(int i=t;i>=1;i--)
    {
        // next sumN -> [mnN*(i-1),mxN*(i-1)]
        int n=rnd.next(max(mnN,sumN-mxN*(i-1)),min(sumN-mnN*(i-1),mxN));
        ns.push_back(n);
        sumN-=n;
    }
    for(int i=1;i<ns.size();i++)
        swap(ns[i],ns[rnd.next(0,i)]);
}

int mxN[4]={2,100,100000,100000};
int task,sumn,t;

void print(vector<int> a,vector<int> b,vector<int> c)
{
	t--; sumn-=a.size();
    cout << a.size() << endl;
    if(task==3)
    	for(int i=0;i<c.size();i++) c[i]=1;
    for(int i=0;i<a.size();i++) cout << a[i] << " \n"[i==a.size()-1];
    for(int i=0;i<b.size();i++) cout << b[i] << " \n"[i==b.size()-1];
    for(int i=0;i<c.size();i++) cout << c[i] << " \n"[i==c.size()-1];

}

vector<int> genRandVec(int n,int mn,int mx)
{
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		v.push_back(rnd.next(mn,mx));
	}
	return v;
}

const int MXC=1e9;

int main(int argc, char ** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    registerGen(argc,argv,1);
    task=atoi(argv[1]);
    t=100;
    sumn=5e5;
    cout << t << endl;
    // N=1 special cases
    print({1},{100},{100});
    print({100},{100},{100});
    print({99},{100},{100});
    print({1},{99},{100});
    print({100},{99},{100});
    print({99},{99},{100});
    print({49},{50},{100});
    print({50},{50},{100});
    print({51},{50},{100});
    print({0},{99},{1000000000});
    // Samples
    if(task!=1) print({40,50,0},{80,100,55},{1,2,3});
    print({0},{50},{10});
    print({100},{100},{10});
    // Special cases
    int curn=min(mxN[task-1],10000);
	print(genRandVec(curn,0,49),genRandVec(curn,50,100),genRandVec(curn,1,MXC));
	print(genRandVec(curn,0,49),genRandVec(curn,0,49),genRandVec(curn,1,MXC));
	print(genRandVec(curn,50,100),genRandVec(curn,0,49),genRandVec(curn,1,MXC));
	print(genRandVec(curn,50,100),genRandVec(curn,50,100),genRandVec(curn,1,MXC));
	print(genRandVec(curn,100,100),genRandVec(curn,0,99),genRandVec(curn,1,MXC));
	print(genRandVec(curn,0,100),genRandVec(curn,100,100),genRandVec(curn,1,MXC));
	vector<int> v=genRandVec(curn,100,100);
	v[rnd.next(0,curn-1)]=99;
	print(genRandVec(curn,0,99),v,genRandVec(curn,1,MXC));
	print(genRandVec(curn,0,49),genRandVec(curn,50,50),genRandVec(curn,1,MXC));
	genNs(1,mxN[task-1],sumn,t);
	for(int i=0;i<ns.size();i++)
	{
		print(genRandVec(ns[i],0,100),genRandVec(ns[i],0,100),genRandVec(ns[i],0,MXC));
	}
    return 0;
}
