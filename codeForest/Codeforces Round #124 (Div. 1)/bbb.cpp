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
int n, m;
queue<pii> q;
pii t[Maxn*3][Maxn*3];
char g[Maxn][Maxn];
bool vis[Maxn*3][Maxn*3];
bool ans;
void work()
{
    while (!q.empty())
    {
        pii now = q.front();
        q.pop();
        REP(i, 4)
        {
            int x = now.fi + dx[i], y = now.se + dy[i];
            int xx = (x %n + n) % n, yy = (y %m + m) % m;
            if (g[xx][yy] != '#')
            {
                if (vis[xx][yy])
                {
                    if (t[xx][yy] != mp(x, y))
                    {
                        ans = true;
                        return;
                    }
                }
                else
                {
                    vis[xx][yy] = true;
                    t[xx][yy] = mp(x, y);
                    q.push(mp(x, y));
                }
            }
        }
    }
}
int main() 
{
    //cin >>n >>m;
    sf("%d%d", &n, &m)
    REP(i, n)
        sf("%s", &g[i]);
    memset(vis, false, sizeof(vis));
    REP(i, n)
    {
        REP(j, m)
            if (g[i][j] == 'S')
            {
                vis[i][j] = true;
                t[i][j] = mp(i, j);
                q.push(mp(i, j));
            }
    }
    ans = false;
    work();
    if (ans) pf("Yes\n");
    else pf("No\n");
    return 0;
}
