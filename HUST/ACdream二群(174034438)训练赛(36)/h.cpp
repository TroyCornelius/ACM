/*
 * Author:  Troy
 * Created Time:  2012/6/8 23:14:36
 * File Name: h.cpp
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;


const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
char gm[12][110][110];
int n, L, h, w, s;
struct People
{
    int fi, r, c, p, ti;
}peo[110];

int dis[12][110][110];

struct Tnode
{
    int fi, r, c;
    Tnode() {}
    Tnode(int _fi, int _r, int _c)
    :fi(_fi),r(_r),c(_c){}
};
pii find_st()
{
    REP(i, h)
        REP(j, w)
        if (gm[0][i][j] == 'S') return mp(i, j);
}
bool check(int f, int x, int y)
{
    return x>=0 && y>=0 && x<h && y<w && gm[f][x][y] != 'X' && dis[f][x][y] == -1;
}
void bfs()
{
    memset(dis, -1, sizeof(dis));
    queue<Tnode> q;
    pii tmp = find_st();
    dis[0][tmp.fi][tmp.se] = 0;
    q.push(Tnode(0, tmp.fi, tmp.se));
    while (!q.empty())
    {
        Tnode now = q.front();
        q.pop();
        int x = now.r, y = now.c, f = now.fi;
        if (gm[f][x][y] == 'U')
        {
            if (dis[f+1][x][y] == -1)
            {
                dis[f+1][x][y] = dis[f][x][y] + 1;
                q.push(Tnode(f+1, x, y));
            }
        }
        else
        if (gm[f][x][y] == 'D')
        {
            if (dis[f-1][x][y] == -1)
            {
                dis[f-1][x][y] = dis[f][x][y] + 1;
                q.push(Tnode(f-1, x, y));
            }
        }
        REP(i, 4)
        {
            int tx = x + dx[i], ty = y + dy[i];
            if (check(f, tx, ty))
            {
                dis[f][tx][ty] = dis[f][x][y] + 1;
                q.push(Tnode(f, tx, ty));
            }
        }
    }
}

int dp[20100];
void work_dp()
{
    memset(dp, 0, sizeof(dp));
    REP(i, n) {
        peo[i].ti = dis[peo[i].fi-1][peo[i].r-1][peo[i].c-1] * 3;
        //if (peo[i].ti < 0) 
        //{
            //cout <<"fuck it!" <<endl;
            //cout <<gm[peo[i].fi-1][peo[i].r-1][peo[i].c-1] <<endl;
        //}
    }
    REP(i, n)
    if (peo[i].ti > 0)
        FORD(j, s, peo[i].ti)
            dp[j] = max(dp[j], dp[j-peo[i].ti] + peo[i].p);
    cout <<dp[s] <<endl;
}
int main() 
{
    //freopen("j.in", "r", stdin);
    //freopen("my.out", "w", stdout);
    ios::sync_with_stdio(false);
    int T;
    cin >>T;
    while (T--)
    {
        cin >>L >>h >>w >>n >>s;
        REP(i, L)
            REP(x, h)
                REP(y, w)
                    cin >>gm[i][x][y];
        REP(i, n)
            cin >>peo[i].fi >>peo[i].r >>peo[i].c >>peo[i].p;
        bfs();
        work_dp();
        
    }
    return 0;
}

