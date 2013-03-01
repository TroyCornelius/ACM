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
const int inf = 1 << 29;
const double dinf = 1e30;
const ll linf = 1LL << 55;
#define maxn 110
int val[maxn];
int dp[maxn][550];
int f[550];
int pre[maxn];
int ti[maxn], gold[maxn];
int n, t, tt;
bool inpath[maxn];
bool visit[maxn];
int eh[maxn], tot;
int q[maxn], qn;
struct Edge {
    int u, v, w, next;
}et[maxn*maxn];

void init() {
    tot = 0;
    memset(eh, -1, sizeof(eh));
}

void addedge(int u, int v, int w) {
    Edge e = {u, v, w, eh[u]};
    et[tot] = e;
    eh[u] = tot++;
}

void bfs(int s) {
    memset(pre, -1, sizeof(pre));
    memset(visit, false, sizeof(visit));
    queue<int> que;
    que.push(s);
    gold[s] = val[s];
    ti[s] = 0;
    visit[s] = 1;
    while(!que.empty()) {
        int u = que.front();
        que.pop();
        for(int i = eh[u]; i != -1; i = et[i].next) {
            int v = et[i].v, w = et[i].w;
            if(visit[v]) continue;
            ti[v] = ti[u] + w;
            gold[v] = gold[u] + val[v];
            pre[v] = u;
            visit[v] = 1;
            que.push(v);
        }
    }
}

void dfs(int u) {
    inpath[u] = true;
    for(int i = 0; i <= tt; i++) dp[u][i] = val[u];
    for(int i = eh[u]; i != -1; i = et[i].next) {
        int v = et[i].v, w = et[i].w;
        if(inpath[v]) continue;
        dfs(v);
        for(int j = tt; j >= 0; j--)
            for(int k = 0; k <= j; k++)
                if(j - k - 2 * w >= 0) dp[u][j] = max(dp[u][j], dp[u][j-k-2*w] + dp[v][k]);
    }
}

int main() {
    while(~scanf("%d%d", &n, &t)) {
        init();
        for(int i = 1; i < n; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            addedge(a, b, c);
            addedge(b, a, c);
        }
        for(int i = 1; i <= n; i++) scanf("%d", &val[i]);
        bfs(1);       
        memset(inpath, false, sizeof(inpath));
        int x = n;
        //cout << gold[n] << " " << ti[n] << endl;
        qn = 0;
        while(x != -1) {
            inpath[x] = true;
            val[x] = 0;
            q[qn++] = x;
            x = pre[x];
        }
        if(ti[n] > t) puts("Human beings die in pursuit of wealth, and birds die in pursuit of food!");
        else {
            tt = t - ti[n];
          //  cout << tt << endl;
            for(int i = 0; i < qn; i++) dfs(q[i]);
            memset(f, 0, sizeof(f));
            for(int kk = 0; kk < qn; kk++) {
                int u = q[kk];
                for(int i = tt; i >= 0; i--)
                    for(int j = 0; j <= tt; j++)
                        if(i - j >= 0) f[i] = max(f[i], f[i-j] + dp[u][j]);
            }
            /*
            for(int i = 0; i <= tt; i++) {
                cout << f[i] << " ";
            }
            cout << endl;
            for(int i = 2; i <= 4; i++) {
                cout << val[i] << endl;
                for(int j = 0; j <= tt; j++)
                    cout << dp[i][j] << " ";
                cout << endl;
            }
            */
            int res = 0;
            for(int i = 0; i <= tt; i++) {
                res = max(res, f[i]);
            }
            printf("%d\n", gold[n] + res);
        }
    }
    return 0;
}

