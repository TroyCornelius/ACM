/*
 * Author:  Troy
 * Created Time:  2012/8/16 23:31:58
 * File Name: 
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
const int maxint = 1<<29;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, c[330][330];
int dis[330];
bool vis[330];
void spfa(int st)
{
    queue<int> que;
    REP(i, n) dis[i] = maxint;
    memset(vis, false, sizeof(vis));
    REP(i, n)
        if (i != st) {dis[i] = c[st][i]; que.push(i);vis[i] = true;}
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        vis[now] = false;
        REP(i, n)
            if (dis[now] + c[now][i] < dis[i])
            {
                dis[i] = dis[now] + c[now][i];
                if (!vis[i])
                {
                    vis[i] = true;
                    que.push(i);
                }
            } 
    }
}
int main() 
{
    while (~sf("%d", &n))
    {
        REP(i, n)
            REP(j, n)
            sf("%d", &c[i][j]);
        spfa(0);
        int ans = dis[n-1], c1 = dis[0]; 
        spfa(n-1);
        ans = min(ans, c1 + dis[n-1]);
        pf("%d\n", ans);
    }
    return 0;
}

