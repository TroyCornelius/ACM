/*
 * Author:  Troy
 * Created Time:  2012/6/12 22:16:43
 * File Name: bb.cpp
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
#define Maxn 1610
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

char g[Maxn*3][Maxn*3];
int tot[Maxn][Maxn];
int n, m;
queue<pii> q;
bool vis[Maxn*3][Maxn*3];
pii fuck;
void init()
{
    memset(g, 0, sizeof(g));
    memset(vis, false, sizeof(vis));
    
    fuck = mp(0,0 );
    REP(i, n)
    {
        sf("%s", &g[i]);
        REP(j, m)
            if (g[i][j] == 'S') 
            {
                fuck = mp(i, j);
                g[i][j] = '.';
            }
    }
    
    REP(i, n*3)
        REP(j, m*3)
        {
            if (i < n && j < m) continue;
            g[i][j] = g[i%n][j%m];
        }
}
void work()
{
    fuck.fi += n; fuck.se += m;
    q.push(fuck);
    vis[fuck.fi][fuck.se] = true;
    
    int tn = n * 3, tm = m * 3;
    while (!q.empty())
    {
        pii now = q.front();
        q.pop();
        
        int x = now.fi, y = now.se;
        REP(i, 4)
        {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 0 || ty < 0 || tx >= tn || ty >= tm) continue;
            if (!vis[tx][ty] && g[tx][ty] != '#')
            {
                vis[tx][ty] = true;
                q.push(mp(tx,ty));
            }
        }
    }
}
int main() 
{
    //cin >>n >>m;
    sf("%d%d", &n, &m);
    init();
    work();
    
    bool ans = false;
    REP(i, n*3)
        REP(j, m*3)
        {
            if (!vis[i][j]) continue;
            int x = i % n, y = j % m;
            tot[x][y] ++;
            if (tot[x][y] > 1) ans = true;
        }
    if (ans) pf("Yes\n");
    else pf("No\n");
                    
}

