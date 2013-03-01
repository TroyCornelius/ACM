/*
 * Author:  Troy
 * Created Time:  2012/6/22 23:50:18
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
#define Maxn 101000
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, k;
string s[2];
int f[Maxn][2];
bool vis[Maxn][2];
bool spfa()
{
    //memset(f, -1, sizeof(f));
    memset(vis, false, sizeof(vis));
    REP(i, n+5) f[i][0] = f[i][1] = maxint;
    f[0][0] = 0;
    queue<pii> que;
    que.push(mp(0,0));
    while (!que.empty())
    {
        pii now = que.front();
        que.pop();

        int p = now.fi, id = now.se;
        vis[p][id] = false;

        if (p + 1 >= n || (p + 1 < n && s[id][p+1] != 'X' && f[p][id] + 1 <= p+1))
        {
            if (p + 1 >= n) return true;
            if (f[p+1][id] > f[p][id] + 1)
            {
                f[p+1][id] = f[p][id] + 1;
                if (!vis[p+1][id])
                {
                    vis[p+1][id] = true;
                    que.push(mp(p+1, id));
                }
            }            
        }

        if (p - 1 >= 0 && s[id][p-1] != 'X' && f[p][id] + 1 <= p - 1)
        {
            if (f[p-1][id] > f[p][id] + 1)
            {
                f[p-1][id] = f[p][id] + 1;
                if (!vis[p-1][id])
                {
                    vis[p-1][id] = true;
                    que.push(mp(p-1, id));
                }
            }
        }

        if (p + k >= n || (p + k < n && s[id^1][p+k] != 'X' && f[p][id] + 1 <= p + k))
        {
            if (p + k >= n) return true;
            if (f[p+k][id^1] > f[p][id] + 1)
            {
                f[p+k][id^1] = f[p][id] + 1;
                if (!vis[p+k][id^1])
                {
                    vis[p+k][id^1] = true;
                    que.push(mp(p+k, id^1));
                }
            }
        }

    }
    return false;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin >>n >>k;
    cin >>s[0];
    cin >>s[1];
    s[0] += "-";
    s[1] += "-";
    bool ans = spfa();
    if (ans) cout <<"YES" <<endl;
    else cout <<"NO" <<endl;

    return 0;
}

