//Sample solution for the Bread Sorting problem in NCPC 2012 by Lukáš Poláček (lukasP)
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
#define trav(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)

typedef vector<int> vi;
typedef long long ll;
struct FenwickTree {
    int n;
    vector<int> s;
    FenwickTree(int _n) : n(_n) {
        s.assign(n, 0);
    }
    void update(int pos) {
        for (; pos < n; pos |= pos + 1)
            s[pos]++;
    }
    int query(int val) {
        int count = 0;
        for (; val >= 0; val = (val & (val + 1)) - 1)
            count += s[val];
        return count;
    }
};
int main()
{
    int n; scanf("%d", &n);
    vi a(n), b(n);
    FenwickTree s(n), t(n);
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
