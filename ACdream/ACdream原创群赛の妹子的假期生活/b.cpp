/*
 * Author:  Troy
 * Created Time:  2013/1/18 22:25:52
 * File Name: b.cpp
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

int n, m, d[Maxn];
struct BIT {
    int t[Maxn];
    void cls() {
        memset(t, 0, sizeof(t));
    }
    void update(int idx, int val) {
        for (; idx <= n; idx += idx&-idx) t[idx] += val;
    }
    int query(int idx) {
        int ret = 0;
        for (; idx; idx -= idx&-idx) ret += t[idx];
        return ret;
    }
    int get_sum(int a, int b) {
        return query(b) - query(a-1);
    }
}num[102];

int in_range(int l, int r, int a, int b) {
    int ret = 0;
    FOR(i, l, r+1)
        ret += num[i].get_sum(a, b);
    return ret;
}
int main() {
    //freopen("b.in", "r", stdin);
    //freopen("my.out", "w", stdout);
    int T, ans;
    sf("%d", &T);
    while (T--) {
        sf("%d%d", &n, &m);
        FOR(i, 1, 101) num[i].cls();
        FOR(i, 1, n+1) {
            sf("%d", &d[i]);
            num[d[i]].update(i, 1);
        }
        ans = 0;
        FOR(i, 1, n+1)
            ans += in_range(1, d[i]-1, i+1, n);
        pf("%d\n", ans);
        int op, x, y, old;
        while (m--) {
            sf("%d%d%d", &op, &x, &y);
            if (op == 0) {
                old = d[x];
                num[d[x]].update(x, -1);
                num[y].update(x, 1);
                d[x] = y;
                if (old < y) {
                    ans -= in_range(old+1, y, 1, x-1);
                    ans += in_range(old, y-1, x+1, n);
                }
                else if (old > y) {
                    ans += in_range(y+1, old, 1, x-1);
                    ans -= in_range(y, old-1, x+1, n);
                }
            }
            else {
                if (x > y) swap(x, y);
                int left_val = d[x], right_val = d[y];
                num[d[x]].update(x, -1); num[d[y]].update(x, 1);
                num[d[y]].update(y, -1); num[d[x]].update(y, 1);
                d[x] = right_val;
                d[y] = left_val;
                if (left_val < right_val) {
                    ans += in_range(left_val+1, right_val-1, x+1, y-1)*2  + 1; 
                    ans += in_range(left_val, left_val, x+1, y-1) + in_range(right_val, right_val, x+1, y-1);
                }
                else if (left_val > right_val){
                    ans -= in_range(right_val+1, left_val-1, x+1, y-1)*2  + 1; 
                    ans -= in_range(left_val, left_val, x+1, y-1) + in_range(right_val, right_val, x+1, y-1);
                }
            }
            pf("%d\n", ans);
        }
        //cout <<endl;
    }
    return 0;
}

