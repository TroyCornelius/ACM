/*
 * Author:  Troy
 * Created Time:  2012/7/23 23:31:54
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
long long g[110][110];
int dis[110][110];
long long dp1[110], dp2[110];
int main() 
{
    int n, m;
    sf("%d%d", &n, &m);
    memset(g, 0, sizeof(g));
    REP(i, n)
        REP(j, n)
        if (i == j) dis[i][j] = 0;
        else dis[i][j] = inf;
    int a, b;
    REP(i, m)
    {
        sf("%d%d", &a, &b);
        a--; b--;
        g[a][b] = g[b][a] = 1;
        dis[a][b] = dis[b][a] = 1;
    }
    if (n == 2)
    {
        cout <<"1.0000000000" <<endl;
        return 0;
    }
    REP(k, n)
        REP(i, n)
            REP(j, n)
            {
                if (dis[i][j] == dis[i][k] + dis[k][j]) g[i][j] += g[i][k] * g[k][j];
                else if (dis[i][j] > dis[i][k] + dis[k][j]) g[i][j] = g[i][k] * g[k][j];
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
    /*
    REP(i, n)
    {
        REP(j, n) cout <<dis[i][j] <<" ";
        cout <<endl;
    }*/
    /*
    memset(dp1, 0, sizeof(dp1));
    dp1[0] = 1;
    queue<int> que;
    bool hash[110];
    memset(hash, false, sizeof(hash));
    que.push(0);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        hash[now] = false;
        FOR(i, 1, n)
        {
            //cout <<i <<" " <<dis[0][i] <<" "<<dis[0][now] <<" "<<dis[now][i] <<endl;
            if (i != now && g[now][i] && dis[0][i] == dis[0][now] + 1) 
            {
                dp1[i] += dp1[now];
                if (!hash[i])
                {
                    hash[i] = true;
                    que.push(i);
                }
            }
        }
    }
    
    //REP(i, n) cout <<dp1[i] <<" ";
    memset(dp2, 0, sizeof(dp2));
    memset(hash, false, sizeof(hash));
    while (!que.empty()) que.pop();
    dp2[n-1] = 1;
    que.push(n-1);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        hash[now] = false;
        FOR(i, 0, n-1)
        {
            //cout <<i <<" " <<dis[0][i] <<" "<<dis[0][now] <<" "<<dis[now][i] <<endl;
            if (i != now && g[now][i] && dis[n-1][i] == dis[n-1][now] + 1) 
            {
                dp2[i] += dp2[now];
                if (!hash[i])
                {
                    hash[i] = true;
                    que.push(i);
                }
                }
                }
                }
     */
    long long ans = g[0][n-1];
    FOR(i, 1, n-1)
    if (dis[0][i] + dis[i][n-1] == dis[0][n-1])
    {
        if (2LL * g[0][i] * g[i][n-1] > ans) ans = 2LL * g[0][i] * g[i][n-1];
    }
    //cout <<ans <<endl;
    printf("%.10f\n", 1.0 * ans / (double)(g[0][n-1]));
    return 0;
}

