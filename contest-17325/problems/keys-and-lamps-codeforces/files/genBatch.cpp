//startTest

#include "testlib.h"
#include "bits/stdc++.h"

using namespace std;

void print(int n,int m,vector<int> v)
{
    n=v.size();
    cout << n << " " << m << endl;
    for(int i=0;i<n;i++)
    {
        cout << v[i];
        if(i==n-1) cout << endl;
        else cout << " ";
    }
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

int main(int argc, char ** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    registerGen(argc,argv,1);
    set<vector<int>> ss;
    int n=5;
    int arr[n];
    iota(arr,arr+n,0);
    do{
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(arr[i]);
            ss.insert(v);
        }
    } while(next_permutation(arr,arr+n));
    vector<pair<vector<int>,int> > tests;
    for(auto i:ss) tests.emplace_back(i,5);
    while(tests.size()%100)
    {
        int n=rnd.next(1,100); int m=rnd.next(n,100);
        tests.emplace_back(genRandVec(n,m),m);
    }
    shuffle(tests.begin(),tests.end());
    for(int i=0;i<tests.size()/100;i++)
    {
        startTest(i+2);
        cout << "100" << endl;
        for(int j=0;j<100;j++)
        {
            print(tests[i*100+j].first.size(),tests[i*100+j].second,tests[i*100+j].first);
        }
    }
    return 0;
}
