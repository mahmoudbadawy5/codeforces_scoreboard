#include "testlib.h"
#include <iostream>

using namespace std;

const int N=105;

int arr[N];
int got[N];

int main(int argc, char* argv[])
{
    setName("Interactor Lamps");
    registerInteraction(argc, argv);
    
    // reads number of queries from test input file
    int t = inf.readInt();
    cout << t << endl;

    for (int tc = 0; tc < t; tc++)
    {
        int n=inf.readInt(); int m=inf.readInt();
        cout << n << " " << m << endl;
        for(int i=0;i<n;i++)
            arr[i]=inf.readInt();
        int curq=0;
        while(true)
        {
            for(int i=0;i<m;i++)
                got[i]=0;
            int x=ouf.readInt(-1,m);
            if(x==-1)
            {
                for(int i=0;i<n;i++)
                    got[i]=ouf.readInt(0,m-1);
                int ok=1;
                for(int i=0;i<n;i++)
                    ok&=arr[i]==got[i];
                if(!ok)
                {
                    cout << -1 << endl;
                    quitf(_wa,"WA: guessed switches incorrectly");
                }
                cout << 0 << endl;
                break;
            }
            curq++;
            if(curq>100)
            {
                cout << -1 << endl;
                quitf(_wa,"Used too many queries");
            }
            for(int i=0;i<x;i++)
            {
                int cur=ouf.readInt(0,m-1);
                if(got[cur])
                {
                    cout << -1 << endl;
                    quitf(_wa,"WA: repeated switches");
                }
                got[cur]=1;
            }
            vector<int> ans;
            for(int i=0;i<n;i++)
            {
                if(got[arr[i]])
                    ans.push_back(i);
            }
            cout << ans.size() << endl;
            for(int i=0;i<ans.size();i++)
            {
                cout << ans[i];
                if(i==ans.size()-1) cout << endl;
                else cout << " ";
            }
            if(!ans.size()) cout << endl;
        }
        tout << "OK: " << curq << endl;
    }

    // just message
    quitf(_ok, "%d queries processed", t);
}
