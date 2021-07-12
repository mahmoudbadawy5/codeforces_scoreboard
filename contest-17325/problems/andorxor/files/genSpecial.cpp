#include "testlib.h"
#include "bits/stdc++.h"

using namespace std;

const int MXV=(1<<20)-1;

int t,task,N;

struct test{
    int a,o,x;
    vector<int> v;
    void print()
    {
        cout << v.size() << " " << a << " " << o << " " << x << endl;
        for(int i=0;i<v.size();i++)
            cout << v[i] << " \n"[i==v.size()-1];
        fflush(stdout);
    }
};

vector<test> tests;

test genAll(int n)
{
    test ret;
    ret.a=0; ret.o=0; ret.x=0;
    for(int i=0;i<n;i++)
        ret.v.push_back(0);
    return ret;
}

test genSorted(int n,int st)
{
    test ret;
    ret.a=MXV; ret.o=0; ret.x=0;
    for(int i=st;i<n+st;i++)
    {
        ret.v.push_back(i);
        ret.a&=i; ret.o|=i; ret.x^=i;
    }
    return ret;
}

test genSortedShuffled(int n,int st)
{
    test ret=genSorted(n,st);
    shuffle(ret.v.begin(),ret.v.end());
    return ret;
}

test genEvil(int ac,int oc,int n)
{
    test ret;
    vector<int> cands;
    for(int i=0;i<=MXV;i++)
    {
        if(__builtin_popcount(i)==oc) cands.push_back(i);
    }
    ret.o=cands[rnd.next(0,(int)cands.size()-1)];
    cands.clear();
    for(int i=0;i<=MXV;i++)
    {
        if(__builtin_popcount(i)==ac&&((ret.o|i)==ret.o)) cands.push_back(i);
    }
    ret.a=cands[rnd.next(0,(int)cands.size()-1)];
    cands.clear();
    for(int i=0;i<=MXV;i++)
    {
        if((ret.o|i)==ret.o && (ret.a&i)==ret.a) cands.push_back(i);
    }
    shuffle(cands.begin(),cands.end());
    for(int i=0;i<cands.size()&&ret.v.size()<n;i++)
    {
        ret.v.push_back(cands[i]);
        ret.x^=ret.v.back();
    }
    return ret;
}

test genSmall(int n,int v)
{
    map<pair<int,pair<int,int> > ,int> co;
    test ret;
    for(int i=0;i<n;i++)
    {
        ret.v.push_back(rnd.next(0,v));
    }
    int mx=0;
    pair<int,pair<int,int> > mxi;
    for(int i=0;i<n;i++)
    {
        int a=ret.v[i]; int o=a,x=a;
        for(int j=i;j<n;j++)
        {
            a&=ret.v[j]; o|=ret.v[j]; x^=ret.v[j];
            co[{a,{o,x}}]++;
            mx=max(mx,co[{a,{o,x}}]);
            if(mx==co[{a,{o,x}}])
                mxi={a,{o,x}};
        }
    }
    ret.a=mxi.first; ret.o=mxi.second.first; ret.x=mxi.second.second;
    return ret;
}

test extendTest(test t,int n)
{
    int on=t.v.size();
    for(int i=on;i<n;i++)
        t.v.push_back(t.v[i-on]);
    return t;
}

int main(int argc, char ** argv){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    N=atoi(argv[1]);
    int stc=atoi(argv[2]);
    registerGen(2,argv,1);
    
    t=20;
    tests.push_back(genAll(N)); t--;
    tests.push_back(genSorted(N,0)); t--;
    tests.push_back(genSorted(N,MXV-N+1)); t--;
    tests.push_back(genSortedShuffled(N,0)); t--;
    tests.push_back(genSortedShuffled(N,MXV-N+1)); t--;
    tests.push_back(genEvil(0,20,N)); t--;
    tests.push_back(genEvil(2,19,N)); t--;
    tests.push_back(genEvil(3,18,N)); t--;
    tests.push_back(genEvil(3,17,N)); t--;
    tests.push_back(genEvil(5,15,N)); t--;
    tests.push_back(genEvil(10,13,N)); t--;
    tests.push_back(extendTest(genSmall(5,3),N)); t--;
    tests.push_back(extendTest(genSmall(10,3),N)); t--;
    tests.push_back(extendTest(genSmall(5,2),N)); t--;
    tests.push_back(extendTest(genSmall(10,2),N)); t--;
    tests.push_back(extendTest(genSmall(5,10),N)); t--;
    tests.push_back(extendTest(genSmall(10,10),N)); t--;
    tests.push_back(extendTest(genSmall(5,7),N)); t--;
    tests.push_back(extendTest(genSmall(100,2),N)); t--;
    tests.push_back(extendTest(genSmall(100,1),N)); t--;
    assert(t==0);
    //shuffle(tests.begin(),tests.end());
    for(int i=0;i<tests.size();i++)
    {
        if(i%5==0)
        {
            startTest(stc+i/5);
            cout << 5 << endl;
        }
        tests[i].print();
    }
    return 0;

}
