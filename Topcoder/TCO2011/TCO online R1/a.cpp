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


class TripleStrings
{
      public :
      int getMinimumOperations(string init, string goal)
      {
          if (init == goal) return 0;
          int len = init.length();
          for (int i=0; i<len; i++)
          {
              string st = init.substr(i, len-i);
              if (goal.find(st, 0) == 0) return i*2;        
          }
          return len*2;          
          
      }
      
      
      
      };
      
