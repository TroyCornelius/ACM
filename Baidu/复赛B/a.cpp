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
using namespace std;


int n, h[Maxn];
int k[Maxn];
int big[Maxn][20];
int ans;

void init()
{
     scanf("%d", &n);
     for (int i=0; i<=n; i++) 
     {
         scanf("%d", &h[i]);     
     }
     
     int tmp = 2, id = 0;
     for (int i = 1; i <= n+1; i++)
     {
       if (i >= tmp) {tmp *= 2;  id++;}
       k[i] = id;
     }
}
void build()
{
     for (int i = 0; i <= n; i++)  big[i][0] = i;
     
     for (int i = 1; i < log(n+1) / log(2) + 1; i++)
       for (int j = 0; j <= n - (1 << i) + 1; j++)
       {
         if (h[big[j][i-1]] > h[big[j + (1 << (i - 1))][i - 1]]) big[j][i] = big[j][i-1];
         else big[j][i] = big[j + (1 << (i - 1))][i - 1];
   //      big[j][i] = max(big[j][i - 1], big[j + (1 << (i - 1))][i - 1]);
       }
}
int search(int a, int b)
{
    int tmp, i;
    i = k[abs(a - b) + 1];
    if (h[big[a][i]] > h[big[b - (1 << i) + 1][i]]) tmp = big[a][i];
    else tmp = big[b - (1 << i) + 1][i];
   // tmp = max(big[a][i], big[b - (1 << i) + 1][i]);
    return tmp;
}
void work()
{
     int p = 0, p2, last = h[0];
     ans = 0;
     while (p < n)
     {     
       p2 = min(n, h[p]+p);
       int loc = search(p, p2);
       if (h[loc] > last) ans += h[loc] - last; 
       last = h[loc];
       p = loc + 1;           
      
     }
     cout <<ans <<endl;
     
     }
int main()
{    
    init();
    build();
    work();
    system("pause");
    return 0;
    }

