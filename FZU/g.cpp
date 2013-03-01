/*
 * Author:  Troy
 * Created Time:  2012/4/15 13:17:27
 * File Name: g.cpp
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

int n, m;
//bool vis[1500][1500];
set<pii> vis;
bool check()
{
    int u, v;
    vis.clear();
    bool flag = true;
    REP(i, m)
    {
        sf("%d%d", &u, &v);
        if (u > v) swap(u, v);
        if (u == v || vis.find(pii(u, v)) != vis.end()) flag = false;
        vis.insert(pii(u, v));
    }
   /* memset(vis, false, sizeof(vis));
    REP(i, m)
    {
        sf("%d%d", &u, &v);
        if (u == v || vis[u][v]) return false;
        vis[u][v] = vis[v][u] = true;
    }*/
    return flag;
}
int main() 
{
    while (~sf("%d%d", &n, &m))
    {
        if (check()) pf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

