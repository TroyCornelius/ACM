/*
 * Author:  Troy
 * Created Time:  2012/9/11 0:48:47
 * File Name: 
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
#define Maxn 100010
using namespace std;
const int inf = 1<<29;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, x;
int a[Maxn], b[Maxn];
int main() 
{
    sf("%d%d", &n, &x);
    REP(i, n) sf("%d", &a[i]);
    REP(i, n) sf("%d", &b[i]);
    sort(a, a+n);
    sort(b, b+n);
    b[n] = x;
    int mi = inf, p1, p2;
    for (int i = 0; i < n; ++i) {
        int loc = lower_bound(b, b+n+1, x - a[i]) - b;
        if (loc == n) continue;
        if (a[i] + b[loc] < mi) {
            mi = a[i] + b[loc];
            p1 = i; p2 = loc;
        }
    }
    //cout <<mi <<" "<<p1 <<" " <<p2 <<endl;
    int mx = 0, cnt = 0;
    int x = n-1, y = 0;
    while (x >= 0 && y < n) {
        while (y < n && a[x] + b[y] < mi) ++y;
        if (x == p1) {x--;continue;}
        if (y == p2) {y++;continue;}
        if (y < n) {
            x--; y++;
            cnt++;
        }
    }
    mx = cnt;
    //cout <<mx <<" "<<cnt <<endl;
    cnt = 0;
    x = 0; y = n-1;
    while (x < n && y >= 0) {
        if (y == p2) {y--;continue;}
        while (x < n && (x == p1 || a[x] + b[y] < mi)) x++;
        if (x < n) {
            cnt++;
            x++; y--;
        }
    }
    //cout <<mx <<" "<<cnt <<endl;
    if (cnt > mx) cnt = mx;
    pf("1 %d\n", mx + 1);
    return 0;
}

