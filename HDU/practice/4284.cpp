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
const int inf = 1 << 28;
const double dinf = 1e30;
const ll linf = 1LL << 55;

int dp[1<<17][20];
int hash[110];
int c[110], d[110];
int n, m, money, h;
int maz[110][110], g[110][110];
//vector<int> vec;
int dist[110];
bool vis[110];
int b[110];

void init(){
    b[0]=1;
    for (int i=1; i<=20; i++) b[i]=b[i-1]<<1;
}

void dij(int s) {
    for(int i = 0; i < n; i++) dist[i] = inf, vis[i] = 0;
    dist[s] = 0;
    //vis[s] = 1;
    while(1) {
        int u = -1;
        for(int i = 0; i < n; i++) {
            if(!vis[i] && (u == -1 || dist[u] > dist[i])) u = i;
        }
        if(u == -1) break;
        vis[u] = 1;
        for(int i = 0; i < n; i++) {
            if(!vis[i] && dist[i] > dist[u] + maz[u][i]) {
                dist[i] = dist[u] + maz[u][i];
            }
        }
    }
    for(int i = 0; i < n; i++) {
        g[s][i] = dist[i];
    }
    return;
}
/*
void spfa(int s) {
    memset(vis, false, sizeof(vis));
    queue<int> que;
    for (int i = 0; i < n; ++i) dist[i] = inf;
    dist[s] = 0; 
    que.push(s);
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        vis[now] = true;
        for (int i = 0; i < n; ++i)
            if (i != now && maz[now][i] != inf) {
                int w = maz[now][i];
                if (dist[now] + w < dist[i]) {
                    dist[i] = dist[now] + w;
                    if (!vis[i]) {
                        vis[i] = true;
                        que.push(i);
                    }
                }
            }
    }
    for (int i = 0; i < n; ++i) g[s][i] = dist[i];
    return;
}
*/
inline int getint() {
    char c = getchar();
    int t = 0;
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9') {
        t = t * 10 + c - '0';
        c = getchar();
    }
    return t;
}

int main() {
    int T;
    scanf("%d", &T);
    init();
    while(T--) {
        scanf("%d%d%d", &n, &m, &money);
        memset(hash, 0, sizeof(hash));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                maz[i][j] = inf;
            maz[i][i] = 0;
        }
        for(int i = 0; i < m; i++) {
            int a, b, c;
            a = getint();
            b = getint();
            c = getint();
            a--, b--;
            maz[a][b] = maz[b][a] = min(maz[a][b], c);
        }
        h = getint();
        int q[20], qn = 0;
        bool flag = true;
        for(int i = 0; i < h; i++) {
            int x;
            x = getint();
            x--;
            q[qn++] = x;
            if(x == 0) flag = false;
            c[x] = getint();
            d[x] = getint();
            hash[x] = b[i];
        }
        if(flag) q[qn++] = 0;
        sort(q, q + qn);
        for(int i = 0; i < qn; i++) dij(q[i]);
        memset(dp, -1, sizeof(dp));
        dp[0][0] = money;
        for(int m = 0; m < b[h]; ++m) {
            for(int i = 0; i < qn; ++i) {
                if(dp[m][i] < 0) continue;
                for(int j = 0; j < qn; ++j) {
                    if(dp[m][i] < g[q[i]][q[j]]) continue;
                    int res = dp[m][i] - g[q[i]][q[j]];
                    dp[m][j] = max(dp[m][j], res);
                    if(hash[q[j]] && !(m & hash[q[j]])) {
                        if(res >= d[q[j]]) {
                            res += c[q[j]] - d[q[j]];
                            dp[m|hash[q[j]]][j] = max(dp[m|hash[q[j]]][j], res);
                        }
                    }
                }
            }
        }
        if(dp[b[h]-1][0] >= 0) puts("YES");
        else puts("NO");
    }
    return 0;
}

