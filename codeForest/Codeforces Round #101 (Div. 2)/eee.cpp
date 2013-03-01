#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
#include "vector"
#include "queue"

using namespace std;
#define pb push_back
#define maxn 1005
#define maxm 1000050
#define fi first
#define se second
#define mp make_pair
typedef pair<int,int> pii;
vector<pair<pii, int> > sb, mb;
int n, m, root;
int eh[maxn], tot, belong[maxn], bcc, dfn[maxn], low[maxn], Dindex;
int s[maxn], top;
int visit[maxn];
bool hash[maxn][maxn];
int cnt, scnt, mcnt;
struct Edge {
	int v, t, next;
}et[maxm];
void init() {
	tot = 0;
	memset(eh, -1, sizeof(eh));
}
void addedge(int u, int v, int t) {
	Edge e = {v, t, eh[u]};
	et[tot] = e;
	eh[u] = tot++;
}
void dfs(int u, int pre) {
	dfn[u] = low[u] = ++Dindex, visit[u] = 1;
	s[++top] = u;
	int tot = 0;
	for(int i = eh[u]; i != -1; i = et[i].next) {
		int v = et[i].v, t = et[i].t;
		if(visit[v] == 1 && v != pre) low[u] = min(low[u], dfn[v]);
		if(visit[v] == 0) {
			dfs(v, u);
			tot++, low[u] = min(low[u], low[v]);
			if(low[v] > dfn[u]) {//ге
                if(!hash[u][v]) {
                    hash[u][v] = hash[v][u] = true;
                    cnt++;
                    if(t == 2) mcnt++;
                    else scnt++;
                }
			}
		}
	}
	visit[u] = 2;
}
void tarjan() {
	top = bcc = Dindex = 0;
    cnt = 0;
	memset(visit, 0, sizeof(visit));
    memset(hash, false, sizeof(hash));
	for(root = 1; root <= n; root++) 
		if(!visit[root]) dfs(root, -1);
}

int main() {
    int u, v, t;
    char s[5];
    while(~scanf("%d%d", &n, &m)) {
        init();
        for(int i = 0; i < m; i++) {
            scanf("%d%d%s", &u, &v, s);
            if (v > u) swap(u, v);
            if(s[0] == 'S') 
            {
                    t = 1;
                    sb.pb(mp(mp(u, v), t));
            }
            else 
            {
                 t = 2;
                 mb.pb(mp(mp(u, v), t));
            }
            addedge(u, v, t);
            addedge(v, u, t);
        }
        tarjan();
        cout << cnt << endl;
    }
    return 0;
}

