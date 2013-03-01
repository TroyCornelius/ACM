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
#define Maxn 1000100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int m, n;
char s[Maxn];
int le[Maxn*3], ri[Maxn*3];
ull hash[Maxn*3][2], pw[Maxn];
void push_up(int p) {
    int lson = (p<<1), rson = (p<<1|1);
    int Llen = ri[lson] - le[lson] + 1, Rlen = ri[rson] - le[rson] + 1;
    hash[p][0] = hash[lson][0] * pw[Rlen] + hash[rson][0];
    hash[p][1] = hash[rson][1] * pw[Llen] + hash[lson][1];
}
void build(int p, int l, int r) {
    le[p] = l, ri[p] = r;   
    if (l == r) {
        hash[p][0] = hash[p][1] = s[l] - 'a' + 1;
        return;
    }
    int mid = (l + r) >>1;
    build(p<<1, l, mid);
    build(p<<1|1, mid+1, r);
    push_up(p);
}
void modify(int p, int idx, ull val) {
    if (le[p] == ri[p] && le[p] == idx) {
        hash[p][0] = hash[p][1] = val;
        return;
    }
    int mid = (le[p] + ri[p]) >>1;
    if (idx <= mid) modify(p<<1, idx, val);
    else modify(p<<1|1, idx, val);
    push_up(p);
}
pair<ull,ull> query(int p, int l, int r) {
    if (l <= le[p] && ri[p] <= r) {
        return mp(hash[p][0], hash[p][1]);
    }
    int mid = (le[p] + ri[p]) >>1;
    if (r <= mid) return query(p<<1, l, r);
    else if (l > mid) return query(p<<1|1, l, r);
    else {
        pair<ull,ull> t1 = query(p<<1, l, r);
        pair<ull,ull> t2 = query(p<<1|1, l, r);
        pair<ull,ull> ret;
        ret.fi = t1.fi * pw[min(ri[p<<1|1], r)-le[p<<1|1]+1] + t2.fi;
        ret.se = t1.se + t2.se * pw[ri[p<<1]-max(l, le[p<<1])+1];
        return ret;
    }
}
int main() {
    pw[0] = 1;
    FOR(i, 1, 1000001) pw[i] = pw[i-1] * 29;
    while (~sf("%s", s)) {
        n = strlen(s);
        build(1, 0, n-1);
        sf("%d", &m);
        char op[3], ch[3];
        int x, y;
        while (m--) {
            sf("%s", op);
            if (op[0] == 'Q') {
                sf("%d%d", &x, &y);
                x--; y--;
                pair<ull,ull> ans = query(1, x, y);
                if (ans.fi == ans.se) puts("yes");
                else puts("no");
            }
            else {
                sf("%d%s", &x, ch);
                x--;
                modify(1, x, ch[0]-'a'+1);
            }
        }
    }
    return 0;
}


