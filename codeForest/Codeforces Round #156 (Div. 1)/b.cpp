/*
 * Author:  Troy
 * Created Time:  2012/12/17 0:02:03
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
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

ll n, x, y, c;

inline ll ABS(ll x) {
    return x < 0 ? -x : x;    
}
bool check(ll t) {
    ll cnt = 0;
    ll tx, ty, tmp, nx, ny, tot;
    
    //up-left
    ty = y - t;
    tx = x;
    if (ty <= 0) {
        tmp = ABS(ty) + 1;
        nx = max(tx - tmp, max(x - t - 1, 0LL));
        cnt += (tx - nx) * y;
        tx = nx;
        ty = 1;
    }
    ll len = (y - ty + 1);
    ll res = min(len, tx - max(x - t - 1, 0LL));
    if (len == 0) res = 0;
    cnt += (len + len - res + 1) * res / 2;
    
    //cout <<t <<" : "<<cnt <<endl;
    //down-left
    ty = y - t + 1;
    tx = x + 1;
    if (ty <= 0) {
        tmp = ABS(ty) + 1;
        nx = min(tx + tmp, min(n + 1, x + t + 1));
        cnt += (nx - tx) * y;
        ty = 1;
        tx = nx;
    }
    len = (y - ty + 1);
    res = min(len, min(x+t+1, n+1)-tx);
    if (len == 0) res = 0;
    cnt += (len + len - res + 1) * res / 2;
    
    //cout <<t <<" : "<<cnt <<endl;
    
    //up-right
    tx = x;
    ty = y + t;
    if (ty >= n+1) {
        tmp = ty - n;
        nx = max(tx-tmp, max(x-t, 0LL));
        cnt += (n - y) * (x - nx);
        tx = nx;
        ty = n;
    }
    len = (ty - y);
    res = min(len, tx-max(x-t, 0LL));
    if (len == 0) res = 0;
    cnt += (len + len - res + 1) * res / 2;
    
    //cout <<t <<" : "<<cnt <<endl;
    //down-right
    tx = x+1;
    ty = y + t - 1;
    if (ty >= n+1) {
        tmp = ty - n;
        nx = min(tx+tmp, min(n+1, x+t));
        cnt += (nx - tx) * (n - y);
        tx = nx;
        ty = n;
    }
    len = (ty - y);
    res = min(len, min(n+1,x+t)-tx);
    if (len == 0) res = 0;
    cnt += (len + len - res + 1) * res / 2;
    
    //cout <<t <<" : "<<cnt <<endl;
    //cout <<endl;
    return cnt >= c;
}
int main() {
    cin >>n >>x >>y >>c;
    ll lo = 0, hi = c, mid, ans;
    while (lo <= hi) {
        mid = (hi - lo) / 2 + lo;
        if (check(mid)) hi = mid-1, ans = mid;
        else lo = mid + 1;
    }
    cout <<ans <<endl;
    return 0;
}

