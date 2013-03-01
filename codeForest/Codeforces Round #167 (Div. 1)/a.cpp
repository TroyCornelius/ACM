/*
 * Author:  Troy
 * Created Time:  2013/2/13 23:41:17
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
#define Maxn 100100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m, a[Maxn];
ll t[Maxn*4], mark[Maxn*4];
void push_up(int p) {
    t[p] = max(t[p<<1], t[p<<1|1]);
}
void build(int p, int l, int r) {
    mark[p] = 0;
    if (l == r) {
        t[p] = a[l];
        return;
    }
    int mid = (l + r)>>1;
    build(p<<1, l, mid);
    build(p<<1|1, mid+1, r);
    push_up(p);
}
void push_down(int p) {
    int lson = (p<<1), rson = (p<<1|1);
    //t[lson] = max(t[lson], mark[p]);
    //t[rson] = max(t[rson], mark[p]);
    t[lson] = t[rson] = mark[p];
    //cout <<mark[p] <<" *** " <<endl;
    mark[lson] = mark[rson] = mark[p];
    mark[p] = 0;
}

void update(int p, int l, int r, int le, int ri, ll val) {
    //cout <<l <<" "<<r <<" "<<le <<" "<<ri <<" "<<val <<endl;
    if (l <= le && ri <= r) {
        t[p] = val;
        mark[p] = val;
        return ;
    }
    if (mark[p]) push_down(p);
    int mid = (le + ri)>>1;
    if (l <= mid) update(p<<1, l, r, le, mid, val);
    if (r > mid) update(p<<1|1, l, r, mid+1, ri, val);
    push_up(p);
}
ll query(int p, int l, int r, int le, int ri) {
    //cout <<l <<" "<<r <<" "<<le <<" "<<ri <<" "<<t[p] <<endl;
    if (l <= le && ri <= r) {
        return t[p];
    }
    int mid = (le + ri)>>1;
    if (mark[p] > 0) push_down(p);
    ll ret = 0;
    if (l <= mid) ret = max(ret, query(p<<1, l, r, le, mid));
    if (r > mid) ret = max(ret, query(p<<1|1, l, r, mid+1, ri));
    //cout <<ret <<" ---- "<<endl;
    return ret;
}
/*
void update(int p, ll val) {
    for (; p; p-=p&-p) t[p] = max(t[p], val);
}
ll get_max(int p) {
    ll ret = 0;
    for (; p; p-=p&-p) ret = max(ret, t[p]);
    return ret;
}
*/
int main() {
    ios::sync_with_stdio(false);
    memset(t, 0, sizeof(t));
    cin >>n;
    int w, h, x;
    REP(i, n) {
        cin >>a[i+1];
    }
    build(1, 1, n);
    cin >>m;
    while (m--) {
        cin >>w >>h;
        ll ans = query(1, 1, w, 1, n);
        cout <<ans <<endl;
        //cout <<ans+h <<endl;
        update(1, 1, w, 1, n, ans+h);
    }
    return 0;
}

