/*
 * Author:  Troy
 * Created Time:  2012/9/14 10:55:00
 * File Name: 4117.cpp
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
#define Maxn 20010
#define Maxm 300010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
int n, w[Maxn];
int st[Maxn], len[Maxn];
char str[Maxm];
int dp[Maxn];
const int kind = 30;
const int maxn = Maxm ;
int root, tot;
int que[maxn];
struct Tnode {
    map<char,int> child;
    int fail, id;
    void clr() {
        child.clear();
        fail = id = 0;
    }
}t[maxn];
void init() {
    root = tot = 0;
    t[root].clr();
}
void insert(char *s, int len) {
    int p = root, idx;
    REP(i, len) {
        if (t[p].child.find(s[i]) == t[p].child.end()) {
            t[++tot].clr();
            t[p].child[s[i]] = tot;
        }
        p = t[p].child[s[i]];
    }
}
void build_ac_auto() {
    int head = 0, tail = 0;
    for (map<char,int>::iterator it = t[0].child.begin(); it != t[0].child.end(); it++) {
        t[it->se].fail = 0;
        que[tail++] = it->se;
    }
    while (head < tail) {
        for (map<char,int>::iterator it = t[que[head]].child.begin(); it != t[que[head]].child.end(); it++) {
            t[it->se].fail = 0;
            int u = que[head];
            while (u) {
                u = t[u].fail;
                if (t[u].child.count(it->fi)) {
                    t[it->se].fail = t[u].child[it->fi];
                    break;
                }
            }
            que[tail++] = it->se;
        }
        head++;
    }
}
struct Edge {
    int v, next;
}et[maxn+1000];
int eh[maxn], total;
pii pos[maxn];
void addedge(int u, int v) {
    Edge tmp = {v, eh[u]};
    et[total] = tmp;
    eh[u] = total++;
}
int dfsCnt;
void dfs(int u) {
    pos[u].fi = pos[u].se = ++dfsCnt;
    for (int i = eh[u]; i != -1; i = et[i].next) {
        int v = et[i].v;
        dfs(v);
        pos[u].se = pos[v].se;
    }
}
void build_tree() {
    total = 0;
    memset(eh, -1, sizeof(eh));
    for (int i = 1; i <= tot; i++) {
        addedge(t[i].fail, i);
    }
    dfsCnt = 0;
    dfs(0);
}
int pw, tree[maxn*2], H;
void put_down(int p) {
    int lson = (p<<1), rson = (p<<1|1);
    tree[lson] = max(tree[lson], tree[p]); 
    tree[rson] = max(tree[rson], tree[p]);
}
void push_down(int p) {
    for (int i = H; i; --i) put_down(p >> i);
}
int query(int l) {
    push_down(l+pw);
    return tree[l + pw];
}
void modify(int l, int r, int val) {
    for (l += pw-1, r += pw + 1; l^r^1; l>>=1, r>>=1) {
        if (~l&1) tree[l^1] = max(tree[l^1], val);
        if (r&1) tree[r^1] = max(tree[r^1], val);
    }
}
void work() {
    memset(tree, 0, sizeof(tree));
    pw = 1; H = 0;
    while (pw <= tot + 3) pw <<=1, H++;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 0;
        int cur = 0;
        for (int j = st[i]; j < st[i] + len[i]; j++) {
            cur = t[cur].child[str[j]];
            int tmp = query(pos[cur].fi);
            if (tmp > dp[i]) dp[i] = tmp;
        }
        dp[i] += w[i];
        ans = max(ans, dp[i]);
        modify(pos[cur].fi, pos[cur].se, dp[i]);
    }
    pf("%d\n", ans);
}
int main() {
    int T, ca = 0;
    sf("%d", &T);
    while (T--) {
        sf("%d", &n);
        init();
        st[0] = 0;
        REP(i, n) {
            sf("%s %d", str+st[i], &w[i]);
            len[i] = strlen(str+st[i]);
            insert(str+st[i], len[i]);
            st[i+1] = st[i] + len[i];
        }
        build_ac_auto();
        build_tree();
        pf("Case #%d: ", ++ca);
        work();
    }
    return 0;
}
