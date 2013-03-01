/*
 * Author:  Troy
 * Created Time:  2012/6/10 23:58:58
 * File Name: bb.cpp
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

int n, m;
pii a[200100];
bool cmp(const pii &b, const pii &c)
{
    //return b.se < c.se || (b.se == c.se && b.fi < c.fi);
    if (b.se != c.se) return b.se < c.se;
    else return b.fi < c.fi;
}
int main() 
{
    while (~sf("%d%d", &n, &m)){
    REP(i, m)
        a[i] = mp(i+1, abs((m+1) - 2*(i+1)));
    sort(a, a+m, cmp);
    int p = 0;
    REP(i, n)
    {
        pf("%d\n", a[p++].fi);
        if (p >= m) p = 0;
    }
    }
    return 0;
}

