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
#define Maxn 90000
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int cmax = 27;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

struct Tnode {
    Tnode *f, *ch[cmax];
    int l, k;
}pool[Maxn*2+20], *init, *tail;

int q[Maxn*2+20], qh, qt, v[Maxn+20], p[Maxn*2+20], tot;
int pt, hash[Maxn*2+20][cmax+2];
char ch[Maxn*2+20][cmax+2];

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
//int lim;
void solve(int k, int A) {
    //if (k > lim) {puts("INVALID");return;}
    //else {
        pt = 0;
        while (k) {
            for (int i = 0, tmp; hash[A][i]; ++i) {
                //cout <<hash[A][i] <<" "<<k <<endl;
                if (k > pool[tmp = hash[A][i]].k) k-= pool[tmp].k;
                else {
                    //if (ch[A][i] == 'a'+26) {puts("INVALID");return;}
                    str[++pt] = ch[A][i], A = tmp, --k;
                    break;
                }
            }
        }
        str[pt+1] = '\0';
        puts(str+1);
    //}
}
int main() {
    int T, ca = 0;
    //sf("%d", &T);
    //while (T--) {
        //sf("%d", &n);
        len = 0;
        tot = 0;
        init = tail = pool + (++tot);
        init->k = 1, init->l = 0;

        //REP(i, n) {
            sf("%s", str);
            len = strlen(str);
            REP(j, len) add(str[j] - 'a');
            //add(26);
            //len += tl;
        //}
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
        //pf("Case %d:\n", ++ca);
        //lim = 0;
        //int A = init - pool;
        //REP(i, 26) 
            //if (hash[A][i]) lim += pool[hash[A][i]].k;
        //cout <<lim <<endl;
        while (Q--) {
            sf("%d", &k);
            solve(k, init - pool);
        }
    //}
    return 0;
}

