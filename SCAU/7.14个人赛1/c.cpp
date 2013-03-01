/*
 * Author:  Troy
 * Created Time:  2012/7/14 14:35:47
 * File Name: c.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
#define N 1005
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
vi g[N*2+10], ng[N*2+10];
int col[2*N], in[N*2], flag[N*2];
int line[N*2+10], tot, cnt;
void dfs1(int u)
{
    col[u] = 1;
    REP(i, g[u].size())
    {
        int v = g[u][i];
        if (!col[v]) dfs1(v);
    }
    line[++tot] = u;
}


void dfs2(int u)
{
    col[u] = cnt;
    REP(i, ng[u].size())
    {
        int v = ng[u][i];
        if (!col[v]) dfs2(v);
    }
}

int work()
{
    tot = 0;
    memset(col, 0, sizeof(col));
    REP(i, n+n+1)
        if (!col[i]) dfs1(i);
    cnt = 0;
    memset(col, 0, sizeof(col));
    FORD(i, tot, 1)
    {
        if (col[line[i]] == 0)
        {
            cnt++;
            dfs2(line[i]);
        }
    }
    FOR(i, 1, n+1)
        if (col[n-i] == col[n+i]) return 0;
    return 1;
}
int main() 
{
    int a, b;
    while (~sf("%d%d", &n, &m))
    {
       REP(i, n+n+10) {g[i].clear();ng[i].clear();}
       REP(i, m)
       {
           sf("%d%d", &a, &b);
           g[n - a].pb(n + b);  g[n - b].pb(n + a);
           ng[n + b].pb(n - a); ng[n + a].pb(n - b);
       } 
       int ans = work();
       pf("%d\n", ans);
    }
    
    return 0;
}

