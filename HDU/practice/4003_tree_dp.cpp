#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Maxn 10050
using namespace std;

typedef pair<int,long long> pii;
vector<pii> edge[Maxn];

int n, s;
long long dp[Maxn][15], k;
void init()
{
     int a, b;
     long long c;
     for (int i=0; i<=n; i++) edge[i].clear();
     for (int i=1; i<n; i++)
     {
         scanf("%d%d%I64d", &a, &b, &c);
         edge[a].pb(mp(b, c));
         edge[b].pb(mp(a, c));         
     }
     memset(dp, -1, sizeof(dp));
     }
void dfs(int root, int fa)
{
     for (int i=0; i<edge[root].size(); i++)
       if (edge[root][i].fi != fa) dfs(edge[root][i].fi, root);         
       
     if ((edge[root].size() == 1 && fa!=-1)||(fa==-1 && edge[root].size()==0))
     {
         for (int i=0; i<=k; i++) dp[root][i] = 0;
         return;                            
     }
     
     for (int i=0; i<edge[root].size(); i++)
     {
         int v = edge[root][i].fi;
         long long w = edge[root][i].se;
         if (v == fa) continue;
         for (int j=k; j>=0; j--)
         {
             if (dp[root][j] == -1)
             {
                if (!j) dp[root][j] = dp[v][j] + 2 * w;
                else
                {
                    for (int t=1; t<=j; t++)
                    if (dp[root][j]==-1 || dp[root][j]>dp[v][t]+t*w)
                      dp[root][j] = dp[v][t] + t*w;                    
                }
                continue;          
             }
             else dp[root][j] += dp[v][0] + 2*w;
             for (int t=1; t<=j; t++)
             {
                 dp[root][j] = min(dp[root][j], dp[root][j-t] + dp[v][t] + t*w);                 
             } 
         }
     }
     }
int main()
{
    while (scanf("%d%d%I64d", &n, &s, &k) != EOF)
    {
          init();
          dfs(s, -1);
          printf("%I64d\n", dp[s][k]);
    }
    return 0;
    }
