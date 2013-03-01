#include <iostream>
#include <cstdio>
using namespace std;

int T, n;
double p[15][15];


void work()
{
     
     
     
     }
int main()
{
    scanf("%d", &T);
    for (;T>0;T--)
    {
        for (int i=1; i<=n; i++)
          for (int j=1; j<=n; j++)
          {
              scanf("%lf", p[i][j]);
              p[i][j] /= 100;              
          }
        work();
    }
    
    
    
    return 0;
    }
