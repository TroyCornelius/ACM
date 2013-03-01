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
#define pb push_back
using namespace std;

class TrainingCamp
{
      public :
      vector<string> att, p;
      bool check(int x, int y)
      {
           for (int i=0; i<p[y].length(); i++)
           if (p[y][i] == 'X')
           {
              if (att[x][i] != 'X') return false;                    
           }
           return true;
      }
      vector <string> determineSolvers(vector <string> attendance, vector <string> problemTopics)
      {
          vector<string> ans;
          string s;
          att = attendance;
          p = problemTopics;
          for (int i=0; i<att.size(); i++)
          {
              s.clear();
              for (int j=0; j<p.size(); j++)
              {
                  if (check(i, j)) s+='X';
                  else s+='-';                  
              }
              ans.pb(s);
          }
          return ans;             
      }
      
      
      };

