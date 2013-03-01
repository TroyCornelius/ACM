//Sample solution for the Bread Sorting problem in NCPC 2012 by Lukáš Poláček (lukasP)
#include <vector>
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
#define trav(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)

typedef vector<int> vi;
typedef long long ll;
struct Buckets {
    int n, b_size;
    vector<int> s;
    vector<bool> t;
    Buckets(int _n) : n(_n) {
        b_size = int(sqrt(n) + 1.1);
        s.assign((n + b_size - 1) / b_size, 0);
        t.assign(n, false);
    }
    void update(int pos) {
        t[pos] = true;
        s[pos / b_size]++;
    }
    int query(int val) {
        int b_ind = val / b_size;
        int res = 0;
        rep(i,0,b_ind)
            res += s[i];
        rep(i,b_ind*b_size,val)
            res += t[i];
        return res;
    }
};
int main()
{
    int n; scanf("%d", &n);
    vi a(n), b(n);
    Buckets s(n), t(n);
    ll ia = 0, ib = 0;
    rep(i,0,n)
    {
        scanf("%d", &a[i]);
        a[i]--;
        ia += i - s.query(a[i]);
        s.update(a[i]);
    }
    rep(i,0,n)
    {
        scanf("%d", &b[i]);
        b[i]--;
        ib += i - t.query(b[i]);
        t.update(b[i]);
    }

    printf((ia % 2 != ib % 2) ? "Impossible\n" : "Possible\n");
}
