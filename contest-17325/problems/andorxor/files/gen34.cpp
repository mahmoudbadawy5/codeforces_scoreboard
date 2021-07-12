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


vector<int> genitervals(int n,int m)
{
    vector<int> v;
    for(int i=0;i<m-1;i++)
    {
        int x=rnd.next(1,n-(m-i-1));
        v.push_back(x);
        n-=x;
    }
    v.push_back(n);
    return v;
}

int geno(int mx=0)
{
    if(task!=3&&task!=4)
    {
        int x=rnd.next(0,20);
        if(x==0) return 0;
        return (1<<(x-1));
    }
    if(mx) return (task==3?0:(1<<19));
    return (task==3?0:(1<<rnd.next(0,19)));
}

int main(int argc, char ** argv){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    
    task=atoi(argv[1]);
    int stc=atoi(argv[2]);
    registerGen(2,argv,1);
    
    t=20;
    N=1e5;
    if(task==1) N=300;
    if(task==2) N=3000;
    vector<test> tests;
    test tt;
    tt.o=geno(1); tt.a=tt.o; tt.x=tt.o;
    for(int i=0;i<N;i++)
        tt.v.push_back(tt.o);
    tests.push_back(tt);
    for(int i=0;i<9;i++)
    {
        tt.v.clear();
        int o=geno();
        tt.o=o; tt.a=o; tt.x=rnd.next(0,1)?o:0;

        int n=rnd.next(N-20,N); int m=i+1;
        vector<int> inter=genitervals(n,m);
        int x=rnd.next(0,1);
        for(int i=0;i<inter.size();i++)
        {
            for(int j=0;j<inter[i];j++)
            {
                if(i%2==x) tt.v.push_back(o);
                else tt.v.push_back(rnd.next(0,MXV));
            }
        }
        tests.push_back(tt);
    }
    for(int i=0;i<5;i++)
    {
        tt.v.clear();
        int o=geno();
        tt.o=o; tt.a=o; tt.x=rnd.next(0,1)?o:0;
        int n=rnd.next(N-20,N); int m=rnd.next(n/10,n);
        vector<int> inter=genitervals(n,m);
        int x=rnd.next(0,1);
        for(int i=0;i<inter.size();i++)
        {
            for(int j=0;j<inter[i];j++)
            {
                if(i%2==x) tt.v.push_back(o);
                else tt.v.push_back(rnd.next(0,MXV));
            }
        }
        tests.push_back(tt);
    }
    for(int i=0;i<5;i++)
    {
        tt.v.clear();
        int o=geno();
        tt.o=o; tt.a=o; tt.x=rnd.next(0,1)?o:0;
        int n=rnd.next(N-20,N);
        if(rnd.next(0,1)) {tt.a=rnd.next(0,MXV); tt.x=rnd.next(0,MXV);}
        for(int i=0;i<n;i++)
            tt.v.push_back(rnd.next(0,MXV));
        tests.push_back(tt);
    }
    int per[20];
    iota(per,per+20,0);
    for(int i=1;i<20;i++)
        swap(per[i],per[rnd.next(0,i)]);
    for(int i=0;i<tests.size();i++)
    {
        if(i%5==0)
        {
            startTest(stc+i/5);
            cout << 5 << endl;
        }
        tests[per[i]].print();
    }
    return 0;

}
