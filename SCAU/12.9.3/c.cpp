/*
 * Author:  Troy
 * Created Time:  2012/9/3 21:45:56
 * File Name: c.cpp
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
#define maxn 100100
#define Maxn 100100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n;
int dis[Maxn];
//int dep[Maxn+Maxn], E[Maxn+Maxn], R[Maxn+Maxn];
vector<pii> g[Maxn];
bool vis[Maxn];
pii del_edge;
int cost;

int id;
/*
void dfs(int u, int depth, int fa) {
    //cout <<u <<" "<<depth <<endl;
    vis[u] = true;
    R[u] = id; E[id] = u; dep[id++] = depth;
    REP(i, g[u].size()) {
        int v = g[u][i].fi, w = g[u][i].se;
        if (v == fa) continue;
        if (v != fa) {
            if (vis[v]) {
                if (del_edge.fi == -1) {
                    del_edge = mp(u, v);
                    cost = w;
                }
            }
            else {
                dis[v] = dis[u] + w;
                dfs(v, depth+1, u);
                E[id] = u; dep[id++] = depth;
            }
        }
    }
    return;
}

int p[25], st[Maxn+Maxn][20];
void init_RMQ() {
    int i, j;
    for (p[0] = 1, i = 1; i < 20; ++i) p[i] = p[i-1] * 2;
    for (i = 0; i < id; i++) st[i][0] = i;
    int tt = int(log(double(n)/log(2.0))) + 1;
    for (j = 1; j < tt; ++j)
        for (i = 0; i < id; ++i) {
            if (i + p[j-1] - 1 < id) {
                st[i][j] = dep[st[i][j-1]] > dep[st[i+p[j-1]][j-1]] ? st[i+p[j-1]][j-1] : st[i][j-1];
            }
            else break;
        }
    //cout <<"fuck" <<endl;
}
int loc[Maxn];
int Query(int x, int y) {
    //int k = int(log(double(y-x+1))/log(2.0));
    int k = loc[y - x + 1];
    return dep[st[x][k]] > dep[st[y-p[k]+1][k]] ? st[y-p[k]+1][k] : st[x][k];
}
*/

int F[maxn*2], B[maxn*2], pos[maxn];//欧拉序列F，深度序列B，某个结点出现最开始位置pos
//查询某两个结点的LCA可以转化为查询B序列中pos[a],pos[b]之间的最小值，返回F序列中的值就是了
//ceil(log(maxn,2)) == 18
int rmq[maxn*2][20], rn;
int in[maxn];
struct Edge {
	int u, v, w, next;
}et[maxn*2];
int eh[maxn], tot;
inline void add(int u, int v, int w) {
	Edge e = {u, v, w, eh[u]};
	et[tot] = e;
	eh[u] = tot++;
}
inline void addedge(int u, int v, int w) {//树是无向的
	add(u, v, w), add(v, u, w);
}
void dfs(int u, int pre, int deep) {
    vis[u] = true;
	F[++rn] = u, B[rn] = deep, pos[u] = rn;
	for(int son = eh[u]; son != -1; son = et[son].next) {
		int v = et[son].v, w = et[son].w;
		if(v == pre) continue;
        if (vis[v]) {
            if (del_edge.fi == -1) {
            del_edge = mp(u, v);
            cost = w;
            }
            continue;
        }
        dis[v] = dis[u] + w;
		dfs(v, u, deep + 1);
		F[++rn] = u, B[rn] = deep;
	}
}
void Init_RMQ() {
	for(int i = 1; i <= rn; i++) rmq[i][0] = i;
	for(int j = 1; (1<<j) <= rn; j++) {
		for(int i = 1; i + (1<<j) - 1 <= rn; i++) {
			int a = rmq[i][j-1], b = rmq[i+(1<<(j-1))][j-1];
			if(B[a] < B[b]) rmq[i][j] = a;
			else rmq[i][j] = b;
		}
	}
}
int RMQ(int a, int b) {//查询[u,v]之间的最小值
	int k = int(log(1.0 + b - a) / log(2.0));
	int u = rmq[a][k], v = rmq[b-(1<<k)+1][k];
	if(B[u] < B[v]) return F[u];
	else return F[v];
}
int LCA(int a, int b) {//查询u,v结点的最近公共祖先
	a = pos[a], b = pos[b];
	if(a > b) return RMQ(b, a);
	else return RMQ(a, b);
}
void init() {
	tot = rn = 0;
	memset(eh, -1, sizeof(eh));
}
//*/


int main() {
    //freopen("cc.in", "r", stdin);
    //freopen("my.out", "w", stdout);
    int u, v, w;
    int m, x, y;
    //int tmp = 2, tt = 0;
    //for (int i = 2; i <= 100000; i++) {
        //if (i >= tmp) tmp *= 2, tt++;
        //loc[i] = tt;
    //}
    while (~sf("%d", &n), n) {
        //REP(i, n) g[i].clear();
        init();
        REP(i, n) {
            sf("%d%d%d", &u, &v, &w);
            //g[u].pb(mp(v, w));
            //g[v].pb(mp(u, w));
            u++;v++;
            addedge(u, v, w);
        }
        del_edge = mp(-1, -1);
        memset(vis, false, sizeof(vis));
        //id = 0;
        rn = 0;
        dis[0] = 0;
        dfs(1, 0, 0);
        //cout <<1 <<endl;
        Init_RMQ();
        sf("%d", &m);
        int s = del_edge.fi, t = del_edge.se;
        //cout <<s <<" "<<t <<" "<<cost <<"!!!" <<endl;
        //REP(i, n) cout <<dis[i] <<" ";
        //cout <<endl;
        while (m--) {
            sf("%d%d", &u, &v);
            u++;v++;
            x = u, y = v;
            //u = R[x], v = R[y];
            //if (u > v) swap(u, v);
            //int lca = E[Query(u, v)];
            int lca = LCA(x, y);
            int ans = dis[x] + dis[y] - 2 * dis[lca], tmp = 0;
            //ans = min(ans, min(dis[x] - dis[s] + dis[y] - dis[t] + cost, dis[x]-dis[t]+dis[y]-dis[t]+cost));
            //cout <<ans <<" : "<<lca <<" -- " <<endl;
            //u = R[x], v = R[s];
            //if (u > v) swap(u, v);
            //lca = E[Query(u, v)];
            lca = LCA(x, s);
            tmp = dis[x] + dis[s] - 2 * dis[lca] + cost; 
            //u = R[y], v = R[t];
            //if (u > v) swap(u, v);
            //lca = E[Query(u, v)];
            lca = LCA(y, t);
            tmp += dis[y] + dis[t] - 2 * dis[lca];
            
            ans = min(ans, tmp);
            
            tmp = 0;
            //u = R[x], v = R[t];
            //if (u > v) swap(u, v);
            //lca = E[Query(u, v)];
            lca = LCA(x, t);
            tmp = dis[x] + dis[t] - 2 * dis[lca] + cost; 
            //u = R[y], v = R[s];
            //if (u > v) swap(u, v);
            //lca = E[Query(u, v)];
            lca = LCA(y, s);
            tmp += dis[y] + dis[s] - 2 * dis[lca];
            ans = min(ans, tmp);
            
            pf("%d\n", ans);
        }
        
    }
    return 0;
}

