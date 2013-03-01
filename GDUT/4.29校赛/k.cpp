/*
 * Author:  Troy
 * Created Time:  2012/4/29 13:37:29
 * File Name: k.cpp
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

int n, m, cost[110];
struct Tnode
{
    int a,b,c;
}d[110];
int calc(int st)
{
    int ret = 0;
    bool vis[110];
    memset(vis, false, sizeof(vis));
    REP(i, m)
    {
        if ((1<<i)&st)
        {
            FOR(j, d[i].a, d[i].b+1) vis[j] = true;
            ret += d[i].c;
        }
    }
    FOR(i, 1, n+1)
        if (vis[i]) ret -= cost[i];
    return ret;
}
int main() 
{
    freopen("k.in", "r", stdin);
    freopen("k.out", "w", stdout);
    int T;
    sf("%d", &T);
    while (T--)
    {
        cin >>n;
        FOR(i, 1, n+1) cin >>cost[i];
        cin >>m;
        REP(i, m) cin >>d[i].a >>d[i].b >>d[i].c;
        int ans = 0;

        REP(i, 1<<m)
        {
            int tmp = calc(i);
            if (tmp > ans) ans = tmp;            
        }
        cout <<ans <<endl;
    }
    return 0;
}

