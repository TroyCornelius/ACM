/*
 * Author:  Troy
 * Created Time:  2012/11/25 23:26:27
 * File Name: a.cpp
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, t;
int need, shop;
string s;
bool check(int tot) {
    int ti = 0, pre = 0;
    vector<pii> vec;
    REP(i, s.size()) {
        if (s[i] == 'H'){
            if (!tot) pre = i;
            tot--;
        }
        if (s[i] == 'S') {
            tot++;
            if (!tot) vec.pb(mp(pre, i));
        }
    }
    int p = n - 1;
    while (s[p] != 'H' && (vec.empty() || p > vec.back().se)) p--;
    ti = p + 1;
    REP(i, vec.size()) ti += (vec[i].se - vec[i].fi) * 2;
    int mi = ti;
    for (int i = (int)vec.size() - 1; i >= 0; i--) {
        ti -= (vec[i].se - vec[i].fi) * 2;
        mi = min(mi, ti + p - vec[i].fi);
    }
    return mi <= t;
}
int main() {
    ios::sync_with_stdio(false);
    cin >>n >>t;
    cin >>s;
    need = count(all(s), 'H');
    shop = count(all(s), 'S');
    int lo = max(need - shop, 0), hi = need, mid, ans = -1;
    while (lo <= hi) {
        mid = (lo + hi) >>1;
        if (check(mid)) ans = mid, hi = mid - 1;
        else lo = mid + 1;
    }
    cout <<ans <<endl;
    return 0;
}

