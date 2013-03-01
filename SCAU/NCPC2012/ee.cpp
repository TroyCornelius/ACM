#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = acos(-1.0);
const double eps = 1e-12;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
const int M = 44444;
const int N = 222;
int n, m;
double D;
double ang[210][210][210];
int g[210][210];
int eh[N], tot;
bool hash[210][210];
double dis[210][210];
struct Point {
    double x, y, len;
}p[210], vec[N][N];
struct Edge {
    int u, v, next;
}et[M];
void init() {
    tot = 0;
    memset(eh, -1, sizeof(eh));
}
void addedge(int u, int v) {
    Edge e = {u, v, eh[u]};
    et[tot] = e;
    eh[u] = tot++;
}
inline double calcLen(int i, int j) {
    double dist = sqrt((vec[i][j].x * vec[i][j].x) + (vec[i][j].y * vec[i][j].y));
    return dist;
}
inline double calc(int i, int j, int k) {
    double tmp = (vec[i][j].x) * (vec[j][k].x) + (vec[i][j].y) * (vec[j][k].y);
    tmp /= vec[i][j].len * vec[j][k].len;
    return acos(tmp) / pi * 180;
}
void calc_ang() {
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                for (int k = 1; k <= n; k++) {
                    if (i != k && j != k) {
                        if (g[i][j] == -1 || g[j][k] == -1) continue;
                        ang[i][j][k] = calc(i, j, k);
                    }
                }
            }
        }
    }
}

inline bool chk(double a, double b) {
    return a < b || (fabs(a-b) < eps);
}
bool spfa(double lim, int s, int t) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = 1e100;
    queue<pii> que;
    memset(hash, false, sizeof(hash));
    for(int i = eh[s]; i != -1; i = et[i].next) {
        int v = et[i].v;
        dis[s][v] = vec[s][v].len;
        hash[s][v] = true;
        que.push(mp(s, v));
    }
    while (!que.empty()) {
        pii now = que.front();
        que.pop();
        int u = now.se;
        hash[now.fi][now.se] = false;
        for(int i = eh[u]; i != -1; i = et[i].next) {
            int v = et[i].v;
            //if(chk(calc(now.fi, u, v), lim)) {
            if (chk(ang[now.fi][u][v], lim)) {
                if (dis[now.fi][u] + vec[u][v].len + eps < dis[u][v]) {
                    dis[u][v] = dis[now.fi][u] + vec[u][v].len;
                    if (v == t && chk(dis[u][v], D)) return true;
                    if (!hash[u][v] && dis[u][v] + eps < D) {
                        hash[u][v] = true;
                        que.push(mp(u, v));
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(chk(dis[i][t], D)) return true;
    }
    return false;
}
inline double double_fix(double x) {
    if (x < eps) x = 0.0;
    return x;
}
int main() {
    freopen("ecodriving.in", "r", stdin);
    while (~scanf("%d%d%lf", &n, &m, &D)) {
        for (int i = 1; i <= n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
        memset(g, -1, sizeof(g));
        init();
        for(int i = 0, u, v; i < m; i++) {
            scanf("%d%d", &u, &v);
            g[u][v] = 1;
            addedge(u, v);
            vec[u][v].x = p[v].x - p[u].x;
            vec[u][v].y = p[v].y - p[u].y;
            vec[u][v].len = calcLen(u, v);
        }
        calc_ang();
        double ans = -1e30;
        double l = 0.0 - eps, r = 180 + eps;
        for(int i = 0; i < 25; i++) {
            double mid = (l + r) / 2.0;
            if(spfa(mid, 1, n)) ans = mid, r = mid;
            else l = mid;
        }
        if (ans < 0) puts("Impossible");
        else printf("%.3f\n", double_fix(ans));
    }
    return 0;
}

