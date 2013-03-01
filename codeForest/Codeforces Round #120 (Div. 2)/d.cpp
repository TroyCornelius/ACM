/*
 * Author:  Troy
 * Created Time:  2012/5/17 0:03:44
 * File Name: d.cpp
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
#define Maxn 400010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, k, f[Maxn];
long long ans;
pii a[Maxn];


bool cmp(const pii a1, const pii a2)
{
    return (a1.fi < a2.fi || (a1.fi == a2.fi && a1.se < a2.se));
}
int main() 
{
    sf("%d%d", &n, &k);    
    REP(i, n)
    {
        sf("%d", &a[i] + 1);
        a[i].se = i;
    }
    memset(f, -1, sizeof(f));   
    sort(a, a+n, cmp);
    int le = 0, ri = 0;
    while (le < n && ri < n)
    {
        if (a[le].fi != a[ri].fi)
        {
            le = ri;
            continue;
        }
        while (ri-le+1 < k && ri < n && a[ri].fi == a[le].fi) ri++;
        if (ri-le+1 >= k && ri < n && a[ri].fi == a[le].fi)
        {
            int x = a[le].se, y = a[ri].se;
            if (f[x] == -1) f[x] = y;
            else f[x] = min(f[x], y);
        }
    }

    return 0;
}

