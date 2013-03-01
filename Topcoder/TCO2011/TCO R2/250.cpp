#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>
#include <functional>
#include <vector>
#include <cctype>
#include <queue>
#include <cstring>
using namespace std;


class BlackWhiteMagic
{      
      public :
      int count(string s)
      {
          int ans = 0;
          int cw=0, cb=0;
          int len = s.size();
          
          for (int i=0; i<len; i++)
          if (s[i]=='W') cw++;
          else cb++;


          int j=len-1;
          for (int i=0; i<cw; i++)
          if (s[i]=='B')
          {
             while (j>=cw)
             if (s[j] == 'W')
             {              
                ans++;
                swap(s[j], s[i]);
                j--;
                break;
             }             
             else j--;
          }
          for (int i=0; i<cw; i++)
          if (s[i]=='B') return -1;
          
          return ans;   
      }
      
      }d;
int main()
{
    string ss;
    while (cin >>ss)
    {
          cout <<d.count(ss) <<endl;
          
    }
    return 0;
    }
