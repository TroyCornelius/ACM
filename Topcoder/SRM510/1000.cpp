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

int ans;
bool check(long long k)
{
     while (k > 0)
     {
        if (k%10 != 4 && k%10 != 7) return false;
        k/=10;
     }
     return true;
     }
class TheLuckyBasesDivTwo
{
      public :
      long long find(long long n)
      {
          if (n==4 || n==7) return -1;
          
          ans = 0;
          
          
           
           
           
      }
      
      
      };
