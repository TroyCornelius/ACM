/*
 * Author:  Troy
 * Created Time:  2012/11/25 23:26:27
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

const int inf = 1 << 29;
const double dinf = 1e30;
const ll linf = 1LL << 55;
const double eps = 1e-8;
double yl, yh, yw, xb, yb, r;
int main() {
    cin >> yl >> yh >> yw >> xb >> yb >> r;
    yl += r;
    double x = (yw - r - yl) * xb / (2 * yw - 2 * r - yl - yb);
    double a = (xb - x) * (yw - r - yh) / (yw - r - yb);
    a = x - a;
    if(yw - r - yh < 0) a = dinf;
    if(a + eps < r) {
        puts("-1");
    }
    else printf("%.11f\n", x);
    return 0;
}

