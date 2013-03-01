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
#define Maxn 100100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, ans;
pii a[Maxn], b[Maxn];
multiset<int> s;
int main() {
    int T;
    sf("%d", &T);
    while (T--) {
        s.clear();
        sf("%d", &n);
        REP(i, n) {
            sf("%d%d", &a[i].fi, &a[i].se);
        }
        REP(i, n) {
            sf("%d%d", &b[i].fi, &b[i].se);
        }
        sort(a, a+n);
        sort(b, b+n);
        int p = 0;
        ans = 0;
        for (int i = 0; i < n; ++i) {
            while (p < n && b[p].fi <= a[i].fi) {
                s.insert(b[p].se);
                p++;
            }
            if (s.size() >= 1) {
                multiset<int>::iterator it = s.lower_bound(a[i].se);
                if (it == s.end()) it--;
                if (it != s.begin() && *it > a[i].se) it--;
                if (*it <= a[i].se ) {
                    s.erase(it);
                    ans++;
                }
            }
        }
        pf("%d\n", ans);
    }
    return 0;
}

