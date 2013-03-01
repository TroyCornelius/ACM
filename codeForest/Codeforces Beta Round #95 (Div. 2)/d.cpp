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
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Maxn 3100
using namespace std;

int n;
int flag, ans[Maxn];
vector<int> g[Maxn];
stack<int> q;
bool vis[Maxn], ring[Maxn];
void dfs(int rt, int fa)
{
     vis[rt] = true;
     q.push(rt);
     for (int i=0; i<g[rt].size(); i++)
     {
         int v = g[rt][i];
         if (v!=fa && !vis[v])
         {
            dfs(v, rt); 
            if (flag != -1) return;
         }
         else
         if (v!=fa)
         {
             flag = v;
             return ;    
         }
     }
     if (flag == -1) q.pop();     
     return;
     }
void dfs1(int u, int len)
{     
     ans[u] = len;
     vis[u] = true;
     for (int i=0; i<g[u].size(); i++)
     {
         int v = g[u][i];
         if (ans[v] == -1) dfs1(v, len+1);         
     }
     return;
     }
int main()
{
    int a, b;
    scanf("%d", &n);
    for (int i = 0; i<=n; i++) g[i].clear();
     
    for (int i =0; i<n; i++)
    {
        scanf("%d%d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);        
    }
    memset(vis, false, sizeof(vis));
    while (!q.empty()) q.pop();
    flag = -1;
    dfs(1, -1);
    memset(ring, false, sizeof(ring));
    memset(ans, -1, sizeof(ans));
    //cout <<flag <<" "<<q.top() <<" "<<q.size() <<endl;
    while (!q.empty())
    {
        //  cout <<q.top() <<endl;
          vis[q.top()] = true;
          ans[q.top()] = 0;
          if (q.top() == flag) break;      
          q.pop();    
    }
    memset(vis, false, sizeof(vis));
    for (int i=1; i<=n; i++)
    {
        if (ans[i]==0) dfs1(i, 0);
    }
    for (int i=1; i<n; i++) printf("%d ", ans[i]);
    printf("%d\n", ans[n]);
    
   // system("pause");
    return 0;
    }
