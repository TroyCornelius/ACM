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
    //int child[kind];
    map<char,int> child;
    int fail, id;
    void clr() {
        //memset(child, 0, sizeof(child));
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
        //idx = (*(s+i)) - 'a';
        //if (s[i] < 'a' || s[i] > 'z') while (1);
        //cout <<*(s+i);
        //if (!t[p].child[idx]) {
        if (t[p].child.find(s[i]) == t[p].child.end()) {
            t[++tot].clr();
            t[p].child[s[i]] = tot;
        }
        p = t[p].child[s[i]];
    }
    //cout <<endl;
}
void build_ac_auto() {
    int head = 0, tail = 0;
    //que[tail++] = root;
    for (map<char,int>::iterator it = t[0].child.begin(); it != t[0].child.end(); it++) {
        t[it->se].fail = 0;
        que[tail++] = it->se;
    }
    while (head < tail) {
        //int u = que[head++];
        //for (int i = 0; i < kind; ++i) 
        for (map<char,int>::iterator it = t[que[head]].child.begin(); it != t[que[head]].child.end(); it++) {
            //if (t[u].child[i]) {
            /*
               int son = it->se;//t[u].child[i];
               int p = t[u].fail;
               if (u) {
               t[son].fail = t[p].child[it->fi];
               }
               que[tail++] = son;
             */
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
        //else {
        //int p = t[u].fail;
        //t[u].child[i] = t[p].child[i];
        //}
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
        //cout <<t[i].fail <<" "<<i <<endl;
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

/*
void update(int p) {
    tree[p] = max(tree[p], max(tree[p<<1], tree[p<<1|1]));
}
void modify(int p, int l, int r, int s, int t, int val) {
    if (s <= l && r <= t) {
        tree[p] = max(tree[p], val);
        return ;
    }
    int mid = (l + r) >>1;
    if (s <= mid) modify(p<<1, l, mid, s, t, val);
    if (t > mid) modify(p<<1|1, mid+1, r, s, t, val);
    //update(p);
}
void push_down(int p) {
    tree[p<<1] = max(tree[p<<1], tree[p]);
    tree[p<<1|1] = max(tree[p<<1|1], tree[p]);
}
int query(int p, int l, int r, int idx) {
    if (l == idx && r == idx) {
        return tree[p];
    }
    push_down(p);
    int mid = (l + r) >>1;
    if (idx <= mid) return query(p<<1, l, mid, idx);
    else return query(p<<1|1, mid+1, r, idx);
}
*/
void work() {
    memset(tree, 0, sizeof(tree));
    pw = 1; H = 0;
    while (pw <= tot + 3) pw <<=1, H++;
    int ans = 0;
    //cout <<tot <<" "<<dfsCnt <<endl;
    for (int i = 0; i < n; i++) {
        dp[i] = 0;
        int cur = 0;
        for (int j = st[i]; j < st[i] + len[i]; j++) {
            //cur = t[cur].child[str[j]-'a'];
            cur = t[cur].child[str[j]];
            //cout <<cur <<" ";
            int tmp = query(pos[cur].fi);
            //cout <<pos[cur].fi <<endl;
            //int tmp = query(1, 1, dfsCnt, pos[cur].fi);
            if (tmp > dp[i]) dp[i] = tmp;
         }
            //cout <<cur <<endl;
         //cout <<dp[i] <<endl;
         dp[i] += w[i];
         ans = max(ans, dp[i]);
         modify(pos[cur].fi, pos[cur].se, dp[i]);
         //cout <<pos[cur].fi <<" "<<pos[cur].se <<endl;
         //modify(1, 1, dfsCnt, pos[cur].fi, pos[cur].se, dp[i]);
         //cout <<i <<" "<<dp[i] <<endl;
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
            //cout <<w[i] <<endl;
            len[i] = strlen(str+st[i]);
            insert(str+st[i], len[i]);
            st[i+1] = st[i] + len[i];
        }
        build_ac_auto();
        build_tree();
        
        //REP(i, tot+1) cout <<pos[i].fi <<" "<<pos[i].se <<endl;
        
        pf("Case #%d: ", ++ca);
        work();
    }
    return 0;
}

