#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
const int Maxn = 1<<25;
int n, m, ans;
char g[30][30];
int st[30];
bool vis[Maxn+10];
struct Tnode
{
       int totr, totl, stat, res;
       Tnode(){}
       Tnode(int a, int b, int c, int d)
       :totr(a),totl(b), stat(c),res(d){}
       };
queue<Tnode> que;
inline int calc(int k)
{
       int ret = 0;
       while (k)
       {
             k -= k&(-k);
             ret++;             
       }
       return ret;
       }
int main()
{
    ios::sync_with_stdio(false);
    int tmp, cnt, tt, nt;
    while (cin >>n >>m)
    {
          memset(st, 0, sizeof(st));
          memset(vis, false ,sizeof(vis));
          for (int i=0; i<n; i++)
          {
            for (int j=0; j<m; j++)
            {
                cin >>g[i][j];
                if (g[i][j] == '*') st[i] |= (1<<j);
            }
          }  
          tmp = (1<<n) - 1;
          cnt = n;
          for (int i=0; i<n; i++)
            if (!st[i]) tmp ^= (1<<i), cnt--;  
          while (!que.empty()) que.pop();
          que.push(Tnode(cnt, 0, tmp, 0));
          ans = cnt;
          while (!que.empty())
          {
                Tnode now = que.front();
                que.pop();                
                for (int i=0; i<n; i++)
                if ((1<<i) & now.stat)
                {
                   nt = now.stat-(1<<i);
                   if (vis[nt]) continue;
                   vis[nt] = true;
                   tmp = now.res | st[i];
                   cnt = now.totl + calc(tmp ^ now.res);
                   if (cnt >= now.totr-1 && cnt >= ans) continue;
                   tt = max(now.totr - 1, cnt);
                   if (ans > tt) ans = tt;                   
                   que.push(Tnode(now.totr - 1, cnt, nt, tmp));
                }
          }          
          cout <<ans <<endl;
    }    
    system("pause");
    return 0;
    }
