/*
 * Author:  Troy
 * Created Time:  2012/11/12 1:07:35
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
using namespace std;
const int inf =  1<<30;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
vector<pii> d;
int n;
int main() {
    cin >>n;
    d.clear();
    int le = inf, ri = 0;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        le = min(le, l);
        ri = max(ri, r);
        d.pb(mp(l, r));
    }
    int ans = -1;
    for(int i = 0; i < n; i++) {
        if(d[i].fi <= le && ri <= d[i].se) {
            ans = i + 1;
        }
    }
    cout << ans << endl;
    return 0;
}

