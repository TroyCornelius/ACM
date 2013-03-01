/*
 * Author:  Troy
 * Created Time:  2012/5/18 20:03:40
 * File Name: g.cpp
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
typedef pair<double,double>pdd;

int n, ans;
pii p[800];
map<pii,int> ct;
int gcd(int a, int b)
{
    if (a % b == 0) return b;
    else return gcd(b, a%b);
}
int main() 
{
    int T, ca = 0 ;
    sf("%d", &T);
    while (T--)
    {
        sf("%d", &n);
        REP(i, n) sf("%d%d", &p[i].fi, &p[i].se);
        ans = 1;
        int mx;
        if (n == 1)
        {
            pf("Case %d: %d\n", ++ca, ans);
            continue;
        }
        REP(i, n)
        {
            ct.clear();
            REP(j, n)
                if (i != j)
                {
                    int a = p[j].se - p[i].se;
                    int b = p[j].fi - p[i].fi;
                    if (b == 0) ct[pii(-1,-1)]++;
                    else
                    {
                        int c = gcd(a, b);
                        ct[pii(a/c, b/c)]++;
                    }
                }
            mx = 1;
            for (map<pii,int>::iterator it = ct.begin(); it != ct.end(); it++)
                mx = max(mx, it->se);
            if (mx + 1 > ans) ans = mx + 1;            
        }
        pf("Case %d: %d\n", ++ca, ans);
    }

    return 0;
}

