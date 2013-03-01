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
#define Maxn 101000
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, q;
vi g[Maxn];

struct BIT{
    vi t;
    int lim;
    void init(int mx) {
        lim = mx;
        t.resize(mx+3);
        REP(i, t.size()) t[i] = 0;
    }
    void modify(int idx, int val) {
        if (!idx) return;
        for (; idx; idx -= idx&-idx) t[idx] += val;
    }
    int query(int idx) {
        int ret = 0;
        for (; idx <= lim; idx += idx & -idx) 
            ret += t[idx];
        return ret;
    }
};

BIT rs;
vector<BIT> seg;
int dep[Maxn], id[Maxn], m, len[Maxn];
int main() {
    ios::sync_with_stdio(false);
    cin >>n >>q;
    int u, v, fa, tot;
    REP(i, n-1) {
        cin >>u >>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dep[1] = m = id[1] = 0;
    REP(i, g[1].size()) {
        int v = g[1][i];
        ++m;
        u = v, fa = 1;
        tot = 0;
        bool flag = true;
        while (flag) {
            tot++;
            dep[u] = dep[fa] + 1;
            id[u] = m;
            flag = false;
            REP(j, g[u].size()) {
                if (g[u][j] == fa) continue;
                fa = u;
                u = g[u][j];
                flag = true;
            }
        }
        BIT tmp;
        tmp.init(tot);
        seg.pb(tmp);
    }
    
    int op, x, d, ans1 = 0;
    rs.init(n);
    while (q--) {
        cin >>op;
        if (op == 0) {
            cin >>v >>x >>d;
            if (v != 1) {
                seg[id[v]-1].modify(min(dep[v]+d, seg[id[v]-1].lim), x);
                int res = d - dep[v];
                if (res >= 0) {
                    rs.modify(res, x);
                    seg[id[v]-1].modify(min(res, min(dep[v]+d, seg[id[v]-1].lim)), -x);
                    ans1 += x;
                }
                else if (res < 0) {
                    seg[id[v]-1].modify(dep[v]-d-1, -x);
                }
            }
            else {
                rs.modify(d, x);
                ans1 += x;
            }
        }
        else {
            cin >>v;
            if (v == 1) {
                cout <<ans1 <<endl;
            }
            else {
                cout <<rs.query(dep[v]) + seg[id[v]-1].query(dep[v]) <<endl;
            
            }
        }
    }
    return 0;
}

