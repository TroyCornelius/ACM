#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

double x1, yy, x2, y2;

int main()
{
    while (scanf("%lf%lf%lf%lf", &x1,&yy,&x2,&y2))
    {
       if (x1==0.0 && yy==0.0 && x2==0.0 && y2==0.0) break;
       printf("%.3lf\n", fabs(x1-x2) * fabs(yy-y2));          
    }
    
    return 0;
    }
