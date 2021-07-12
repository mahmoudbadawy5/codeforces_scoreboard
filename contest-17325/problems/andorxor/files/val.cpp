#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc,char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    registerValidation(argc,argv);
    int N=1e5,task=5,MX=(1<<20)-1;
    if(validator.group() == "subtask1") N = 300,task=1;
    if(validator.group() == "subtask2") N = 3000,task=2;
    if(validator.group() == "subtask3") task=3;
    if(validator.group() == "subtask4") task=4;

    int T = inf.readInt(1,5,"T");
    inf.readEoln();

    while(T--){
        int n=inf.readInt(1,N,"N"); inf.readSpace();
        int a=inf.readInt(0,MX,"A"); inf.readSpace();
        int o=inf.readInt(0,MX,"O"); inf.readSpace();
        int x=inf.readInt(0,MX,"X"); inf.readEoln();
        if(task==3) ensuref(o==0,"Subtask 3 [o!=0]");
        if(task==4) ensuref(((o&(o-1))==0) && o!=0,"Subtask 4 [o!=2^m]");
        for(int i=0;i<n;i++)
        {
            int x=inf.readInt(0,MX,"arr_i");
            if(i==n-1) inf.readEoln();
            else inf.readSpace();
        }
    }
    inf.readEof();
    return 0;
}
