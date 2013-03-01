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
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

int n, m;
int deg[128], g[128][128];
int main()
{
    int a, b, ans = 0;
    memset(g, 0, sizeof(g));
    memset(deg, 0, sizeof(deg));
    cin >>n >>m;
    for (int i=0; i<m; i++)
    {
        cin >>a >>b;
        deg[a]++;
        deg[b]++;
        g[a][b] = g[b][a] = 1;        
    }
    bool flag = false;
    vector<int> t;
    while (!flag)
    {
          flag = true;
          t.clear();
          for (int i=1; i<=n; i++)
          if (deg[i] == 1) 
          {   
             t.push_back(i);
             flag = false;    
             deg[i]--;            
          }
          if (!flag){
             ans++;
             for (int i=0; i<t.size(); i++){//cout<<t[i]<<endl;
               for (int j=1; j<=n; j++)
               {
                   if (g[t[i]][j] == 1)
                   {
                      if (deg[j] > 0) deg[j]--;                                  
                   }                   
               }}
          }          
    }
    cout <<ans <<endl;

    
    
    return 0;
    }
