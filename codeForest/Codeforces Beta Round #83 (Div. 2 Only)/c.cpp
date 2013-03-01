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
#define inf 999999999
#define pb push_back
using namespace std;

int n, p;
int in[Maxn], out[Maxn];

struct edge
{
       int next, flow;
       edge() {}
       edge(int _a, int _b)
       :next(_a), flow(_b){}
       }g[Maxn];
struct Tnode
{
       int tank, tap, len;
       Tnode(int a, int b, int c)
       :tank(a), tap(b), len(c){}
       bool operator < (const Tnode &b) const
       {
          return tank < b.tank;     
       }
       };
vector<Tnode> ans;
int main()
{
    int a, b, c;
    scanf("%d%d", &n, &p);
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    for (int i=0; i<=n; i++) g[i].next = g[i].flow = -1;
    for(int i=0; i<p; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        in[b]++; out[a]++;
        g[a] = edge(b, c);            
    }
    int tot = 0, j, tmp;
    ans.clear();
    for (int i=1; i<=n; i++)
    if (in[i]==0)
    {
        j= i; tmp = g[j].flow;
        while (g[j].next != -1) 
        {
              tmp = min(g[j].flow, tmp);
              j = g[j].next;
        }
        if (i != j) 
        {
          ans.pb(Tnode(i, j, tmp));   
          tot++;
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", tot);
    for (int i=0; i<ans.size(); i++) printf("%d %d %d\n", ans[i].tank, ans[i].tap, ans[i].len);
   // system("pause");
    return 0;
    }
