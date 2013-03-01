/*
 * Author:  Troy
 * Created Time:  2012/6/12 21:20:38
 * File Name: c.cpp
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
#define Maxn 1600
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, id[Maxn];
pii p[Maxn];
vi g[Maxn];


bool check(int fb)
{
    id[0] = fb;
}

int main() 
{
    int u, v;
    sf("%d", &n);
    REP(i, n-1)
    {
        sf("%d%d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }
    REP(i, n) sf("%d%d", &p[i].fi, &p[i].se);
    sort(p, p+n);
    
    FOR(i, 1, n+1)
    {
        if (check(i))
        {
            REP(j, n) pf("%d%c", id[j], j == n-1 ? '\n' : ' ');
        }
    }
    
    return 0;
}

