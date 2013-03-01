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
const int maxedge = 400000+ 5;
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
char str[1000];
int main(){
    int n,a,b;
    while(scanf("%d%d%d",&n,&a,&b)!=EOF){
        int s=n+n+a+b,t=n+n+a+b+1;
        init(n+n+a+b+2,s,t);
        for(int i=0;i<a;i++){
            int x;
            scanf("%d",&x);
            addedge(s,i,x,0);
        }
        for(int i=a;i<a+b;i++){
            int x;
            scanf("%d",&x);
            addedge(i,t,x,0);
        }
        for(int i=0;i<n;i++){
            scanf("%s",str);
            for(int j=0;str[j];j++)
                if(str[j]=='Y')addedge(j,a+b+i,1,0);
        }
        for(int i=0;i<n;i++){
            scanf("%s",str);
            for(int j=0;str[j];j++)
                if(str[j]=='Y')addedge(a+b+i+n,a+j,1,0);
        }
        for(int i=0;i<n;i++)addedge(a+b+i,a+b+i+n,1,0);
        int ans=dinic_flow();
        printf("%d\n",ans);
    }
    return 0;
}