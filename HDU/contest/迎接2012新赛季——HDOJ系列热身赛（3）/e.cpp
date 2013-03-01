/*
 * Author:  Troy
 * Created Time:  2012/4/2 14:44:00
 * File Name: e.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

double p, f[10][10], ans1, ans2;
inline double calc(double pi)
{
    return pi * pi / (1 - 2.0 * pi * (1-pi));
}
double dp(int n, double pi, double cp)
{
    REP(i, 10)
        REP(j, 10)
        {
            if (i >= n && i >= j+2) f[i][j] = 1.0;
            else
            if (j >= n && j >= i+2) f[i][j] = 0.0;
            else f[i][j] = -1;
        }
    f[n][n] = cp;
    f[n-1][n] = pi * f[n][n];
    f[n][n-1] = (1- pi) * f[n][n] + pi;
    FORD(i, n-1, 0)
        FORD(j, n-1, 0)
            f[i][j] = pi * f[i+1][j] + (1 - pi) * f[i][j+1];
    return f[0][0];   
} 
double get_game(double pi)
{
    double ret = dp(4, pi, calc(pi));
    return ret;
}
double get_set(double pi)
{
    double tmp = dp(7, pi, calc(pi));
    double ret = dp(6, ans1, tmp);
    return ret;
}
double get_match(double pi)
{
    return pi * pi + pi * (1 - pi) * pi * 2.0;
}
int main() 
{
    while (~sf("%lf", &p))
    {
        if (p < 0) break;
        ans1 = get_game(p);
        ans2 = get_set(p);
        pf("%.11f %.11f %.11f\n", ans1, ans2, get_match(ans2));
    }
    return 0;
}

