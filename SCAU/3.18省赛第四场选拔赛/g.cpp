/*
 * Author:  Troy
 * Created Time:  2012/3/18 16:51:36
 * File Name: a.cpp
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
#define Maxn 100010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
int val[Maxn];
vector<int> g[Maxn];
int main() 
{
    int x, y;
    while (~scanf("%d%d", &n, &m))
    {
        FOR(i, 1, n+1) scanf("%d", &val[i]);
        FOR(i, 1, n+1) g[i].clear();
        REP(i, m)
        {
            scanf("%d%d", &x, &y);
            g[x].pb(y);
            g[y].pb(x);
        }
        dfs(1, -1);
            
        
        
    }
    return 0;
}

