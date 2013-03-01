#include <iostream>
#include <cstdio>
using namespace std;

int n, d[550];
int main()
{
    int T, ans;
    cin >>T;
    while (T--)
    {
          cin >>n;
          for (int i=0; i<n; i++) cin >>d[i];
          sort(d, d+n);
          ans = 0;
          int tmp = d[n/2];
          for (int i=0; i<n; i++) ans += abs(d[i] - tmp);
          cout <<ans <<endl;          
    }
    return 0;
    }
