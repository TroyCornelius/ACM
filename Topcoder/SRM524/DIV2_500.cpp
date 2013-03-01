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

bool check(long long m)
{
     for (long long i=2; i*i<=m; i++)
     if (m % i == 0) return false;
     return true;
     }
class MultiplesWithLimit
{
      public:
      long long minimalTransfer(long long n)
      {
           if (check(n) && n!=1) return 2;
           else return 1;           
      }
      };
