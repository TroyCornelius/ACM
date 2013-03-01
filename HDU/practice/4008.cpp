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
#define all(a) (a).begin(),(a).end()
#define Maxn 100100
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

int n, m, c;
vector<int> g[Maxn];
pii dfn[Maxn];
int minson[Maxn], minchi[Maxn][2];
void dfs(int root, int pre)
{
    dfn[roo].fi = ++c;
    minson[root] = minchi[root][0] = minchi[root][1] = inf;
    REP(i, g[root].size())
    {
        int v = g[root][i];
        if (v == pre) continue;
        if (v < minchi[root][0])
        {
            minchi[root][1] = minchi[root][0];
            minchi[root][0] = v;        
        }
        else minchi[root][1] = min(minchi[root][1], v);
        dfs(v, root);    
        minson[root] = min(minson[root], minson[v]);
    }
    dfn[root].se = ++c;
    minson[root] = min(minson[root], minchi[root][0]);
    return;  
}
int main()
{
    int T, u, v;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        REP(i, n+1) g[i].clear();
        REP(i, n-1)
        {
            scanf("%d%d", &u, &v);
            g[u].pb(v); g[v].pb(u);         
        }
        c = 0;
        dfs(1, 1);
        while (m--)
        {
            scanf("%d%d", &u, &v);
            if (dfn[x].fi < dfn[y].fi || dfn[x].se > dfn[y].se)
            {
                int ans1 = minchi[y][0], ans2 = minson[y];
                if (ans1 == inf) printf("no answers!");
                else printf("%d%d\n", ans1, ans2);            
            }
            else
            {
            
            }
        }
    }
    
    return 0;
}

