#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
const double eps = 1e-10;
double t1, t2, x1, x2, t0;
int main()
{
     //   freopen("c.in", "r", stdin);
  //  freopen("c2.out", "w", stdout);
    cin >>t1 >>t2 >>x1 >>x2 >>t0;
    if (t1 == t0 && t2 == t0 ) printf("%.0f %.0f\n", x1, x2 );
    else
    if (t1 == t0) printf("%.0f 0\n", x1 );
    else
    if (t2 == t0) printf("0 %.0f\n", x2);
    else
   {
    double tmp = 999999999.0;
    double ans1, ans2, c, nt, a=0, b=0, c1;
    for (ans1 = x1; ans1>=0; ans1-=1.0)
    {
        
        c1 = 1.0 * (t0 - t1) * ans1 / (t2 - t0);
     //   c = floor(c1 + 0.5);
        c = ceil(c1);
        if (c > x2 || c < 0) continue;
        nt = (t1*ans1 + t2*c) / (ans1 + c);   //cout <<ans1 <<" "<<c1<< " "<<nt <<endl;
        if (nt >= t0 && nt - t0 < tmp)
        {
            tmp = nt - t0;
            a = ans1;
            b = c;
        }
        else 
        if (fabs(nt - t0 - tmp) < eps && min(ans1, c) > min(a, b))
        {
           a = ans1;
           b = c;
        }     
      /*  c  = floor(c1);
        if (c > x2 || c < 0) continue;
        nt = (t1*ans1 + t2*c) / (ans1 + c);   cout <<ans1 <<" "<<c<< " "<<nt <<endl;
        if (nt >= t0 && nt - t0 < tmp)
        {
            tmp = nt - t0;
            a = ans1;
            b = c;
        }
        else 
        if (fabs(nt - t0 - tmp) < eps && min(ans1, c) > min(a, b))
        {
           a = ans1;
           b = c;
        }         */
    }
    if (a == b && b==0 && t2 >= t0) b = x2;
    printf("%.0f %.0f\n", a, b);}
   // system("pause");
    return 0;
    }
