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
#define Maxn 1010
using namespace std;

int n, ta, tb;
vector<int> d;

struct Tnode
{
       int id, num;
       Tnode (int a, int b)
       {
          id = a;  num = b;     
       }
       };
vector<vector<Tnode> > p[Maxn];
bool vis[Maxn];
int f[Maxn];

void init()
{
       scanf("%d%d", &ta, &tb);
       int tmp;
       for (int i=1; i<=n; i++) 
       {
           scanf("%d", &tmp);
           d.push_back(tmp);
       }  
       for (int i=1; i<=n; i++) p[i].clear();    
     }
int gcd(long long a,long long b)
{
    if (a%b==0) return b;
    else return gcd(b, a%b);
    }
int main()
{
    bool flag = false;
    while (scanf("%d", &n))
    {
       if (n == 0) break;
       init();
       for (int i=1; i<=n; i++)
       {
       flag = false;
       memset(vis, false, sizeof(vis));
       int t1 = 0, now = i;
       int len = tb - ta;
       
       while (!vis[d[now]])
       {
             t1++;
             vis[d[now]] = true;
             now += len;
             if (now>n) now-=n;
             f[t1++] = d[now];
             
       }
       sort(d.begin(), d.end());
       
       
       
       }
       

    }
    
    
    return 0;
    }
