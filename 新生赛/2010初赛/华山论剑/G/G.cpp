#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, ans;
int map[55][55];

struct Tnode
{
       int x, y, dir, change;
       Tnode (int i, int j, int c, int d)
         {x=i; y=j; dir=c; change=d;}
       };
bool f[55][55];
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
queue<Tnode> q;
void bfs(int a, int b)
{
     memset(f, false, sizeof(f));
     f[a][b] = true;
     while (!q.empty()) q.pop();
     for (int c=0; c<4; c++) q.push(Tnode(a,b,c,0));
     while (!q.empty())
       {
          Tnode now = q.front();
          q.pop();
          if (now.change > 2) continue;
          int tx = now.x + dx[now.dir];
          int ty = now.y + dy[now.dir];
          if (tx >= 0 && tx < n && ty >= 0 && ty < m  && !f[tx][ty])
            { 
               f[tx][ty] = true;
               if (map[tx][ty]!=0 && map[tx][ty]!=map[a][b]) continue;
              
               if (map[a][b] == map[tx][ty]) {ans++;continue;}
               for (int k=0; k<4; k++) 
                 if (k==now.dir) q.push(Tnode(tx, ty, k, now.change));
                 else q.push(Tnode(tx, ty, k, now.change+1));
            }
       }
     }
int main()
{
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++)
      for (int j=0; j<m; j++)
        scanf("%d", &map[i][j]);
    ans = 0;
    for (int i=0; i<n; i++)
      for (int j=0; j<m; j++)
      {
         if (map[i][j] != 0)  
         {
            bfs(i, j);  
           // cout <<i <<" "<<j <<" " <<map[i][j] <<" "<<ans <<endl;
         }   

   
      }
    cout <<(ans/2) <<endl;
    system("pause");
    return 0;
    }
