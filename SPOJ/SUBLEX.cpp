/*
 * Author:  Troy
 * Created Time:  2012/8/18 21:45:38
 * File Name: 1010.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <cctype>
#include <functional>
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
using namespace std;
const int cmax = 26;
#define Maxn 90000
struct Tnode {
    Tnode *f, *ch[cmax];
    int l, k;
}pool[Maxn*2+10], *init, *tail;
int q[Maxn*2+10], qh, qt, v[Maxn+10], p[Maxn*2+10], tot;
int pt, hash[Maxn*2+10][cmax+2];
char ch[Maxn*2+10][cmax+2];
int n, len;
char str[Maxn];
void add(int c) {
    Tnode *q = pool + (++tot), *p = tail;
    q->l = p->l + 1, q->k = 1;
    for (; p&& !p->ch[c]; p= p->f) p->ch[c] = q;
    tail = q;
    if (!p) q->f = init;
    else {
        if (p->ch[c]->l == p->l + 1) q->f = p->ch[c];
        else {
            Tnode *u = p->ch[c], *r = pool + (++tot);
            memcpy(r->ch, u->ch, sizeof(u->ch));
            r->k = 1, r->f = u->f;
            r->l = p->l + 1;
            q->f = u->f = r;
            for (; p && p->ch[c] == u; p = p->f) p->ch[c] = r;
        }
    }
}
inline void addhash(int a, int j, int k) {
    pool[a].k += pool[a].ch[j]->k;
    hash[a][k] = pool[a].ch[j] - pool;
    ch[a][k] = j + 'a';
}
int lim;
void solve(int k, int A) {
    //if (k > lim) {puts("INVALID");return;} //如果查询的k比所有合法子串数还多的话则输出INVALID
    //else {
        pt = 0;
        while (k) {
            for (int i = 0, tmp; hash[A][i]; ++i) {
                if (k > pool[tmp = hash[A][i]].k) k-= pool[tmp].k;
                else {
                    str[++pt] = ch[A][i], A = tmp, --k;
                    break;
                }
            }
        }
        str[pt+1] = '\0';
        puts(str+1);
}
int main() {
        len = 0;
        tot = 0;
        init = tail = pool + (++tot);
        init->k = 1, init->l = 0;
        sf("%s", str);
        len = strlen(str);
        REP(j, len) add(str[j] - 'a');
        FOR(i, 1, tot+1) ++v[pool[i].l];
        FOR(i, 1, len+1) v[i] += v[i-1];
        FOR(i, 1, tot+1) p[v[pool[i].l]--] = i;
        for (int i = tot, j, now; i; --i) {
            for (now = j = 0; j < cmax; ++j)
                if (pool[p[i]].ch[j]) addhash(p[i], j, now++);
            hash[p[i]][now] = 0;
        }
        int Q, k;
        sf("%d", &Q);
        //lim = 0;
        //int A = init - pool;
        //REP(i, 26) 
            //if (hash[A][i]) lim += pool[hash[A][i]].k; //计算合法子串数
        while (Q--) {
            sf("%d", &k);
            solve(k, init - pool);
        }
    return 0;
}
Input:
aaa
2
2
3
Output:
aa
aaa

