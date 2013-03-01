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
#define Maxn 55
using namespace std;

double pro[Maxn], f[Maxn];
int n;
class MuddyRoad
{
      public :
      double getExpectedValue(vector <int> road)
      {
             n = road.size();
             for (int i=0; i<road.size(); i++) pro[i] = double(road[i]) / 100.0;
             f[0] = 1.0;
             for (int i=1; i<n; i++)
             {
                 f[i] = f[i-1]*pro[i];
                 if (i>2) f[i] += f[i-2]*pro[i];                 
             }
             return f[n-1];      
      }
      }a;
int main()
{
    vector<int> p;
    p.clear();
    cin >>n;
    int t;
    for (int i=0; i<n; i++)
    {
        cin >>t;
        p.push_back(t);        
    }
    cout <<a.getExpectedValue(p) <<endl;
    system("pause");
    return 0;
    }      
