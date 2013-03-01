#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int a, b, r;
int main()
{
    int tot=0;
    while (scanf("%d", &r))
    {
          
          if (r == 0) break;
          tot++;
          scanf("%d%d", &a, &b);
          if (a*a + b*b <= 4 * r *r) printf("Pizza %d fits on the table.\n", tot);
          else printf("Pizza %d does not fit on the table.\n", tot);     
    }
    system("pause");
    
    return 0;
    }
