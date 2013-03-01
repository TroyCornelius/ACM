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
#define Maxn 100010
#define pb push_back
using namespace std;

int n, ta, tb;
vector<int> d;
int main()
{
    while (scanf("%d", &n))
    {
       if (n == 0) break;
       scanf("%d%d", &ta, &tb);
       d.clear();
       int tmp;
       for (int i=0; i<n; i++)
       {
          scanf("%d", &tmp);
          d.pb(tmp);           
       }
       while (d[0] != 1)
       {
          tmp = d[0];
          d.erase(d.begin());
          d.pb(tmp); 
       }
       
       for (int i=0; i<n; i++)
       if (d[i]!=i+1)
       {
           
           
       }
    }

    
    
    return 0;
    }
