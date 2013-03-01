#include <cstdio>
#include <iostream>
#include <cmath>
#include <functional>
#include <algorithm>
using namespace std;

double p;
int n;
int gcd(int a, int b)
{
    if (a%b==0) return b;
    else return gcd(b, a%b);
    }
int main()
{
    double anst, t;
    int ansa, ansb, c;

    while (scanf("%lf%d",&p, &n))
    {
        if (n == 0) break;
        p = sqrt(p);
        anst = 99999999.9;
        for (int i=0; i<=n; i++)
          for (int j=1; j<=n; j++)
          {
             t = double(i)/double(j);
             if (t < p || t > anst) continue;
             if (t >= p && t < anst)
             {
                anst = t;
                ansa = i; ansb = j;                   
             }
          }
        c = gcd(max(ansa, ansb), min(ansa, ansb));
        printf("%d/%d\n", ansa/c, ansb/c);  
    }
    
    return 0;
    }
