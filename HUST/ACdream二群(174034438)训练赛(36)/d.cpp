/*
 * Author:  Troy
 * Created Time:  2012/6/8 19:36:11
 * File Name: d.cpp
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
const int Maxn = 1<<16;
int n, k;
struct Player
{
    int init, now, id;
}d[Maxn];
vector<int> rec[Maxn];
int main() 
{
    int T;
    sf("%d", &T);
    while (T--)
    {
        sf("%d%d", &n, &k);
        REP(i, 1<<n)
        {
            sf("%d", &d[i].init);
            d[i].now = d[i].init;
            d[i].id = i;            
            rec[i].clear();
        }
        for (int p = 1<<n; p > 1; p>>=1)
        {
            int j = 0;
            REP(i, p)
            if (i % 2 == 0)
            {
                if (d[i].now < d[i+1].now) swap(d[i], d[i+1]);
                d[i].now = min(d[i].init, d[i].now - d[i+1].now + k);
                rec[d[i].id].pb(d[i+1].id);
                d[j++] = d[i];
            }
        }
        pf("%d\n", d[0].id+1);
        REP(i, rec[d[0].id].size()) pf("%d%c", rec[d[0].id][i] + 1, i == rec[d[0].id].size() - 1 ? '\n' : ' ');
    }
    return 0;
}

