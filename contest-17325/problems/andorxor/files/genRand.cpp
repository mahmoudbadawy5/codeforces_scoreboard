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

int main(int argc, char ** argv){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

    N=atoi(argv[1]);
    int stc=atoi(argv[2]);

    registerGen(2,argv,1);
    
    t=20;
    for(int ttc=0;ttc<t;ttc++)
    {
        if(ttc%5==0)
        {
            startTest(stc+ttc/5);
            cout << 5 << endl;
        }
        int x=rnd.next(0,4);
        test tt;
        if(x)
        {
            tt.a=0; tt.o=MXV; tt.x=0;
            for(int i=0;i<N;i++)
            {
                tt.v.push_back(rnd.next(0,MXV));
                tt.x^=tt.v.back();
            }
        }
        else
        {
            tt.a=rnd.next(0,MXV); tt.o=rnd.next(0,MXV); tt.x=rnd.next(0,MXV);
            for(int i=0;i<N;i++)
            {
                tt.v.push_back(rnd.next(0,MXV));
            }
        }
        tt.print();
    }
    return 0;

}
