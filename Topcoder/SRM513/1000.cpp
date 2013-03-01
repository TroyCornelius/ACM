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
using namespace std;

class CutTheNumbers
{
      public:
      int ans;
      int maximumSum(vector <string> board)
      {
          int s1=0, s2=0;
          string s;
          for (int i=0; i<board.size(); i++)
          {
              s1 += atoi(board[i].c_str());              
          }
          for (int j=0; j<board[0].length(); j++)
          {
              s = "";
              for (int i=0; i<board.size(); i++) s+= board[i][j];
              s2 += atoi(s.c_str());              
          }
          return max(s1, s2); 
      }
      
      
      
      };

