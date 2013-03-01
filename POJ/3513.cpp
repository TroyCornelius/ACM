#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <map>
#include <vector>
#include <cctype>
#include <cstdlib>
#define pb push_back
#define Maxn 100001
using namespace std;

int vs, fs, tc, tot; 
int deg[Maxn+10];
int f[Maxn][2], num[Maxn][2][2];
string s;
map<string, int>g;
vector<int> adj[Maxn+10];
void init()
{
     tc++; tot = 0;
     for (int i=0; i<Maxn; i++) adj[i].clear();
     g.clear();
     memset(deg, 0, sizeof(deg));     
     }
void dfs(int x)
{
     f[x][0] = vs; f[x][1] = fs;   // 0 is single while 1 is family
     num[x][0][0] = 1; num[x][0][1] = 0;  
     num[x][1][0] = 0; num[x][1][1] = 1;
     
     for (int i=0; i<adj[x].size(); i++) dfs(adj[x][i]);
     for (int i=0; i<adj[x].size(); i++)
     {
         int v = adj[x][i];
         if (f[v][0] < f[v][1])
         {
                     
         }
         else
         if (f[v][0] > f[v][1])
         {
                     
         }
         else
         {
             
         }
     }
      
     
     }
void work()
{
     for (int i=1; i<tot; i++)
     {
         if (!deg[i]) dfs(i);
         
     }
     
     
     }
int main()
{
    string s1, s2;
    int loc, wa[1010], k;
    ios::sync_with_stdio(false);
    tc = 0;
    getline(cin, s);
    while (true)
    {
       if (isdigit(s[0]))
       {
          loc = s.find(" ", 0);
          s1 = s.substr(0, loc);
          vs = atoi(s1.c_str());
          s1 = s.substr(loc+1, s.length() - loc);
          fs = atoi(s1.c_str());     
          if (vs == 0 && fs == 0) break;        
          else continue;            
       }
       init();
       while (true)
       {
          getchar();
          getline(cin, s);
          if (isdigit(s[0]))
          {
             work();
             break;
          }
          else
          {
              k = 0;
              loc = 0;
              s1.clear();
              for (int i=0; i<s.length(); i++)
              if (s[i]==' ')
              {
                 int v = g[s1];
                 if (v == 0) g[s1] = ++tot;
                 wa[k++] = v;
                 s1.clear();                          
              }
              else s1 += s[i];
              int v = g[s1];
              if (v == 0) g[s1] = ++tot;
              wa[k++] = v;
              s1.clear();
              for (int i=1; i<k; i++) 
              {
                 deg[wa[i]]++;
                 adj[wa[0]].pb(wa[i]);                  
              }
          }
             
       }
    }
    return 0;
    }
