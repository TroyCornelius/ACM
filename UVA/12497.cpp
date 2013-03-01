#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
#include "vector"
#include "queue"
#include "stack"
#include "cmath"
#include "string"
#include "cctype"
#include "map"
#include "iomanip"
#include "set"
#include "utility"
using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long
#define ull unsigned long long
const int inf = 1 << 29;
const double dinf = 1e30;
const ll linf = 1LL << 55;
const int N = 15;
bool maz[N][N];
bool dp[N][1<<N];
bool route[N][1<<N];
int n, m;
int cnt[1<<N];
ll solve() {
    ll ans = 0;
    memset(route, false, sizeof(route));
    for(int i = 0; i < n; i++) {
        memset(dp, false, sizeof(dp));
        for(int j = 0; j < n; j++) {
            if(maz[i][j]) {
                dp[j][1<<j] = true;
            }
        }
        for(int mask = 1; mask < (1 << n); mask++) {
            for(int j = 0; j < n; j++) {
                if(!dp[j][mask]) continue;
                for(int k = 0; k < n; k++) {
                    if(!maz[j][k] || (mask >> k & 1)) continue;
                    if(k == i) { 
                        if(cnt[mask] >= 2) route[i][mask] = true;
                    } else {
                        dp[k][mask | (1 << k)] = true;
                    }
                }
            }
        }
        for(int mask = 1; mask < (1 << n); mask++) {
            if(!route[i][mask]) continue;
            int t = ~mask & ((1 << n) - 1);
            for(int subMask = t; subMask; subMask = (subMask - 1) & t) {
                if(route[i][subMask]) {
                    //cout << i << " " << mask << " " << subMask << endl;
                    ans++;
                }
            }
        }
    }
    return ans >> 1;
}

int main() {
    cnt[0] = 0;
    for(int mask = 1; mask < (1 << N); mask++) {
        int i = 0;
        while(~mask >> i & 1) i++;
        cnt[mask] = cnt[mask ^ (1 << i)] + 1;
    }
    int T, Case = 1;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        memset(maz, false, sizeof(maz));
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            maz[a][b] = maz[b][a] = true;
        }
        ll ans = solve();
        /*
        for(int i = 0; i < n; i++) {
            cout << "********" << endl;
            cout << i << endl;
            for(int mask = 1; mask < (1 << n); mask++) {
                if(route[i][mask] && cnt[mask] > 1) cout << mask << endl;
            }
        }
        */
        printf("Case %d: ", Case++);
        cout << ans << endl;
    }
    return 0;
}
