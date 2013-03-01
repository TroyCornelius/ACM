/*
 * Author:  Troy
 * Created Time:  2012/5/2 22:45:23
 * File Name: l.cpp
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

int n, m, k;

bool f[1010][1010];
int x[1010], y[1010];

inline bool check(long long tx, long long ty, long long r)
{
    return tx*tx+ty*ty <= r;
}
int main() 
{
    int tx, ty;
    long long r;
    sf("%d%d%d", &n, &m, &k);
    REP(i, n) sf("%d%d", &x[i], &y[i]);
    
    memset(f, false, sizeof(f));
    REP(i, m)
    {
        sf("%I64d%d%d", &r, &tx, &ty);
        r = r * r;
        REP(j, n)
            if (check(x[j]-tx, y[j]-ty, r)) f[j][i] = true;        
    }
    int ans;
    while (k--)
    {
        sf("%d%d", &tx, &ty);
        tx--; ty--;
        ans = 0;
        REP(i, m) ans += f[tx][i] ^ f[ty][i];
        pf("%d\n", ans);
    }
    
    return 0;
}

