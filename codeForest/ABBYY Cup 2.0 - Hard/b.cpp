/*
 * Author:  Troy
 * Created Time:  2012/4/28 22:08:14
 * File maxname: b.cpp
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
#define maxn 200010
#define maxm 200010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;


int n, m, root;
int eh[maxn], tot, belong[maxn], bcc, dfn[maxn], low[maxn], Dindex;
int s[maxn], top;
int visit[maxn];
struct Edge {
	int v, next;
}et[maxm];
void init() {
	tot = 0;
	memset(eh, -1, sizeof(eh));
}
void addedge(int u, int v) {
	Edge e = {v, eh[u]};
	et[tot] = e;
	eh[u] = tot++;
}
void dfs(int u, int pre) {
	dfn[u] = low[u] = ++Dindex, visit[u] = 1;
	s[++top] = u;
	int tot = 0;
	for(int i = eh[u]; i != -1; i = et[i].next) {
		int v = et[i].v;
		if(visit[v] == 1 && v != pre) low[u] = min(low[u], dfn[v]);
		if(visit[v] == 0) {
			dfs(v, u);
			tot++, low[u] = min(low[u], low[v]);
            //if (u == 1) cout <<low[v] <<" "<<dfn[u] <<" "<<v <<endl;
			//if((u == root && tot > 1) || (u != root) && (low[v] >= dfn[u])) // u is a cutpoint;割点
			if(low[v] > dfn[u]) {//桥
			//	(u, v) is a bridge.
                //cout <<u <<" --- "<<v <<endl;
				bcc++;	//[0, bcc]
				while(1) {//缩点,也可以直接利用low[]来缩点,low属于[1, n]
					belong[s[top]] = bcc;
                    //cout <<s[top] <<" "<<bcc <<endl;
					if(s[top--] == v) break;
				}
			}
		}
	}
	visit[u] = 2;
}
void tarjan() {
	top = bcc = Dindex = 0;
    bcc++;
	memset(visit, 0, sizeof(visit));
	for(root = 1; root <= n; root++) 
		if(!visit[root]) dfs(root, -1);
    FOR(i, 1, n+1)
        if (belong[i] == 0) belong[i] = 1;
    //belong[1] = 1;
}

vi g[maxn];
pii e[maxm];
void rebuild()
{
   /* FOR(i, 1, n+1)
    {
        g[i].pb(0);
        g[0].pb(i);
    }*/
    g[0].pb(1);
    g[1].pb(0);
    
    REP(i, m)
    {
        int u = e[i].fi, v = e[i].se;
        if (belong[u] != belong[v])
        {
            g[belong[u]].pb(belong[v]);
            g[belong[v]].pb(belong[u]);
        }
    }    
}

bool vis[maxn];
//int n;//点数
int R[maxn];//第一次出现i点下标
int p[maxn*2];//记录路径点编号
int dis[maxn];//与根的距离
int dep[2*maxn];//深度
int dp[20][2*maxn];//从j开始长度为2^i路径的最近公共祖先下标，这里这里！！！第二维要2倍大小！！
int num;
//int fa[maxn];
/*
int find(int x){
    if(fa[x] != x)
    fa[x] = find(fa[x]);
    return fa[x];
}
void uni(int u,int v){
    int a = find(u);
    int b = find(v);
    if(a == b)return ;
    fa[a] = b;
}*/
void dfs2(int u,int depth){
    vis[u] = 1;
    p[++num] = u;
    dep[num] = depth;
    //for(int i=head[u];i!=-1;i=e[i].next){
    REP(i, g[u].size()){
        int v = g[u][i];
        if(!vis[v]){
            dis[v] = dis[u]+ (u == 0 ? 0 : 1);
            dfs2(v,depth+1);
            p[++num] = u;
            dep[num] = depth;
        }
    }
}
void init_rmq(){
    int i,j;
    for(i=1;i<=num;i++){
        if(R[p[i]] == -1){
            R[p[i]] = i;
        }
    }
    for(i=1;i<=num;i++){
        dp[0][i] = i;
    }
    int t = (int)(log(num*1.0)/log(2.0));
    for(i=1;i<=t;i++){
        for(j=1;j+(1<<(i-1))<=num;j++){
            int a = dp[i-1][j],b = dp[i-1][j+(1<<(i-1))];
            if(dep[a]<=dep[b]){
                dp[i][j] = a;
            } else dp[i][j] = b;
        }
    }
}
int rmq(int u,int v){//返回最近公共祖先的编号
    if(R[u]>=R[v])swap(u,v);
    int s = R[u],t = R[v];
    int k = (int)(log((t-s+1)*1.0)/log(2.0));
    int a = dp[k][s],b = dp[k][t-(1<<k)+1];
    if(dep[a]<=dep[b])return p[a];
    else return p[b];
}

int main() 
{
    init();
    int u, v;
    sf("%d%d", &n, &m);
    REP(i, m)
    {
        sf("%d%d", &u, &v);
        addedge(u, v);
        addedge(v, u);
        e[i] = mp(u, v);
    }
    
    tarjan();
    //cout <<endl ;
    //REP(i, n) cout <<belong[i+1] <<" "<<i+1 <<endl;
    
    
    rebuild();
    memset(R,-1,sizeof(R));
    memset(vis, false, sizeof(vis));
    num = 0;
    dis[0] = dep[0] = 0;
    dfs2(0, 0);
    //REP(i, 5) cout <<dis[i] <<endl;
    init_rmq();
    int Q;
    sf("%d", &Q);
    while (Q--)
    {
        sf("%d%d", &u, &v);
        int fat = rmq(belong[u], belong[v]);
        //cout <<fat <<" "<< dis[belong[u]] << " " <<dis[belong[v]] <<" "<< dis[fat] <<" " <<endl;
        pf("%d\n", dis[belong[u]] + dis[belong[v]] - 2*dis[fat]);
    }
    return 0;
}

