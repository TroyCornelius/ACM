/*
 * Author:  Teletubbies
 * Created Time:  2012年10月24日 星期三 16时30分51秒
 * File Name: 
 */
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
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

const int maxm = 210*210;
struct Edge{
    int v, next;
}et[maxm];
int eh[210], tot;

int n, m;
double D;
struct Point {
    double x, y;
}p[210];

int g[210][210];
//vi edge[210];
double len[210][210];
//double ang[210][210][210];

void addedge(int u, int v) {
    Edge tmp = {v, eh[u]};
    et[tot] = tmp;
    eh[u] = tot++;
}
inline double calc_len(int i, int j) {
    return sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x) + (p[i].y-p[j].y)*(p[i].y-p[j].y));
}
void edge_init() {
    tot = 0;
    memset(eh, -1, sizeof(eh));
}
void init() {
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            //if (g[i][j] != -1 || g[j][i] != -1)
            len[i][j] = len[j][i] = calc_len(i, j);
}
inline double calc(int i, int j, int k) {
    double a = len[i][j], b = len[j][k], c = len[i][k];
    double o = acos((a*a + b*b - c*c) / (2.0*a*b));
    double ret = (o / pi * 180.0);
    return 180.0 - ret;
}
/*
void calc_ang() {
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                for (int k = 1; k <= n; k++)
                    if (i != k && j != k) {
                        if (g[i][j] == -1 || g[j][k] == -1) continue;
                        ang[i][j][k] = calc(i, j, k);
                    }
}
*/
bool hash[210][210];
double dis[210][210];
inline bool chk(double a, double b) {
    return a < b || (fabs(a-b) < eps);
}
bool spfa(double lim, int s, int t) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = 1e100;
    queue<pii> que;
    memset(hash, false, sizeof(hash));
    for (int i = eh[s]; i != -1; i = et[i].next) {
        //int v = edge[s][i];
        int v = et[i].v;
        dis[s][v] =  len[s][v];
        hash[s][v] = true;
        que.push(mp(s, v));
    }
    while (!que.empty()) {
        pii now = que.front();
        que.pop();
        int u = now.se;
        hash[now.fi][now.se] = false;
        //REP(i, edge[u].size()) {
        for (int i = eh[u]; i != -1; i = et[i].next) {
            //int v = edge[u][i];
            int v = et[i].v;
            if (chk(calc(now.fi, u, v), lim)) {
                if (dis[now.fi][u] + len[u][v] < dis[u][v]) {
                    dis[u][v] = dis[now.fi][u] + len[u][v];
                    if (v == t && chk(dis[u][v], D)) return true;
                    if (!hash[u][v]) {
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
    while (~sf("%d%d%lf", &n, &m, &D)) {
        for (int i = 1; i <= n; i++) sf("%lf%lf", &p[i].x, &p[i].y);
        //for (int i = 1; i <= n; i++) edge[i].clear();
        int u, v;
        memset(g, -1, sizeof(g));
        edge_init();
        REP(i, m) {
            sf("%d%d", &u, &v);
            g[u][v] = 1;
            //edge[u].pb(v);
            addedge(u, v);
        }
        init();
        //calc_ang();
        double lo = -1.0, hi = 181.0, mid;
        double ans = -5.0;
        REP(i, 30) {
            mid = (lo + hi) / 2.0;
            if (spfa(mid, 1, n)) {
                hi = mid;
                ans = mid;
            }
            else lo = mid;
        }
        //cout <<ans <<endl;
        if (chk(ans, -5)) puts("Impossible");
        else pf("%.3lf\n", double_fix(ans));
    }
    return 0;
}

