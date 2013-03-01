#include <cstdio>
#include <iostream>
using namespace std;

int m;
int main()
{
    cin >>m;
    m *= 100;
    int t1=m, t2=1, ans;
    for (ans = 1; ans <= 38; ans++)
      {
          if (t2 > t1) break;
          t2 += 1 << (ans-1);
          t1 += m;      
      }
    cout <<ans-1 <<endl;
    return 0;
    }
