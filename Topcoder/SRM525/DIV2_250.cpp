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
#define mp make_pair
#define fi first
#define se second
using namespace std;

const int dx[]={0,0,1,-1,1,1,-1,-1};
const int dy[]={1,-1,0,0,1,-1,1,-1};
bool vis[100][100];
typedef pair<int,int> pii;
class RainyRoad
{
      public:  
      string isReachable(vector <string> road)
      {
             int n = road.size();
             int m = road[0].length();
             memset(vis, false, sizeof(vis));
             queue<pii> q;
             q.push(mp(0, 0));
             vis[0][0] = true;
             while (!q.empty())
             {
                   pii now = q.front();
                   q.pop();
                   for (int i=0; i<8; i++)
                   {
                       int tx = now.fi + dx[i];
                       int ty = now.se + dy[i];
                       if (tx>=0 && tx<n && ty>=0 && ty<m && road[tx][ty] != 'W' && !vis[tx][ty])
                       {
                          vis[tx][ty] = true;
                          q.push(mp(tx, ty));                   
                       }                       
                   }                  
             }
             if (vis[0][m-1]) return "YES";
             else return "NO";             
             
      }

      };
