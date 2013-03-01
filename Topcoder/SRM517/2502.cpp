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
      bool vx[100], vy[100]; 
      int theMin(vector <string> board)
      {
          int n = board.size();
          int m = board[0].length();
          int ans = n + m;
          memset(vx, false, sizeof(vx));
          memset(vy, false, sizeof(vy));
          for (int i=0; i<n; i++)
          {
            for (int j=0; j<m; j++)
              if (board[i][j] == 'W' && !vy[j]) {ans--; vx[i] == true;break;}
            for (int j=0; j<m; j++)
              if (board[i][j] == 'W')
            
          }
          
          
          
      }

      
      };

int main()
{
    
    return 0;
    }
    

