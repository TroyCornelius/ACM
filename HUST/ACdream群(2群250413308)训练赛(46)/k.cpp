/*
 * Author:  Troy
 * Created Time:  2012/7/28 19:16:35
 * File Name: k.cpp
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
long long a, b, c, d, e, k, n;
long long f[11000];
int main() 
{
    int T, ca = 0;
    sf("%d", &T);
    while (T--)
    {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &k, &n);
        f[0] = a; f[1] = b; f[2] = c; f[3] = d; f[4] = e; f[5] = k;
        REP(i, 6) f[i] %= 10000007LL;
        for (int i = 6; i<=n; i++)
            f[i] = (f[i-1]+f[i-2]+f[i-3]+f[i-4]+f[i-5]+f[i-6]) % 10000007LL;
        pf("Case %d: %lld\n", ++ca, f[n]);
    }
    return 0;
}

