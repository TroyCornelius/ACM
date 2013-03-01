#include <vector>
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

bool check(int n)
{
       string s = "";
       while (n > 0)
       {
             char t = '0' + n%10;
             s  = t + s;
             n /= 10;             
       }
       for (int i=0, j=s.length()-1; i<=j; i++, j--)
       if (s[i] != s[j]) return false;
       return true;       
       }
class PalindromizationDiv2
{
      public :
      int getMinimumCost(int p)
      {
          int ans=0;
          
          for (int i=0; i<=p; i++)
          {
              if (check(p+i) || check(p-i)) 
              {
                 ans = i; 
                 break;
              }              
          }
          return ans;
      }
      };

