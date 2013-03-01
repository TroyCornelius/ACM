/*
 * Author:  Troy
 * Created Time:  2012/2/25 20:21:09
 * File Name: 2.cpp
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
typedef pair<double, double> pdd;
pdd p[256];
int n;
inline double calc(pdd a, pdd b)
{
    return (a.fi - b.fi)*(a.fi - b.fi) + (a.se - b.se) * (a.se - b.se);
}
int main() 
{
    n = 0;
    double x, y;
    while (~scanf("%lf%lf", &x, &y)) p[n++] = mp(x, y);
    
    REP(i, n)
    {
        FOR(j, i+1, n)
        {
            int len = calc(p[i], p[j]);
            if (len > 6.25) continue;
            
                
        }
    }
    
    
    
    
    return 0;
}

