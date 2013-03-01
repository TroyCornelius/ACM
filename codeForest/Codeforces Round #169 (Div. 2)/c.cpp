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
#define Maxn 200100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, k;
ll t[Maxn], cnt[Maxn];
int a[Maxn];
void add(int idx, ll val) {
    for (; idx; idx-=idx&-idx) t[idx] += val;
}
ll query(int idx) {
    ll ret = 0;
    for (; idx <= n; idx += idx&-idx) ret += t[idx];
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin >>n >>k;
    REP(i, n) cin >>a[i];
    memset(t, 0, sizeof(t));
    sort(a, a+n);
    int u, v;
    while (k--) {
        cin >>u >>v;
        add(v, 1);
        add(u-1, -1);
    }
    ll ans = 0;
    FOR(i, 1, n+1) {
        cnt[i] = query(i);
    }
    sort(cnt+1, cnt+1+n);
    FOR(i, 1, n+1) {
        ans += 1LL * a[i-1] * cnt[i];
    }
    cout <<ans <<endl;
    return 0;
}

