/*
 * Author:  Troy
 * Created Time:  2012/5/4 21:48:12
 * File Name: j.cpp
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
vi g[2020];
long long ans;
int main() 
{
    int T, a, b, tmp;
    sf("%d", &T);
    while (T--)
    {
        sf("%d%d", &n, &m);
        REP(i, 1, n+1) g[i].clear();
        REP(i, m)
        {
            sf("%d%d", &a, &b);
            g[a].pb(b);
            g[b].pb(a);
        }
        if (n < 3) ans = 0;
        else
        {
            ans = 1LL * n * (n - 1) * (n - 2);
            FOR(i, 1, n+1)
            {
                long long tmp = g[i].size();
                
            }
        }
    }
    return 0;
}

