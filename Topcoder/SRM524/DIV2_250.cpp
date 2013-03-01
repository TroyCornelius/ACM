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

class ShippingCubes
{
      public:
      int minimalCost(int N)
      {     
            int ans = 1<<30;
            for (int i=1; i<=N; i++)
              for (int j=1; j<=N; j++)
              {
                  if (N%(i*j) == 0)
                  {
                     int k = N / (i * j);
                     if (i + j + k < ans) ans = i + j +k;                              
                  }                  
              }
              return ans;
      }
     
      };
