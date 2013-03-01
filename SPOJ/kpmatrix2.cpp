#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>
#include <set>

#define Maxn 256
#define ll long long
using namespace std;

int n, m, A, B;
int a[253][253];
//int bb[Maxn][Maxn];
ll sum[253][253], ans;
int t[760], lim;
ll b[800];
multiset<long long> cnt;
inline void update(int idx, int val) {
    for (;idx <= lim; idx+=idx&-idx) t[idx] += val;
}
inline int query(int idx) {
    int ret = 0;
    for (;idx;idx-=idx&-idx) ret += t[idx];
    return ret;
}
inline int gsum(int a, int b) {
    return query(b) - query(a-1);
}

inline int getint() {
    int ret = 0;
    char ch;
    bool neg = false;
    while ((ch=getchar()) > '9' || ch < '0' && ch != '-');
    if (ch == '-') {
        neg = true;
        while ((ch = getchar()) > '9' || ch < '0');
    }
    do {
        ret = ret * 10 + ch - '0';
    }while ((ch=getchar())<='9' && ch >='0');
    if (neg) ret = -ret;
    return ret;
}
inline int bsearch(int l, int r, long long val) {
    int mid;
    while (l <= r) {
        mid = (l + r) >>1;
        if (b[mid] == val) return mid;
        else if (b[mid] > val) r = mid - 1;
        else l = mid + 1;
    }
    return mid;
} 
int main() 
{
    int i, j, x, y, tt;
    int tid, t1, t2;
    ll s;
    //sf("%d%d", &n, &m);
    n = getint();
    m = getint();
    if (n > m) {
        for (i = 1; i <= n; ++i) 
            for (j = 1; j <= m; ++j) {
                a[j][i] = getint();
            }
        swap(n, m);
    }
    else {
        for (i = 1; i <= n; ++i) 
            for (j = 1; j <= m; ++j) {
                a[i][j] = getint();
            }
    }
    for (i = 1; i <= n; ++i) 
            for (j = 1; j <= m; ++j) {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
            }
        A = getint();
        B = getint();
        ans = 0;
        for (x = 1; x <= n; ++x)
            for (y = x; y <= n; ++y) {
                for (i = 1; i <= m; ++i) {
                    s = sum[y][i] - sum[x-1][i];
                }
            }
        printf("%I64d\n", ans);
    return 0;
}
