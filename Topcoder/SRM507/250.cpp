#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <stack>
#include <cctype>
using namespace std;

int f[8]={0,1,2,1,1,2,3,2};
class getMinimumSteps
{
      public :
      int getMinimumSteps(vector <int> pos)
      {
          int ans = 0;
          for (int i=0; i<pos.size(); i++) ans >?= f[pos[i]];
          return ans;          
      }
      
      
      };
