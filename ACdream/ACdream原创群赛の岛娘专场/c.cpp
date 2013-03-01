/*
 * Author:  Troy
 * Created Time:  2013/1/25 19:58:22
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
#define ll long long
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

struct BIT {
    int sz, t[Maxn*2];
    void init(int _sz) {
        sz = _sz;
        memset(t, 0, sizeof(t));
    }
    void insert(int idx, int val) {
        for (; idx <= sz; idx += idx&-idx) t[idx] += val;
    }
    int query(int idx) {
        int ret = 0;
        for (; idx; idx -= idx&-idx) ret += t[idx];
        return ret;
    }
    int get_sum(int a, int b) {
        return query(b) - query(a-1);
    }
};
BIT le, ri;
int n;
int val[Maxn];
vi b;
int seg[Maxn][2];
char op[Maxn];

int main() {
    while (~sf("%d", &n)) {
        REP(i, n) {
            sf("%s", op[i]);
            if (op[0] == 'D' || op[0] == 'Q') {
                sf("%d%d", &seg[i][0], &seg[i][1]);
                b.pb(seg[i][0]);
                b.pb(seg[i][1]);
            }
            else {
                sf("%d", &seg[i][0]);
                b.pb(seg[i][0]);
            }
        }
        sort(all(b));
        b.resize(unique(all(b))-b.begin());
        le.init(b.size());
        ri.init(b.size());
    }
    
    return 0;
}

