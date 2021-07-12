#include "testlib.h"
#include "bits/stdc++.h"

using namespace std;

int t;

void print(int n,int m,vector<int> v)
{
    t--;
    n=v.size();
    cout << n << " " << m << endl;
    for(int i=0;i<n;i++)
        cout << v[i] << " \n"[i==n-1];
}

vector<int> genRandVec(int n,int m)
{
    m=max(m,n);
    vector<int> ch,v;
    for(int i=0;i<m;i++)
        ch.push_back(i);
    for(int i=0;i<n;i++)
    {
        int x=rnd.next(0,(int)ch.size()-1);
        v.push_back(ch[x]);
        swap(ch[x],ch[ch.size()-1]);
        ch.pop_back();
    }
    return v;
}

void genRand(int n,int m)
{
    print(n,m,genRandVec(n,m));
}

void genSorted(int n,int m,int s)
{
    vector<int> v=genRandVec(n,m);
    sort(v.begin(),v.end());
    if(s) reverse(v.begin(),v.end());
    print(n,m,v);
}

void genEvOd(int n,int m,int mask)
{
    vector<int> v=genRandVec(n,m);
    sort(v.begin(),v.end());
    vector<int> ev,od;
    for(int i:v)
    {
        if(i&1) od.push_back(i);
        else ev.push_back(i);
    }
    if(mask&1) reverse(ev.begin(),ev.end());
    if(mask&2) reverse(od.begin(),od.end());
    if(mask&4) swap(ev,od);
    v.clear();
    for(int i:ev) v.push_back(i);
    for(int i:od) v.push_back(i);
    print(n,m,v);
}

void genOne(int m,int v)
{
    m=max(m,v+1);
    print(1,m,{v});
}

int main(int argc, char ** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    registerGen(argc,argv,1);

    t=100;    
    cout << t << endl;
    int Ns[5]={20,50,80,100,-1};
    for(int i=0;i<5;i++)
    {
        int n=Ns[i];
        if(n==-1) n=rnd.next(1,100);
        for(int j=0;j<2;j++)
            genSorted(n,100,j);
    }
    for(int i=0;i<5;i++)
    {
        int n=Ns[i];
        if(n==-1) n=rnd.next(1,100);
        for(int j=0;j<8;j++)
        {
            genEvOd(n,100,j);
        }
    }
    genOne(1,0);
    genOne(100,0);
    genOne(100,50);
    genOne(100,99);
    genOne(100,rnd.next(0,99));
    while(t>20)
    {
        int n=rnd.next(1,100); int m=rnd.next(n,100);
        genRand(n,m);
    }
    while(t)
    {
        int n=rnd.next(1,10); int m=rnd.next(n,10);
        genRand(n,m);
    }
    return 0;
}
