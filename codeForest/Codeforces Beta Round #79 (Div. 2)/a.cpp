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
#define inf 999999999
#define pb push_back
using namespace std;

int n, m, p[110], ans;
bool mathch[110][110];

int main()
{
    memset(mathch, false, sizeof(mathch));
    int a, b;
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++) scanf("%d", &p[i]);
    for (int i=0; i<m; i++)
    {
        scanf("%d%d", &a, &b);
        mathch[a][b] = true;
        mathch[b][a] = true;        
    }
    ans = inf;
    for (int i=1; i<=n; i++)
      for (int j=i+1; j<=n; j++)
        for (int k=j+1; k<=n; k++)
          if (mathch[i][j] && mathch[i][k] && mathch[j][k]) ans = min(ans, p[i]+p[j]+p[k]);
    if (ans == inf) printf("-1\n");
    else printf("%d\n", ans);
    
    return 0;
    }
