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
#define Maxn 2020
#define inf 999999999
#define pb push_back
#define mp make_pair
using namespace std;

int n, m, fa[Maxn], ans, tmp;
vector<int> edge[Maxn];
bool vis[Maxn];
void dfs(int rt, int lvl)
{
     vis[rt] = true;
     if (lvl > tmp) tmp = lvl;
     for (int i=0; i<edge[rt].size(); i++)
     {
         if (!vis[edge[rt][i]]) dfs(edge[rt][i], lvl+1);         
     }
     }
int main()
{
    cin >>n;
    for (int i=1; i<=n; i++) 
    {
        cin >>fa[i];
        if (fa[i] != -1)
        {
           edge[i].pb(fa[i]);
           edge[fa[i]].pb(i);                  
        }        
    }
    memset(vis, false, sizeof(vis));
    ans = 0;
    for (int i=1; i<=n; i++)
    if (fa[i]==-1)
    {
        tmp = 0;
        dfs(i, 1);
        ans = max(ans, tmp);
    }
    cout <<ans <<endl;
 //   system("pause");
    return 0;
    }
