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
using namespace std;

int sum[50][50];
class DropCoins
{
      public:
      int getMinimum(vector <string> board, int K)
      {
          int n = board.size();
          int m = board[0].length();
          int ans = 1<<30;
          memset(sum, 0, sizeof(sum));
          for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
            {
                if (board[i][j] == 'o') sum[i+1][j+1] = 1;
                sum[i+1][j+1] += sum[i+1][j] + sum[i][j+1] - sum[i][j];                
            }
          
          for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
              for (int x=1; x<=n; x++)
                for (int y=1; y<=m; y++)
                {
                    int tmp = sum[x][y] - sum[x][j-1] - sum[i-1][y] + sum[i-1][j-1];
                    if (tmp == K)
                    {
                       int cnt = (i-1) + (j-1) + (n-x) + (m-y) + min(i-1, n-x) + min(j-1, m-y);
                       ans = min(ans, cnt);                            
                    }   
                }
          if (ans == (1<<30)) ans = -1;
          return ans;  
      }

      };
