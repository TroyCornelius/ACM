/*
 * Author:  Troy
 * Created Time:  2012/12/28 2:15:26
 * File Name: aa.cpp
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
#define Maxn 100010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, x, p;
ll a[Maxn], t, mi;
int main() {
    sf("%d%d", &n, &x);
    x--;
    REP(i, n) sf("%I64d", &a[i]);
    mi = *min_element(a, a+n);
    for (p = x; a[p] != mi; p = (p-1+n)%n)
        --a[p];
    t = a[p];
    a[p] = 1LL*a[p]*n+(x-p+n)%n;
    a[p] += t;
    REP(i, n) a[i] -= t;
    REP(i, n) pf("%I64d%c", a[i], i==n-1?'\n':' ');
    return 0;
}

