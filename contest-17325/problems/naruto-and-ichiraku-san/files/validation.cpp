#include "testlib.h"

int N[4]={100000,6,1000,100000};

int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    int testCount = inf.readInt(1, 20, "testCount");  inf.readEoln();
    int st=4;
    if(validator.group() == "subtask1") st=1;
    if(validator.group() == "subtask2") st=2;
    if(validator.group() == "subtask3") st=3;
    for (int i = 0; i < testCount; i++)
    {
        int n = inf.readInt(1, N[st-1], "n");
        if(st==1) ensuref(n>=500,"N<500 in subtask 1");
        inf.readEoln();

        for (int i = 0; i < n; ++i)
        {
            int l=(-1e9),r=1e9;
            if(st==1)
            {
                l=-100; r=100;
            }
            else if(st==2)
            {
                l=0; r=8;
            }
            inf.readInt(l, r, "ans_i");
            if (i < n - 1)
                inf.readSpace();
        }
        inf.readEoln();
    }

    inf.readEof();
}