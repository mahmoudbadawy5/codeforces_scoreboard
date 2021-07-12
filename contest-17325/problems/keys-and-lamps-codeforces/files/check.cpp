#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int t,n;

int maxq()
{
    int mx=0;
    for(int i=0;i<t;i++)
    {
        string s=ouf.readToken();
        if(s!="OK:") {s=ouf.readString(); quitf(_wa,"WA");return -1;}
        int cur=ouf.readInt();
        mx=max(mx,cur);
    }
    return mx;
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    t = inf.readInt();
    int q=maxq();
    if(q==-1)
        quitf(_wa,"WA :(");
    if(q<=7)
        quitf(_ok,"OK :)");
    else if(q<=20)
        quitp(100-3*(q-7),"OK :)");
    quitp(61-(q-20)/2.0,"OK :)");
}
