#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int n;
int cans[100005];
long long sum[100005];

int readAns(InStream& stream)
{
    int nn=stream.readInt(-1,n);
    if(nn==-1) return nn;
    if(nn!=n) stream.quitf(_wa,"expected n or -1 found %d",nn);
    for(int i=0;i<n;i++)
    {
        sum[i+1]=stream.readLong((long long)-1e12,(long long)1e12);
        sum[i+1]+=sum[i];
    }
    for(int i=0;i<n;i++)
    {
        int l=stream.readInt(1,n,"l");
        int r=stream.readInt(l,n,"r");
        if(l==r)
            stream.quitf(_wa,"L can\'t be equal to R");
        if(sum[r]-sum[l-1]!=cans[i])
            stream.quitf(_wa,"The %dth query had different answer than expected",i+1);
    }
    return 1;
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    int t = inf.readInt();
    while(t--)
    {
        n=inf.readInt();
        for(int i=0;i<n;i++)
            cans[i]=inf.readInt();
        int x=readAns(ouf); int y=readAns(ans);
        if(x!=y)
        {
            if(x>y)
                ans.quitf(_fail,"fail :'(");
            else
                ouf.quitf(_wa,"Couldn't find an answer");
        }
    }
    ouf.quitf(_ok,"OK :)");
}
