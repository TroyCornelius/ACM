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

const int mod = 1000000007;
class SRMSystemTestPhase
{
      public:
      int f[55][5][5][5];
      bool check(int i, int j, int k, int p)
      {
           return (((i>0&&des[p][0]=='Y')||(i==0&&des[p][0]=='N')) 
                   &&((j>0&&des[p][1]=='Y')||(j==0&&des[p][1]=='N'))
                   &&((k>0&&des[p][2]=='Y')||(k==0&&des[p][2]=='N')));
      }
      int countWays(vector <string> des)
      {
          memset(f, 0, sizeof(f));
          for (int i=0; i<4; i++)
            for (int j=0; j<4; j++)
              for (int k=0; k<4; k++)
              if (check(i,j,k,0)) f[0][i][j][k] = 1;
          
          for (int p=1; p<des.size(); p++)
          {
              
              
          }
          
          
          
          
      
          
          
      }
      };
