#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
#include "vector"
#include "queue"
#include "cmath"
#include "string"
#include "cctype"
#include "map"
#include "iomanip"
using namespace std;
#define pb push_back
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long
#define maxn 100050
int group[maxn];
int n;
int cnt[10];

void solve() {
    int ans = 0;
    ans += cnt[4], cnt[4] = 0;
    if(cnt[3] > 0) {
        if(cnt[3] >= cnt[1]) ans += cnt[3], cnt[1] = cnt[3] = 0;
        else ans += cnt[3], cnt[1] -= cnt[3], cnt[3] = 0;
    }
    if(cnt[2] > 0) {
        if(cnt[2] & 1) ans += cnt[2] / 2, cnt[2] = 1;
        else ans += cnt[2] / 2, cnt[2] = 0;
        if(cnt[2] > 0) {
            if(cnt[1] <= 2) ans++, cnt[1] = 0;
            else ans++, cnt[1] -= 2;
        }
    }
    if(cnt[1] > 0) ans += (cnt[1] + 3) / 4, cnt[1] = 0;
    cout << ans << endl;
}

int main() {
    int s;
    while(cin >> n) {
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++) {
            cin >> s;
            cnt[s]++;
        }
        solve();
    }
    return 0;
}
