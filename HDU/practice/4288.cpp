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
#include <rope>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
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

rope<char> aaa;

int n;
char op[Maxn][5];
int num[Maxn];
int b[Maxn], m;
long long sum[Maxn*3][6];
int cnt[Maxn*3], pw;
void build() {
    pw = 1;
    memset(sum, 0, sizeof(sum));
    memset(cnt, 0, sizeof(cnt));
    while (pw <= m + 3) pw <<=1;
}
void update(int p) {
    int lson = (p<<1), rson = (p<<1|1);
    cnt[p] = cnt[lson] + cnt[rson];
    REP(i, 5) {
        sum[p][i] = sum[lson][i] + sum[rson][((i - cnt[lson])%5+5)%5];
    }
}
void modify(int x, int val, int flag) {
    cnt[x+pw] += flag;
    sum[x+pw][0] += val * flag;
    for (int p = (x + pw)>>1; p ; p>>=1) update(p);
}
int main() {
    while (~sf("%d", &n)) {
        m = 0;
        REP(i, n) {
            sf("%s", op[i]);
            if (op[i][0] != 's') {
                sf("%d", &num[i]);
                if (op[i][0] == 'a') b[m++] = num[i];
            }
        }
        sort(b, b + m);
        m = unique(b, b + m) - b;
        build();
        REP(i, n) {
            if (op[i][0] == 's') {
                pf("%I64d\n", sum[1][2]);
            }
            else if (op[i][0] == 'a') {
                int idx = lower_bound(b, b+m, num[i]) - b + 1;
                modify(idx, num[i], 1);
            }
            else {
                int idx = lower_bound(b, b+m, num[i]) - b + 1;
                modify(idx, num[i], -1);
            }
        }
    }
    return 0;
}

