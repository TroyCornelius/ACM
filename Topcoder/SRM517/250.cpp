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
#define Maxn 5000
#define inf 1<<30
#define pb push_back
#define mp make_pair
using namespace std;

class MonochromaticBoard
{
      public:
      bool vis[100], flag;
      int theMin(vector <string> board)
      {
          int n = board.size();
          int m = board[0].length();          
          int ans = 0, tmp = 0;
          memset(vis, false, sizeof(vis));
          for (int i=0; i<n; i++)
          {
              flag = false;
              for (int j=0; j<m; j++)
                if (board[i][j] == 'W') {flag=true;break;}
              if (!flag) 
              {
                 for (int j=0; j<m; j++)
                 if (board[i][j] == 'B' && !vis[j]) {flag=true;break;}
                 if (flag) tmp++;
                 continue;
              }
              else
              {
                  for (int j=0; j<m; j++)
                  if (board[i][j] == 'B' && !vis[j])
                  {
                     tmp++;
                     vis[j] = true;                                  
                  }                  
              }
          }
          ans = tmp; tmp = 0;
          memset(vis, false, sizeof(vis));
          for (int j=0; j<m; j++)
          {
              flag = false;
              for (int i=0; i<n; i++)
                if (board[i][j] == 'W') {flag=true;break;}
              if (!flag) 
              {
                 for (int i=0; i<n; i++)
                 if (board[i][j] =='B' && !vis[i]) {flag=true;break;}
                 if (flag) tmp++;
                 continue;
              }
              else
              {
                  for (int i=0; i<n; i++)
                  if (board[i][j] == 'B' && !vis[i])
                  {
                     tmp++;
                     vis[i] = true;                                  
                  }                  
              }
          }       
          return min(ans, tmp);   
          
      }

      
      };

int main()
{
    
    return 0;
    }
    

