/*
 * Author:  Troy
 * Created Time:  2013/1/23 0:35:55
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
#define ull unsigned long long
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n;
int cx[1010], cy[1010];
ull bit[1010][18];
vector<pair<int,pii> >sch;
vi dx[1010];
bool cmp(pii a, pii b) {
    return a.fi > b.fi || (a.fi == b.fi && a.se < b.se);
}
int main() {
    sf("%d", &n);
    int x, y;
    memset(cx, 0, sizeof(cx));
    memset(cy, 0, sizeof(cy));
    memset(bit, 0, sizeof(bit));
    sch.clear();
    REP(i, n-1) {
        sf("%d%d", &x, &y);
        cx[x]++;
        cy[y]++;
        bit[x][y/63] |= (1LL<<(y%63));
    }
    
        //puts("damn1");
    for (int i = n; i >= 1; --i) {
        //cout <<i <<" : " <<endl;
        //int mx = max_element(cx+1, cx+n+1) - cx;
        int mx = i, val = cx[mx];
        for (int j = i-1; j >= 1; j--)
            if (cx[j] > val) val = cx[j], mx = j;
        if (mx != i) {
            swap(cx[i], cx[mx]);
            sch.pb(mp(1, mp(i, mx)));
            REP(j, 18) swap(bit[i][j], bit[mx][j]);
        }
        vector<pii> tmp;
        FOR(j, 1, n+1) tmp.pb(mp(cy[j], j));
        sort(all(tmp), cmp);
        //puts("damn1");
        //cout <<tmp.size() <<endl;
        //REP(j, tmp.size()) cout <<tmp[j].fi <<" "<<tmp[j].se <<endl;
        //puts("--------------");
        FOR(j, 1, n+1) {
            if (tmp[j-1].fi == 0) break;
            //cout <<i <<" "<<j <<" " <<tmp[j-1].fi <<" "<<tmp[j-1].se <<endl;
            if (j != tmp[j-1].se) {
                sch.pb(mp(2, mp(j, tmp[j-1].se)));
                swap(cy[j], cy[tmp[j-1].se]);
                ull v1 = (bit[i][j/63]&(1LL<<(j%63)));
                ull v2 = (bit[i][tmp[j-1].se/63]&(1LL<<(tmp[j-1].se%63)));
                if (v1 != v2) {
                    bit[i][j/63] ^= (1LL<<(j%63));
                    bit[i][tmp[j-1].se/63] ^= (1LL<<(tmp[j-1].se%63));
                }
            }
        }
        //puts("damn1");
        cx[i] = 0;
        REP(j, 18)
            REP(k, 63)
                if ((1LL<<k)&bit[i][j]) cy[i*63+k]--;
        //cout <<sch.size() <<" "<<i <<endl;
    }
    pf("%d\n", sch.size());
    REP(i, sch.size())
        pf("%d %d %d\n", sch[i].fi, sch[i].se.fi, sch[i].se.se);
    return 0;
}

