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
using namespace std;

const int dx[] = {1,-1,0,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,0,1,-1,1,-1};
char g[10][10];
bool vis[10][10][1024];
struct Tnode
{
       int x,y,ti;
       Tnode(){}
       Tnode(int _x,int _y, int _ti)
       :x(_x),y(_y),ti(_ti){}
       };
inline bool check(int x, int y, int ti)
{
       if (x<1 || x>8 || y<1 || y>8) return false;
       if (g[x][y] == 'A') return true; 
       if ((x-ti>0 && g[x-ti][y] == 'S') || (x-ti+1>0 && g[x-ti+1][y] == 'S')) return false;
       return true;
       
      // return false;
       }
bool bfs()
{
     memset(vis, false, sizeof(vis));
     queue<Tnode> q;
     q.push(Tnode(8,1,0));
     vis[8][1][0] = true;
     while (!q.empty())
     {
           Tnode now = q.front();
           q.pop();
         //  cout <<now.x <<" " <<now.y<<" "<<now.ti <<endl;
           for (int i=0; i<9; i++)
           {
               int tx = now.x + dx[i];
               int ty = now.y + dy[i];
               if (check(tx, ty, now.ti+1) && !vis[tx][ty][now.ti+1])
               {
                  if (tx == 1 && ty == 8) return true;
                  q.push(Tnode(tx, ty, now.ti+1));
                  vis[tx][ty][now.ti+1] = true;                             
               }               
           }
     }
     return false;
     }
int main()
{
    for (int i=1; i<=8; i++)
      for (int j=1; j<=8; j++)
        cin >>g[i][j];
    if (bfs()) cout <<"WIN" <<endl;
    else cout <<"LOSE" <<endl;
  // system("pause");
    return 0;
    }
