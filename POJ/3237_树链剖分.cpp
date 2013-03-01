/*
题意：给定一棵无向树T，每条边都有一个权值，现在有三种操作，
1、 QUERY a b: 查询结点 a 到结点 b 路径中边权最大值。
2、 CHANGE a w: 将第 a 条边的权值改变为 w
3、 NEGATE a b: 将结点 a 到结点 b 中所有边权取反。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 100001;
const int INF = 999999999;
typedef pair<int, int> pair_T;
struct Edge {
    int id, v;
    Edge *next;
}*adj[MAXN], memo[2 * MAXN];
int mSet, weight[MAXN];
 
void addEdge(int u, int v, int id) {
    Edge *ptr = &memo[mSet ++];
    ptr->id = id;
    ptr->v = v;
    ptr->next = adj[u];
    adj[u] = ptr;
}
 
int E[2 * MAXN]; //给树T做深度优先遍历，并记录每次到达的结点
int R[MAXN]; //R[i]表示E数组中第一个值为i的数组下标
int L[2 * MAXN]; //L[i]表示访问的结点E[i]的深度
int d[2 * MAXN][14]; //d[i][j]记录从i开始到i + 2 ^ j下标的L[]深度的最小值下标
int tot, visited[MAXN];
vector<pair_T> father[MAXN];
 
void DFS(int u, int pre, int deep) 
{
    if(!visited[u]) {
        visited[u] = 1;
        R[u] = tot;
    }
    E[tot] = u;
    L[tot ++] = deep;
    for(Edge *ptr = adj[u]; ptr; ptr = ptr -> next) {
        int  v = ptr -> v;
        if(v != pre) {
            father[v].push_back(make_pair(u, ptr -> id));
            DFS(v, u, deep + 1);
            E[tot] = u;
            L[tot ++] = deep;
        }
    }
}
 
void createTable() 
{ /* 根据深度来建立 */
    for(int j = 0; (1 << j) <= tot; j ++) {
        for(int i = 0; i + (1 << j) <= tot; i ++) {
            if(j == 0) d[i][j] = i;
            else {
                if(L[d[i][j - 1]] < L[d[i + (1 << (j - 1))][j - 1]])
                    d[i][j] = d[i][j - 1];
                else
                    d[i][j] = d[i + (1 << (j - 1))][j - 1];
            }
        }
    }
}
 
int RMQ(int v1, int v2) 
{ /* 期间所有节点中层次最大的即是 */
    int k = 0;
    while((1 << (k + 1)) < (v2 - v1 + 1))
        k ++;
    if(L[d[v1][k]] < L[d[v2 - (1 << k) + 1][k]])
        return E[d[v1][k]];
    else
        return E[d[v2 - (1 << k) + 1][k]];
}
 
int LCA(int v1, int v2) 
{
    if(R[v1] < R[v2])
        return RMQ(R[v1], R[v2]);
    else
        return RMQ(R[v2], R[v1]);
}
 
void query(int u, int v) 
{ /* 各自向父节点回溯 */
    int t, id;
    int maximum = -INF;
    int fv = LCA(u, v);
    while(u != fv) {
        t = father[u][0].first;
        id = father[u][0].second;
        if(maximum < weight[id]) 
            maximum = weight[id];
        u = t;
    }
    while(v != fv) {
        t = father[v][0].first;
        id = father[v][0].second;
        if(maximum < weight[id]) 
            maximum = weight[id];
        v = t;
    }
    printf("%d\n", maximum);
}
 
void negate(int u, int v) 
{
    int id, fv = LCA(u, v);
    while(u != fv) {
        id = father[u][0].second;
        weight[id] *= -1;
        u = father[u][0].first;
    }
    while(v != fv) {
        id = father[v][0].second;
        weight[id] *= -1;
        v = father[v][0].first;
    }
}
 
int main() 
{
    int n, casn;
    scanf("%d", &casn);
    while(casn --) {
        scanf("%d", &n);
        int i, u, v, w;
        for(i = 0; i <= n; i ++) {
            adj[i] = NULL;
            father[i].clear();
        }
        mSet = 0;
        for(i = 1; i < n; i ++) {
            scanf("%d%d%d", &u, &v, &weight[i]);
            addEdge(u, v, i);
            addEdge(v, u, i);
        }
        weight[0] = 0;
        int root = 1; //取结点1为根
        father[1].push_back(make_pair(1, 0));
        memset(visited, 0, sizeof(visited));
        tot = 0;
        DFS(root, root, 0);
        createTable();
        char str[100];
        while(scanf("%s", str) != EOF) {
            if(strcmp(str, "QUERY") == 0) {
                scanf("%d%d", &u, &v);
                query(u, v);
            }else if(strcmp(str, "CHANGE") == 0) {
                scanf("%d%d", &v, &w);
                weight[v] = w;
            }else if(strcmp(str, "NEGATE") == 0) {
                scanf("%d%d", &u, &v);
                negate(u, v);
            }else if(strcmp(str, "DONE") == 0) {
                break;
            }
        }
    }
    return(0);
}
