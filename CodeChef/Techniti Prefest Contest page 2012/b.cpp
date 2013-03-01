/*
 * Author:  Troy
 * Created Time:  2012/2/28 0:20:59
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
#include <assert.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
const int dx[]={0,0,1,-1,1,1,-1,-1};
const int dy[]={1,-1,0,0,-1,1,-1,1};
int n, m, ans;
char g[210][210];
bool vis[210][210];
inline bool check(int x, int y)
{
    return (x < n && x >= 0 && y<m && y>=0 && g[x][y]=='#' && !vis[x][y]);
}
void dfs(int x, int y)
{
    vis[x][y] = true;
    REP(i, 8)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if (check(tx, ty)) dfs(tx, ty);
    }
}
/*void bfs(int sx, int sy)
{
    int x, y, tx, ty;
    queue<pii> q;
    q.push(mp(sx, sy));
    while (!q.empty())
    {
        pii now = q.front();
        q.pop();
        x = now.fi, y = now.se;
        vis[x][y] = true;
        REP(i, 8)
        {
            tx = x + dx[i], ty = y + dy[i];
            if (check(tx, ty)) q.push(mp(tx, ty));
        }
    }
    return;
}*/
int main() 
{
    ios::sync_with_stdio(false);
    int T;
    cin >>T;
    assert(T <= 20);
   // scanf("%d", &T);
 //   getchar();
    while (T--)
    {
        ans = 0;
        cin >>n >>m;
       // scanf("%d%d", &n, &m);
        REP(i, n)
        {
            REP(j, m)// scanf("%c", &g[i][j]);
            //getchar();
            cin >>g[i][j];
        }
        //memset(vis, false, sizeof(vis));
        REP(i, n)
            REP(j, m) vis[i][j] = false;
        REP(i, n)
            REP(j, m)
            if (!vis[i][j] && g[i][j] == '#')
            {
                dfs(i, j);
                ans++;
            }
        cout <<ans <<endl;
    }
    return 0;
}

