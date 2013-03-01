/*
 * Author:  Troy
 * Created Time:  2012/12/14 20:13:33
 * File Name: a.cpp
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
#define ll long long
#define sf scanf
#define pf printf
#define Maxn 10100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

pii d[Maxn];
int n, k;
bool cmp(const pii &a, const pii &b) {
    return a.fi - a.se > b.fi - b.se || (a.fi-a.se==b.fi-b.se && a.fi < b.fi);
}
int main() {
    while (~sf("%d%d", &n, &k)) {
        REP(i, n) sf("%d", &d[i].fi);
        REP(i, n) sf("%d", &d[i].se);
        sort(d, d+n, cmp);
        double ans = 0.0, sum = 0.0;
        REP(i, k)
            ans += log(d[i].fi), sum += log(d[i].se);
        pf("%.3f\n", ans/sum);
        
    }
    return 0;
}

