/*
 * Author:  Troy
 * Created Time:  2012/10/4 12:06:00
 * File Name: 2475_link_cut_tree.cpp
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
#define Maxn 500100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int le[Maxn], ri[Maxn], p[Maxn];
int n;
bool rt[Maxn];
inline void getint(int&a) {
    int b; a=0;
    while ((b=getchar())<'0'||b>'9'); a=b-'0';
    while ((b=getchar())>='0'&&b<='9') a=a*10+b-'0';
}
inline void Set(int l[], int y, int x) {
    l[y] = x, p[x] = y;
}
inline void Rotate(int x) {
    int y = p[x], z = p[y];
    if (!rt[y]) Set(y == le[z] ? le : ri, z, x);
    else p[x] = z;
    
    if (x == le[y]) Set(le, y, ri[x]), Set(ri, x, y);
    else Set(ri, y, le[x]), Set(le, x, y);
    
    if (rt[y]) rt[y] = false, rt[x] = true;
}
inline void Splay(int x) {
    while (!rt[x]) Rotate(x);
}
int Access(int x) {
    int y = 0;
    do {
        Splay(x);
        rt[ri[x]] = true; rt[ri[x] = y] = false;
        x = p[y = x];
    }while (x);
    return y;
}
inline int get_root(int x) {
    for (x = Access(x); le[x]; x = le[x]);
    return x;
}
inline int Lca(int x, int y) {
    int ret; 
    Access(y); 
    y = 0;
    do {
        Splay(x);
        if (!p[x]) ret = x;
        rt[ri[x]] = true; rt[ri[x] = y] = false;
        x = p[y = x];
    } while (x);
    return ret;
}
void Link(int y, int x) {
    if (y && (x == y || get_root(x) == get_root(y) && Lca(x, y) == x)) return;
    Access(x);
    Splay(x);
    rt[le[x]] = true;
    le[x] = p[le[x]] = 0, p[x] = y;
    Access(x);
}
int main() {
    bool flag = false;
    while (~sf("%d", &n)) {
        if (flag) puts("");
        else flag = true; 
        FOR(i, 1, n+1) {
            rt[i] = true;
            getint(p[i]);
        }
        char op[6];
        int Q, x, y;
        getint(Q);
        while (Q--) {
            sf("%s", op);
            if (op[0] == 'Q') {
                getint(x);
                pf("%d\n", get_root(x));
            }
            else {
                getint(x); getint(y);
                Link(y, x);
            }
        }
        memset(p, 0, sizeof(p));
        memset(le, 0, sizeof(le));
        memset(ri, 0, sizeof(ri));
    }
    return 0;
}

