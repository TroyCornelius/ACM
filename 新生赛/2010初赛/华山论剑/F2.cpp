#include <iostream>
#include <vector>
#include <queue>
#define oo 999999999
using namespace std;

struct Tnode
{
       int id, ti;
       Tnode (int a, int b)
         {id=a; ti=b;}
       };
struct Tnode2
{
       int mon, cost_ti;
       Tnode2 (int a=0, int b=oo)
         { mon = a; cost_ti = b;}
       };
vector <vector<Tnode> > g;
queue <int> q;
Tnode2 f[110];
int n, m, time_lim, T;
int val[110], st, en, ans_mon, ans_time;
bool used[110];
void init()
{
     scanf("%d%d%d", &n, &m, &time_lim);
     g.clear();
     g.resize(n+5);
     for (int i=1; i<=n; i++) 
       {
          scanf("%d", &val[i]);  
          val[i] = -val[i];
       }  
     int x, y, c;
     for (int i=0; i<m; i++)
       {
          scanf("%d%d%d", &x, &y, &c);
          g[x].push_back(Tnode(y,c));
          g[y].push_back(Tnode(x,c));             
       }
     scanf("%d%d", &st, &en);
     memset(used, false, sizeof(used));
     ans_mon = ans_time = 0;
     for (int i=0; i<=n; i++)
       {
          f[i].mon = 0;
          f[i].cost_ti = oo;              
       }
     }
void spfa()
{
     used[st] = true;
     f[st].mon = val[st];
     f[st].cost_ti = 0;
     while (!q.empty()) q.pop();
     q.push(st);
     while (!q.empty())
       {
          int now = q.front();
          for (int i=0; i<g[now].size(); i++)
            {
               bool flag = false;
               int tid = g[now][i].id;
               if (f[now].mon + val[tid] <= f[tid].mon && f[now].cost_ti + g[now][i].ti <= time_lim)
                 {
                    if (f[now].mon + val[tid] == f[tid].mon)
                      {
                        if (f[now].cost_ti + g[now][i].ti < f[tid].cost_ti)
                          {
                             f[tid].cost_ti = f[now].cost_ti + g[now][i].ti;  
                             flag = true;          
                          }                                  
                      }
                    else
                      {
                         f[tid].mon = f[now].mon + val[tid];
                         f[tid].cost_ti = f[now].cost_ti + g[now][i].ti;
                         flag = true;                          
                      }
                    
                    if (flag && !used[tid])
                      {
                        q.push(tid);
                        used[tid] = true;                             
                      } 
                 }
            }
          used[now] = false;
          q.pop();           
       }
     if (f[en].mon == 0) printf("0 0\n");
     else
       printf("%d %d\n", -f[en].mon, f[en].cost_ti);
     }
int main()
{
    scanf("%d", &T);
    for (; T>0; T--)
      {
         init();         
         spfa();
         //printf("%d %d\n", ans_mon, ans_time);
      }
    system("pause");    
    return 0;
    }
