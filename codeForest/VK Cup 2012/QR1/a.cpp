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
int score[55];
int n, k;
int main() {
    while(cin >> n >> k) {
        for(int i = 1; i <= n; i++) cin >> score[i];
        int tmp = score[k], ans = 0;
        if(tmp == 0) tmp++;
        for(int i = 1; i <= n && score[i] >= tmp; i++)
            ans++;
        cout << ans << endl;
    }
    return 0;
}
