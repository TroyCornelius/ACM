#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define Maxn 10010
#define pb push_back
using namespace std;

vector<int> g1[Maxn], g2[Maxn];
int n, m, pos[Maxn], cnt, tot;
int id[Maxn], out[Maxn];
bool mark[Maxn];
void init()
{
     int a, b;
     scanf("%d%d", &n, &m);
     for (int i=0; i<m; i++)
     {
         scanf("%d%d", &a, &b);
         g1[a].pb(b);     
         g2[b].pb(a);    
     }   
     }
void dfs1(int k)
{
     id[k] = 0;
     for (int i=0; i<g1[k].size(); i++)
       if (id[g1[k][i]] == -1) dfs1(g1[k][i]);
     pos[tot++] = k;
     }
void dfs2(int k)
{
     id[k] = cnt;
     for (int i=0; i<g2[k].size(); i++)
       if (id[g2[k][i]] == -1) dfs2(g2[k][i]);
     }

void work()
{
     memset(id, -1, sizeof(id));
     tot = 0;
     for (int i=1; i<=n; i++)
       if (id[i] == -1) dfs1(i);
     memset(id, -1, sizeof(id));
     cnt = 0;
     for (int i=tot-1; i>=0; i--)
     if (id[pos[i]] == -1) 
     {
        dfs2(pos[i]);
        cnt++;                    
     }
     memset(mark, false, sizeof(mark));
     for (int i=1; i<=n; i++)
     {
         for (int j=0; j<g1[i].size(); j++)
         if (id[i] != id[g1[i][j]]) mark[id[i]] = true;         
     }
     int p, ans=0;
     for (int i=0; i<cnt; i++)
     if (!mark[i])
     {
        ans++;
        p = i;          
     }
     if (ans > 1) printf("0\n");
     else
     {
         ans = 0;
         for (int i=1; i<=n; i++) 
         if (id[i] == p) ans++;
         printf("%d\n", ans);         
     }     
     }
int main()
{
    init();
    work();
    
    return 0;
    } 
