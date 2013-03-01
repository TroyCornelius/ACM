/*
 * Author:  Troy
 * Created Time:  2012/7/14 19:47:04
 * File Name: b.cpp
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
#define Maxn 30010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

vi g[Maxn], ng[Maxn];
int n, m;
int tot, cnt, col[Maxn], line[Maxn]; 
int indeg[Maxn], outdeg[Maxn];

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

int main() 
{
    int T;
    sf("%d", &T);
    while (T--)
    {
        sf("%d%d", &n, &m);
        REP(i, n+5)
        {
            g[i].clear();
            ng[i].clear();
        }
        
        int a, b;
        REP(i, m)
        {
            sf("%d%d", &a, &b);
            g[a].pb(b);
            ng[b].pb(a);
        }
        memset(col, 0, sizeof(col));
        tot = 0;
        FOR(i, 1, n+1)
            if (!col[i]) dfs1(i);
        
        cnt = 0;
        memset(col, 0, sizeof(col));
        FORD(i, tot, 1)
            if (!col[line[i]]) 
            {
                cnt++;
                dfs2(line[i]);
            }
        if (cnt == 1) pf("0\n");
        else
        {
            memset(indeg, 0, sizeof(indeg));
            memset(outdeg, 0, sizeof(outdeg));
            FOR(i, 1, n+1)
                REP(j, g[i].size())
                {
                    int v = g[i][j];
                    if (col[i] == col[v]) continue;
                    indeg[col[v]]++;
                    outdeg[col[i]]++;
                }
            int ans1 = 0, ans2 = 0;
            //cout <<cnt <<endl;
            FOR(i, 1, cnt+1)
            {
                //cout <<i <<" "<<indeg[i] <<" "<<outdeg[i] <<endl;
                if (indeg[i] == 0) ans1++;
                if (outdeg[i] == 0) ans2++;
            }
            pf("%d\n", max(ans1, ans2));               
            
        }
        
    }
    return 0;
}

