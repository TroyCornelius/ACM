#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int T;
double x1, ty1, z1, r1;
double x2, ty2, z2, r2;
double ans;
const double pi = 3.141592653589793;
inline double get_dis()
{
       return sqrt((x1-x2)*(x1-x2) + (ty1-ty2)*(ty1-ty2) + (z1-z2)*(z1-z2));
       }
int main()
{
    scanf("%d", &T);
    for (;T>0;T--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &ty1, &z1, &r1, &x2, &ty2, &z2, &r2);
        double h = r1 + r2 - get_dis();
        h /= 2.0;
       // double h1 = sqrt(r1*r1 - (r1-h)*(r1-h));
        //double h2 = sqrt(r2*r2 - (r2-h)*(r2-h));
        double v1 = pi * h * h * (r1 - h/3.0);
        double v2 = pi * h * h * (r2 - h/3.0);
        ans = 4.0/3.0*pi*r1*r1*r1 + 4.0/3.0*pi*r2*r2*r2 - (v1 + v2);
        printf("%.2lf\n", ans);   
    }    
    system("pause");
    return 0;
    }
