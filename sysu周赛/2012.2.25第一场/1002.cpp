/*
 * Author:  Troy
 * Created Time:  2012/2/25 19:34:35
 * File Name: 1002.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
#include <functional>
#include <iomanip>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
const double delta = 2.5*2.5;
pair<double, double> p[256];
int n, ans;
inline bool sgn(double x)
{
    return x < eps;
}
bool calc(double x, double y, pair<double,double> c)
{
   // printf("%.2f %.2f %.3f\n",x, y, (c.fi-x)*(c.fi-x) + (c.se-y)*(c.se-y));
    //x = 1.0; y = 22.5;
    //if (x == 1.0 && y == 22.5) printf("%.1f\n",(c.fi-x)*(c.fi-x) + (c.se-y)*(c.se-y));
    return sgn((c.fi-x)*(c.fi-x) + (c.se-y)*(c.se-y) - delta);
}

int main() 
{
  // freopen("1.out", "w", stdout);
     n = 0;
     double x, y;
     while (~scanf("%lf%lf", &x, &y) ) p[n++] = mp(x, y);
     ans = 0;
     int cnt;
     for (double i = 0.0; i<=50.0; i += 0.1)
         for (double j = 0.0; j<=50.0; j += 0.1)
         {
             cnt = 0;
             REP(k, n)
             {
                 if (calc(i, j, p[k])) cnt++;
             }
             if (cnt > ans) ans = cnt;
             if (ans == n) {cout <<ans <<endl; return 0;}
          //   cout <<i <<" " <<j  <<" "<<cnt <<endl;
         }
    printf("%d\n", ans);
    return 0;
}

