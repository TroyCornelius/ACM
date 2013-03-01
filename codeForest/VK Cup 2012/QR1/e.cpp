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
#define maxn 5000
int n, k;
int t[maxn], d[maxn];
int end[maxn], maxtime[maxn];

int solve() {
    memset(maxtime, 0, sizeof(maxtime));
    if(n == k) return 86400; 
    int cnt = n - k;
    for(int i = 0; i < cnt; i++) {
        for(int j = n - 1; j >= i; j--) {
            if(j == 0) {
                maxtime[j] = t[j] - 1;
                end[j] = t[j] + d[j];
            } else if(t[j] > end[j-1]) {
                maxtime[j] = max(maxtime[j-1], t[j] - end[j-1]);
                end[j] = t[j] + d[j];
            } else {
                maxtime[j] = maxtime[j-1];
                end[j] = end[j-1] + d[j];
            }
        }
        for(int j = i; j < n - 1; j++)
            end[j+1] = min(end[j], end[j+1]);
    }
    int res = 0;
    for(int j = cnt - 1; j < n; j++) {
        res = max(res, max(maxtime[j], 86400 - end[j] - 1));
    }
    return res;
}

int main() {
    while(cin >> n >> k) {
        for(int i = 0; i < n; i++) {
            cin >> t[i] >> d[i];
            end[i] = 1;
        }
        cout << solve() << endl;
    }
    return 0;
}
