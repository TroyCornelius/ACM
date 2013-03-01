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

int c[55][55];
void init()
{
     memset(c, 0, sizeof(c));
     c[1][1] = 1;
     for (int i=2; i<=50; i++)
       for (int j=1; j<=i; j++)
         c[i][j] = (c[i-1][j] + c[i-1][j-1]) % 9;
     //for (int i=0; i<=50; i++) c[i][0] = 1;
     }
class LuckyRemainder
{
      public :
      int getLuckyRemainder(string s)
      {
          init();
          int ans = 0;
          int len = s.length()-1;
          for (int i=0; i<s.length(); i++)
          {
             int sum = 0;
             for (int j=0; j<=i; j++)
               for (int t=0; t<=len - i; t++)
               {
                   sum += c[i][j]*c[len-i][t];
               //  ans = (ans + (s[i]-'0')*c[i][j]*c[len-i][t])%9;     
                 //cout <<ans <<"  " <<  c[i][j] <<" "<<c[len-i][t] <<endl;
                // cout <<i <<"/ "<< j <<"   " <<len-i<<"/ "<< t <<endl;
               }
             ans = (ans + (s[i]-'0')*sum%9)%9;
          }
          return ans%9;
      }
      
      }d;

int main()
{
    cout <<d.getLuckyRemainder("123") <<endl;
    system("pause");
    return 0;
    }
