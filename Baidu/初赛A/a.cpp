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

int n, m;
int d[Maxn], f[Maxn], pre[Maxn];
bool cmp(int a, int b)
{
     return a>b;
     }
long long ans;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++) scanf("%d", &d[i]);
    sort(d, d+m, cmp);
    memset(pre, -1, sizeof(pre));
    ans = 0;
    int tot = 0, p=0;
    while (tot < n)
    {
       f[tot++] = p;
       d[p]--;
       p++;
       if (p >= m || d[p]==0) p = 0;          
    }
    for (int i=0; i<n; i++)
    {
        if (pre[f[i]] != -1) ans += i - pre[f[i]];
        pre[f[i]] = i;        
    }
    cout <<ans <<endl;
    
    
    return 0;
    }
