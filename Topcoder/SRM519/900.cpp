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

class BinaryCards
{
      public:
      long long largestNumber(long long A, long long B)
      {
           long long dif = A^B;
           while (dif)
           {
                 A |= dif;
                 dif >>= 1;                 
           }
           return A;       
      }      
      };
