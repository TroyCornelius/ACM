/*
��Ŀ���⣺Alice �� Bob��һ�����������ߣ�ÿ�����һ����Ȩֵ��Alice���ߵ�Ȩֵ�;���С��Bob���߾�����ͬʱ���ߵ�Ȩֵ�ͱ�����[L, R]��������������ڣ�Bob���ߡ���Bob�ܵõ�������Ȩֵ���Ƕ��٣� ע�⣺��������ߣ�Alice�Ͳ���ͣ������һֱ����������Ϊֹ��Alice������;ͣ����

�ⷨ����dp����f[t]��ʾ���ڵ�t�õ�������ֵ��Ȼ���Ҷ�ڵ�ݹ������Aliceѡ��С�ߣ�Bobѡ���ֵ�������һ����������dist[u]��ʾ�Ӹ����ڵ�u�ľ��룬dist[u]+f[t]+cost(u, t) ������[L, R]֮���ת��

�������ֱ�����Ļ����ϸ��ֳ����Ż���֦����C++��������ǿ�ܹ���1800+MS��G++��TLE�ģ����濪�������֮���ٶ�˲�����N������G++����ʱ800+MS��Ĥ�������
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

