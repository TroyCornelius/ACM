/*
 * Author:  Troy
 * Created Time:  2012/5/25 22:46:53
 * File Name: e.cpp
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
#define Maxn 3000
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m, tot, ans;
pii tree[Maxn];
bool cmpX(pii a, pii b)
{
    return a.fi < b.fi;
}
bool cmpY(pii a, pii b)
{
    return a.se < b.se;
}
int main() 
{
    int T, x, y, k;
    sf("%d", &T);
    while (T--)
    {
        sf("%d%d", &n, &m);
        tot = 0;
        tree[tot++] = mp(0, 0);
        tree[tot++] = mp(n, m);
        while (sf("%d", &k), k)
        {
            sf("%d%d", &x, &y);
            if (k == 1) tree[tot++] = mp(x, y);
            else
            {
                int dx, dy;
                sf("%d%d", &dx, &dy);
                REP(i, k) tree[tot++] = mp(x+i*dx, y+dy*i);
            }
        }
        ans = 0;
        sort(tree, tree+tot, cmpX);        
        int lo, hi;
        REP(i, tot)
        {
            lo = 0; hi = m;
            FOR(j, i+1, tot)
            {
                if (tree[i].fi == tree[j].fi) continue;
                ans = max(ans, (tree[j].fi - tree[i].fi) * (hi - lo));
                if (tree[j].se < tree[i].se) lo = max(lo, tree[j].se);
                else hi = min(hi, tree[j].se);
            }
        }
        
        sort(tree, tree+tot, cmpY);
        REP(i, tot)
        {
            lo = 0; hi = n;
            FOR(j, i+1, tot)
            {
                if (tree[j].se == tree[i].se) continue;
                ans = max(ans, (tree[j].se - tree[i].se) * (hi - lo));
                if (tree[j].fi < tree[i].fi) lo = max(lo, tree[j].fi);
                else hi = min(hi, tree[j].fi);
            }            
        }   
        pf("%d\n", ans);     
    }
    return 0;
}

