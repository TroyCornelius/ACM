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

class WhichDay
{
      public :      
      string getDay(vector <string> notOnThisDay)
      {
             string a[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
             bool flag;
             for (int i=0; i<7; i++)
             {
                 flag = true;
                 for (int j=0; j<notOnThisDay.size(); j++)
                 if (notOnThisDay[j] == a[i]) {flag = false;break;}
                 if (flag) return a[i];    
             }
             return a[6];
      }
      
      };
      

