#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc,char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    registerValidation(argc,argv);
    int N=1e5,task=4;
    if(validator.group() == "subtask1") N = 2,task=1;
    if(validator.group() == "subtask2") N = 100,task=2;
    if(validator.group() == "subtask3") task=3;

    int T = inf.readInt(1,1000,"T");

    inf.readEoln();
    int sumN=0;
    while(T--){
        int n=inf.readInt(1,N,"N"); inf.readEoln();
        sumN+=n;
        for(int i=0;i<n;i++)
        {
            int x=inf.readInt(0,100,"a_i");
            if(i==n-1) inf.readEoln();
            else inf.readSpace();
        }
        for(int i=0;i<n;i++)
        {
            int x=inf.readInt(0,100,"b_i");
            if(i==n-1) inf.readEoln();
            else inf.readSpace();
        }
        for(int i=0;i<n;i++)
        {
            int x=inf.readInt(1,(task==3?1:(int)1e9),"c_i");
            if(i==n-1) inf.readEoln();
            else inf.readSpace();
        }
    }
    ensuref(sumN<=5e5,"Sum of ns exceeded 5e5");
    inf.readEof();

    return 0;
}
