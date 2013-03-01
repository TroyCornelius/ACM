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
#include <ext/hash_map>
#define Maxn 15
#define Maxk 50050
using namespace std;
using namespace __gnu_cxx;

int n, k;
struct Tnode
{
       int ai, bi;
       }d[Maxn];
void init()
{
     scanf("%d%d", &n, &k);
     for (int i=0; i<n; i++) scanf("%d%d", &d[i].ai, &d[i].bi);
     
     
     }
hash_map<int, int> f;
int c[Maxk];
int check(int hp)
{
     f.clear();
     int p1;
     c[0] = 0; p1 = 1;
     bool flag = true;
     int tmp, ti=1, x;
     while (flag)
     {
         flag = false;
         x = p1;
         for (int i=0; i<p1; i++)
         {
             for (int j=0; j<n; j++)
             {
                 tmp = c[i] + d[j].ai + d[j].bi * ti;
                 if (tmp <= hp && f.find(tmp) == f.end())
                 {
                    f[tmp] = 1;
                    c[x++] = tmp;
                    flag = true;      
                 }
                 if (x > k+1) return x-1;
             }             
         }
         p1 = x;
         ti++;           
     }
     return p1-1;
     }
int main()
{
        init();
        
        int lo = 1, hi = 1000000, mid;
        while (lo+1 < hi)
        {
           mid = (lo + hi) / 2;
           if (check(mid) >= k) hi = mid;
           else lo = mid;       
        }
        
        if (check(mid)==k) cout <<mid <<endl;
        else
        if (check(hi)==k) cout <<hi <<endl;
        else cout <<lo <<endl;;    
    

    return 0;
    }
