#include <iostream>
#include <cstdio>
using namespace std;

long long s[55], f[55], ans ,d;
int n;
void init()
{
     memset(s, 0, sizeof(s));
     memset(f, 0, sizeof(f));
     f[1] = s[1] = 1;
     for (int i=2; i<=50; i++) f[i] = f[i-1] * 2;   
     }
int main()
{
    init();
    while (cin >>n)
    {
          if (n == 0) break;
          ans = 0;
          for (int i=1; i<=n; i++) 
          {
              cin >>d;
              ans += f[i] * d;
          }
          cout <<ans <<endl; 
    }
    system("pause");
    return 0;
    }
