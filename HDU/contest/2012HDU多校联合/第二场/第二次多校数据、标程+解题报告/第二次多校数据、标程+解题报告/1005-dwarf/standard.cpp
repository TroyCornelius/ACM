#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

const int MAXN = 2010;
const int INF = 1000100100;
struct SS {int a, b;} s[MAXN];
int n, H;
int dp[MAXN][MAXN];
int sumA[MAXN];

int cmp(SS a, SS b) {
    return a.a + a.b > b.a + b.b;
}

int main() {
 //   freopen("data.in","r",stdin);
 //   freopen("data.out","w",stdout);
    while (scanf("%d",&n) != EOF) {
        assert(n > 0 && n <= 2000);
        for (int i = 0 ; i < n ; i++) {
            scanf("%d%d", &s[i].a, &s[i].b);
            assert(s[i].a <= 100000 && s[i].b <= 100000);
        }
        scanf("%d", &H);
        assert(H <= 100000);
        sort(s, s+n, cmp);
        for (int i = 0 ; i < n ; i++)
            if (i == 0) sumA[i] = s[i].a;
            else sumA[i] = sumA[i-1] + s[i].a;
        for (int i = 0 ; i <= n ; i++)
            for (int j = 0 ; j <= n ; j++)
                dp[i][j] = INF;

        dp[0][0] = 0;
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 0 ; j <= i ; j++) {
                dp[i][j] = dp[i-1][j] - s[i-1].a;
                int tmp;
                if (j) tmp = max(dp[i-1][j-1], H - sumA[i-1] - s[i-1].b);
                else tmp = H - sumA[i-1] - s[i-1].b;
                if (tmp < dp[i][j]) dp[i][j] = tmp;
                if (dp[i][j] < 0) dp[i][j] = 0;
            }
        }
        int j;
        for (j = n ; j >= 0 ; j--)
            if (dp[n][j] <= 0) break;
        printf("%d\n", j);
    }
    return 0;
}
