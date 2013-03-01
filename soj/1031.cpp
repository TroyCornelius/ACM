#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <memory.h>
#define oo 99999999
using namespace std;

int T, n, st, en;
int f[150];
struct Tnode
{
       int id, dis;
       Tnode(int a=0, int b=0) {id=a; dis=b;}
       };
vector <Tnode> g[250];
map <string, int> loc;
string s1, s2;
queue <int> q;
bool vis[250];
void init()
{
     scanf("%d", &n);
     int tot = 0, tmp;
     loc.clear();
     for (int i=0; i<=n+5; i++) g[i].clear();
     for (int i=0; i<n; i++)
       {
          cin >>s1 >>s2;
          if (!loc[s1]) loc[s1] = ++tot;
          if (!loc[s2]) loc[s2] = ++tot;
          cin >> tmp;
          int t1 = loc[s1], t2 = loc[s2];
          g[t1].push_back(Tnode(t2, tmp));
          g[t2].push_back(Tnode(t1, tmp));  
       }
     for (int i=0; i<=110; i++) f[i] = oo;
     cin >>s1 >>s2;
     st = loc[s1];
     en = loc[s2];    
     memset(vis, false, sizeof(vis));
     }
void spfa()
{
     
     while (!q.empty()) q.pop();
     q.push(st);
     vis[st] = true;
     f[st] = 0;
     while (!q.empty())
       {
          int now = q.front();
          q.pop();
          vis[now] = false;
          for (int i=0; i<g[now].size(); i++)
            {
               if (f[now] + g[now][i].dis < f[g[now][i].id])
                 {
                    f[g[now][i].id] = f[now] + g[now][i].dis;
                    if (!vis[g[now][i].id])
                      {
                          vis[g[now][i].id] = true;
                          q.push(g[now][i].id);
                      }
                 }                   
            }           
       }
     if (f[en] == oo) cout <<"-1" <<endl;
     else
     cout << f[en] <<endl;
     }
int main()
{
    cin >>T;
    for (;T>0;T--)
      {
          init();
          spfa();                  
      }

    
    return 0;
    }
