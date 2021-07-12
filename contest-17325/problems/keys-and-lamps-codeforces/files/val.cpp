#include "testlib.h"

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);

  int T = inf.readInt(1, 500, "T");
  inf.readEoln();
  
  while (T--) {
    int n=inf.readInt(1,100,"n"); inf.readSpace(); int m=inf.readInt(n,100,"m"); inf.readEoln();
    set<int> ss;
    for(int i=0;i<n;i++)
    {
      int x=inf.readInt(0,m-1,"a_i");
      ensuref(ss.find(x)==ss.end(),"Repeated switches");
      ss.insert(x);
      if(i==n-1) inf.readEoln();
      else inf.readSpace();
    }
  }
  inf.readEof();

  return 0;
}
