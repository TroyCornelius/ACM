/*
 * Author:  Troy
 * Created Time:  2012/8/22 15:44:12
 * File Name: 4381.cpp
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
#define Maxn 1010
using namespace std;
const int maxint = -1u>>1;
const int inf = 1<<29;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
pii op1[Maxn], op2[Maxn];
int n1, n2;
int dpl[Maxn], dpr[Maxn];
bool cmp2(pii a, pii b) {
    return a.fi > b.fi || (a.fi == b.fi && a.se < b.se);
}
void init_dp() {
    REP(j, n+2)
        dpl[j] = dpr[j] = inf;

    sort(op1+1, op1+n1+1);
    dpl[0] = 0;
    FOR(i, 1, n1+1) {
        FORD(j, op1[i].fi, op1[i].se)
            dpl[j] = min(dpl[j], dpl[j-op1[i].se] + 1);
    }
    sort(op2+1, op2+n2+1, cmp2);
    dpr[n+1] = 0;
    FOR(i, 1, n2+1) {
        FOR(j, op2[i].fi, n-op2[i].se+2)
            dpr[j] = min(dpr[j], dpr[j+op2[i].se] + 1);
    }
}
int main() {
    int T, ca = 0, type, a, b;
    sf("%d", &T);
    while (T--) {
        sf("%d%d", &n, &m);
        n1 = n2 = 0;
        REP(i, m) {
            sf("%d%d%d", &type, &a, &b);
            if (type == 1) op1[++n1] = mp(a, b);
            else op2[++n2] = mp(a, b);
        }
        init_dp();
        int ans1 = 0, ans2 = inf;
        REP(i, n+1)
            FOR(j, i+1, n+2) {
                if (dpl[i] != inf && dpr[j] != inf) {
                    if (i + n + 1 - j > ans1) ans1 = i + n + 1 - j, ans2 = dpl[i] + dpr[j];
                    else if (i + n + 1 - j == ans1) ans2 = min(ans2, dpl[i] + dpr[j]); 
                }
            }
        if (ans2 == inf) ans2 = 0;
        pf("Case %d: %d %d\n", ++ca, ans1, ans2);
        
    }
    return 0;
}


