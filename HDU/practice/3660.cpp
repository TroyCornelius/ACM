/*
题目大意：Alice 和 Bob在一颗树上轮流走，每天边有一定的权值，Alice想走的权值和尽量小，Bob想走尽量大，同时所走的权值和必须在[L, R]这个给定的区间内，Bob先走。求Bob能得到的最大的权值和是多少？ 注意：如果还能走，Alice就不能停下来，一直都到不能走为止，Alice不能中途停下来

解法：树dp，设f[t]表示到节点t得到的最优值，然后从叶节点递归回来，Alice选最小走，Bob选最大值，另外加一个辅助数组dist[u]表示从跟到节点u的距离，dist[u]+f[t]+cost(u, t) 必须在[L, R]之间才转移

这题如果直接做的话加上各种常数优化剪枝，用C++编译器勉强能过，1800+MS，G++会TLE的，后面开了输入挂之后，速度瞬间提高N倍，用G++仅耗时800+MS，膜拜输入挂
*/
#include <iostream>
#include <cstdio>
#define Maxn 500050
using namespace std;
const int inf = 1<<30;
struct Edge
{
       int u, v, cost, next;
       }et[Maxn];
int eh[Maxn], tot;
int n, L, R;
int f[Maxn], dist[Maxn];
void init()
{
     memset(eh, -1, sizeof(eh));
     tot = 0;
     dist[0] = 0;
     }
inline void addedge(int u, int v, int cost)
{
     et[tot].v = v; et[tot].u = u; et[tot].cost = cost;
     et[tot].next = eh[u];
     eh[u] = tot++;     
     }
void dfs(int t, bool player)  // true for bob
{
     if (dist[t] > R) {f[t] = 0; return;}
     f[t] = player?-1:inf;
     if (eh[t] == -1)
     {
        f[t] = 0;
        return;               
     }
     for (int i=eh[t]; i!=-1; i=et[i].next)
     {
         int v = et[i].v;
         int w = et[i].cost;
         dist[v] = dist[t] + w;
         dfs(v, !player);
         if (f[v] == -1 || f[v] == inf) continue;
         if (dist[t] + f[v] + w <= R && dist[t] + f[v] + w >= L)
         {
            if (player) f[t] = max(f[t], f[v] + w);
            else f[t] = min(f[t], f[v]+w);                     
         }         
     }
     
     }
int getint(){
    char c = getchar();
    int t = 0;
    while (c < '0' || c > '9'){
        c = getchar();
    }
    while (c >= '0' && c <= '9'){
        t = t * 10 + c - '0';
        c = getchar();
    }
    return t;
}
int main()
{
    int a, b, c;
    while (scanf("%d%d%d", &n, &L, &R) != EOF)
    {
          init();
          for (int i=1; i<n; i++)
          {
             // scanf("%d%d%d", &a, &b, &c);
              a = getint();
              b = getint();
              c = getint();
              addedge(a, b, c);              
          }
          dfs(0, true);
          if (f[0]>=L && f[0]<=R) printf("%d\n", f[0]);
          else printf("Oh, my god!\n");
    }
    return 0;
    }

