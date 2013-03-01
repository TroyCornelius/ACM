#include<stdio.h>
#include<string.h>
#include<map>
#include<vector>
#include<set>
#include<math.h>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
const int maxnode = 40000 + 5;
const int maxedge = 200000+ 5;
const int oo = 1000000000;

int node, src, dest, nedge;
int head[maxnode], point[maxedge], next[maxedge], flow[maxedge], capa[maxedge];
int dist[maxnode], Q[maxnode], work[maxnode];

void init(int _node, int _src, int _dest) {
    node = _node;
    src = _src;
    dest = _dest;
    for (int i = 0; i < node; i++) head[i] = -1;
    nedge = 0;
}

void addedge(int u, int v, int c1, int c2) {
    point[nedge] = v, capa[nedge] = c1, flow[nedge] = 0, next[nedge] = head[u], head[u] = (nedge++);
    point[nedge] = u, capa[nedge] = c2, flow[nedge] = 0, next[nedge] = head[v], head[v] = (nedge++);
}

bool dinic_bfs() {
    memset(dist, 255, sizeof (dist));
    dist[src] = 0;
    int sizeQ = 0;
    Q[sizeQ++] = src;
    for (int cl = 0; cl < sizeQ; cl++)
        for (int k = Q[cl], i = head[k]; i >= 0; i = next[i])
            if (flow[i] < capa[i] && dist[point[i]] < 0) {
                dist[point[i]] = dist[k] + 1;
                Q[sizeQ++] = point[i];
            }
    return dist[dest] >= 0;
}

int dinic_dfs(int x, int exp) {
    if (x == dest) return exp;
    for (int &i = work[x]; i >= 0; i = next[i]) {
        int v = point[i], tmp;
        if (flow[i] < capa[i] && dist[v] == dist[x] + 1 && (tmp = dinic_dfs(v, min(exp, capa[i] - flow[i]))) > 0) {
            flow[i] += tmp;
            flow[i^1] -= tmp;
            return tmp;
        }
    }
    return 0;
}

int dinic_flow() {
    int result = 0;
    while (dinic_bfs()) {
        for (int i = 0; i < node; i++) work[i] = head[i];
        while (1) {
            int delta = dinic_dfs(src, oo);
            if (delta == 0) break;
            result += delta;
        }
    }
    return result;
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int s,t;
        scanf("%d%d",&s,&t);
        s--;t--;
        init(n+n,s,t+n);
        for(int i=0;i<n;i++){
            int c;
            scanf("%d",&c);
            addedge(i,i+n,c,0);
        }
        for(int i=0;i<m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            x--;y--;
            addedge(x+n,y,oo,0);
            addedge(y+n,x,oo,0);
        }
        int ans = dinic_flow();
        printf("%d\n",ans);
    }
    return 0;
}