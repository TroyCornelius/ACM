#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>

#define Maxn 256
#define ll long long
using namespace std;

int n, m, A, B;
int a[253][253];
//int bb[Maxn][Maxn];
ll sum[253][253], ans;
int t[256], lim;
ll b[800];
inline void update(int idx, int val) {
    for (;idx <= lim; idx+=idx&-idx) t[idx] += val;
}
inline int query(int idx) {
    int ret = 0;
    for (;idx;idx-=idx&-idx) ret += t[idx];
    return ret;
}
inline int gsum(int a, int b) {
    return query(b) - query(a);
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
    scanf("%d%d", &n, &m);
    if (n > m) {
        for (i = 1; i <= n; ++i) 
            for (j = 1; j <= m; ++j) {
                //scanf("%d", &a[j][i]);
                a[j][i] = getint();
            }
        swap(n, m);
    }
    else {
        for (i = 1; i <= n; ++i) 
            for (j = 1; j <= m; ++j) {
                    //scanf("%d", &a[i][j]);
                    a[i][j] = getint();
                }
        }
        for (i = 1; i <= n; ++i) 
            for (j = 1; j <= m; ++j) {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
            }
        //scanf("%d%d", &A, &B);
        A = getint();
        B = getint();
        ans = 0;
        for (x = 1; x <= n; ++x)
            for (y = x; y <= n; ++y)
            {
                lim = 0;
                for (i = 1; i <= m; ++i) {
                    s = sum[y][i] - sum[x-1][i]; 
                    b[++lim] = s;
                }
                b[++lim] = 0;
                sort(b+1, b+lim+1);
                lim = unique(b+1, b+1+lim) - b;
                memset(t, 0, sizeof(t));
                tid = lower_bound(b+1, b+lim, 0) - b;
                update(tid, 1);
                for (i = 1; i <= m; ++i) {
                    s = sum[y][i] - sum[x-1][i];
                    t1 = upper_bound(b+1, b+lim, s-A) - b - 1;
                    t2 = lower_bound(b+1, b+lim, s-B) - b - 1;
                    ans = ans + gsum(t2, t1);
                    tid = lower_bound(b+1, b+lim, s) - b;
                    update(tid, 1);
                }
            }
        printf("%I64d\n", ans);
    return 0;
}
