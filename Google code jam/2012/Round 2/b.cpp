/*
 * Author:  Troy
 * Created Time:  2012/5/26 23:23:09
 * File Name: b.cpp
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
#define Maxn 1010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-7;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, p[20];
double w, h, r[Maxn];
double ansx[Maxn], ansy[Maxn];

bool check()
{
    double x = 0, y = 0, ny;
    double k = r[p[0]];
    ansx[p[0]] = ansy[p[0]] = 0;
    
    FOR(i, 1, n)
    {
        if (x + r[p[i]] + r[p[i-1]] <= w + eps)
        {
            ansx[p[i]] = x + r[p[i]] + r[p[i-1]];
            x = ansx[p[i]];
            if (y > eps) ansy[p[i]] = y + r[p[i]];
            else ansy[p[i]] = 0;
            k = max(k, ansy[p[i]] + r[p[i]]);            
        }
        else
        {
            y = k; x = 0;
            ansx[p[i]] = 0;
            ansy[p[i]] = k + r[p[i]];
            k = max(k, ansy[p[i]] + r[p[i]]);
        }
        if (ansy[p[i]] > h) return false;
    }
    return true;
    
}
int main() 
{
    //freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B-small-attempt0.out", "w", stdout);
    int T, ca = 0;
    sf("%d", &T);
    while (T--)
    {
        sf("%d", &n);
        sf("%lf%lf", &w, &h);
        REP(i, n) sf("%lf", &r[i]);
        REP(i, 15) p[i] = i;
        pf("Case #%d: ", ++ca);
        do
        {
            if (check())
            {
                REP(i, n)
                {
                    pf("%.1f %.1f", ansx[i], ansy[i]);
                    if (i == n-1) pf("\n");
                    else pf(" ");
                }
                break;
            }
            
        }while (next_permutation(p, p+n));
        
    }
    return 0;
}

