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
int a[10];
int ans, idx;

void calc(int x) {
    if(idx) {
        if(a[x] <= a[x+3]) ans += 2 * a[x];
        else ans += 2 * a[x+3] + 1, idx = 0;
    } else {
        if(a[x] >= a[x+3]) ans += 2 * a[x+3];
        else ans += 2 * a[x] + 1, idx = 1;
    }
}


int main() {
    freopen("g.in", "r", stdin);
    freopen("yg.out", "w", stdout);
    int T, Case = 1;
    cin >> T;
    while(T--) {
        ans = 0, idx = 1;
        for(int i = 1; i <= 6; i++) cin >> a[i];
        calc(1), calc(2), calc(3);
        printf("Case %d: ", Case++);
        cout << ans << endl;
    }

    return 0;
}
