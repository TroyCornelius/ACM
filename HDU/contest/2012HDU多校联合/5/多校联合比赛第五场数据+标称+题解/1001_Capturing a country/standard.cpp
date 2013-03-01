#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
//#include <ctime>
using namespace std;
typedef long long ll;
const int N = 111;
const int INF = 0x3f3f3f3f;
int ar[2][N];
int n;
vector<int> adj[N];
int dp[N][3][3];
bool vis[N];

int dfs(int cur, int a, int b, int fa) {
    //cout << cur << endl;
    int &res = dp[cur][a][b];
    if (res != -1) return res;
    if (adj[cur].size() == 1 && adj[cur][0] == fa) {
        if (b == 1) res = ar[a][cur];
        else res = ar[a][cur] / 2;
    } else {
        for (int i = 0; i < adj[cur].size(); ++i) if (adj[cur][i] != fa) {
                dfs(adj[cur][i], 0, 0, cur);
                dfs(adj[cur][i], 0, 1, cur);
                dfs(adj[cur][i], 1, 0, cur);
                dfs(adj[cur][i], 1, 1, cur);
            }
        if (b == 1) {
            int sum = 0;
            int v, temp;
            int minv = INF;
            for (int i = 0; i < adj[cur].size(); ++i) {
                v = adj[cur][i];
                if (v != fa) {
                    temp = min(dp[v][a][0], dp[v][1 - a][1]);
                    sum += temp;
                    minv = min(minv, dp[v][a][1] - temp);
                }
            }
            // if (cur == 1) cout << sum << " " << minv << endl;
            res = min(ar[a][cur] + sum, ar[a][cur] / 2 + sum + minv);
        } else {
            res = ar[a][cur] / 2;
            int v;
            for (int i = 0; i < adj[cur].size(); ++i) {
                v = adj[cur][i];
                if (v != fa) {
                    res += min(dp[v][a][0], dp[v][1 - a][1]);
                }
            }
        }
    }
    return res;
}

int Ans() {
    memset(dp, -1, sizeof (dp));
    int ans1 = dfs(1, 0, 1, -1);
    int ans2 = dfs(1, 1, 1, -1);
    //cout << ans1 << " " << ans2 << endl;
    return min(ans1, ans2);
}

int main() {
 //   freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    while (cin >> n) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &ar[0][i]);
        }
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &ar[1][j]);
        }
        for (int i = 1; i <= n; ++i) adj[i].clear();
        int a, b;
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        printf("%d\n", Ans());
    }
}
