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
#define MOD 1000000009
using namespace std;

class YetAnotherIncredibleMachine
{
      public :
      long long cnt[55];
      long long ans;
      int countWays(vector <int> plat, vector <int> plen, vector <int> balls)
      {
          sort(balls.begin(), balls.end());
          int idx;
          ans = 1;
          for (int i=0; i<plat.size(); i++)
          {
              for (idx=0; idx<balls.size() && balls[idx]<plat[i]; idx++);
              if (idx==balls.size())
              {
                 cnt[i] = min(plat[i] - balls[idx-1], plen[i]+1);                                    
              }
              else
              if (idx==0 && balls[idx] > plat[i])
              {
                 cnt[i] = min(balls[idx] - plat[i], plen[i]+1);                         
              }
              else
              {
                  if (balls[idx] == plat[i]) return 0;
                  int tmp = balls[idx] - balls[idx-1];
                  if (tmp - plen[i] - 1 <= 0) return 0;
                  else cnt[i] = min(tmp - plen[i] - 1, min(plat[i]-balls[idx-1], balls[idx]-plat[i]));
              }             
              ans = (ans * (cnt[i])) % MOD;
          }
          return ans;
      }
      };

