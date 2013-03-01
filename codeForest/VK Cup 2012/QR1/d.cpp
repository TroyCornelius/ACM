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
#define maxn 20050
int t[maxn], n;
int ans;

void solve() {
    for(int i = 3; i < n; i++) {
        if(n % i == 0) {
            int tmp = n / i;
            for(int j = 0; j < tmp; j++) {
                int res = 0;
                for(int k = j; k < n; k += tmp) {
                    res += t[k];
                }
                ans = max(ans, res);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    while(cin >> n) {
        ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> t[i];
            ans += t[i];
        }
        solve();
    }
    return 0;
}
