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


int f[Maxn], ans;
bool check(int k)
{
     int cnt = 0;
     while (k > 0)
     {
        if (k%10 != 4 && k%10 != 7) cnt++;
        k/=10;
     }
     return cnt == 0;
     }
class TheLuckyGameDivTwo
{
      public :
      int find(int a, int b, int jLen, int bLen)
      {
          memset(f, 0, sizeof(f));
          for (int i=a; i<=b; i++)
          {
              if (check(i)) f[i] = f[i-1] + 1;
              else f[i] = f[i-1];              
          }
          
          int big = 0;
          vector<int> st;
          st.clear();
          for (int i=a; i+jLen-1<=b; i++)
          {
              if (f[i+jLen-1] - f[i-1] > big) 
              {
                big = f[i+jLen-1] - f[i-1];
                st.clear();
                st.push_back(i);                            
              }
              else
              if (f[i+jLen-1] - f[i-1] == big) st.push_back(i);              
          }
          ans = 0;
          int sm = bLen;
          for (int t=0; t<st.size(); t++)
          {
              //cout <<st[t] <<endl;
             sm = bLen;
              for (int i=st[t]; i+bLen-1<=st[t]+jLen-1; i++)
              {
                 // cout <<i <<" "<<i+bLen-1 <<" "<<f[i+bLen-1] - f[i-1]<<"  "<<ans <<endl;
                  if (f[i+bLen-1] - f[i-1] < sm) sm = f[i+bLen-1] - f[i-1];                  
              }
              ans = max(ans, sm);
          }
          return ans;      
      }
      };
      
int main()
{
    int a, b, c, d;
    cin >>a >>b >>c >>d;
    cout <<t.find(a, b, c, d) <<endl;
    system("pause");
    
    
    return 0;
    }
