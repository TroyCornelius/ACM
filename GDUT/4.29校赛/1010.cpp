/*
 * Author:  Troy
 * Created Time:  2012/4/29 12:35:42
 * File Name: 1010.cpp
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

int n, m, c[110], sum[110];
struct Tnode
{
    int x,y,g;
    bool operator <(const Tnode &b) const
    {
        return y < b.y;
    }
}d[110];

int f[110];

int getcost(Tnode a, Tnode b)
{
   /* if (b.y >= a.y) return 0;
    else if (b.y >= a.x && b.y <= a.y) return sum[a.y] - sum[b.y];
    else return sum[a.y] - sum[a.x-1];*/
    return sum[a.y] - sum[max(a.x-1, b.y)];
}
int main() 
{
        freopen("k.in", "r", stdin);
    //freopen("kk.out", "w", stdout);
    int T;
    sf("%d", &T);
    while (T--)
    {
        sf("%d", &n);
        sum[0] = 0;
        FOR(i, 1, n+1)
        {
            sf("%d", &c[i]);
            sum[i] = sum[i-1] + c[i];
        }
        sf("%d", &m);
        d[0].x = d[0].y = d[0].g = 0;
        FOR(i, 1, m+1)
        {
            sf("%d%d%d", &d[i].x, &d[i].y, &d[i].g);
        }
        sort(d, d+m+1);
        int ans = 0;
        REP(i, m+1) f[i] = -inf;
        f[0] = 0;
        FOR(i, 1, m+1)
        {
            FORD(j, i-1, 0)
            {
                int tmp = f[j] + d[i].g - getcost(d[i], d[j]);
                if (tmp > f[i])
                {
                    f[i] = tmp;
                    ans = max(ans, tmp);
                }
            }
        }
        REP(i, m+1) cout <<f[i] <<endl;
        pf("%d\n", ans);
    }
    return 0;
}

