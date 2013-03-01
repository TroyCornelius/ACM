/*
 * Author:  Troy
 * Created Time:  2012/6/15 21:26:44
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
#define lim 1000000000000003LL
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<long long,long long> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
typedef long long ll;
vector<pii> ans;
long long m, c[5011][5011];
void init()
{
    c[0][0] = 1;
    FOR(i, 1, 4001)
    {
        c[i][0] = 1;
        FOR(j, 1, i+1)
        {
            c[i][j] = c[i-1][j-1] + c[i-1][j];
            if (c[i][j] > lim) c[i][j] = lim;
        }
    }
}

int main() 
{
    int T;
    sf("%d", &T);
    init();
    while (T--)
    {
        //cin >>m;
        sf("%lld", &m);
        ans.clear();
        
        ans.pb(pii(m, 1)); ans.pb(pii(m, m-1));
        REP(i, 4001)
            REP(j, i+1)
                if (c[i][j] == m) ans.pb(pii(i, j));
        long long tmp = 1;
        for (ll k = 2; k <= 4; k++)
        {
            tmp *= k;
            ll le = (ll)pow(m*tmp, 1.0/k);
            ll ri = le + k;
            FOR(n, le, ri+1)
            {
                ll s = 1;
                REP(i, k) s *= (n - i);
                if (s == m * tmp)
                {
                    ans.pb(pii(n, k));
                    ans.pb(pii(n, n-k));
                }
            }            
        }
        sort(all(ans));
        ans.resize(unique(all(ans)) - ans.begin());
        pf("%d\n", ans.size());
        REP(i, ans.size())
        {
            pf("(%lld,%lld)%c", ans[i].fi, ans[i].se, i == ans.size()-1 ? '\n' : ' ');
        }
        
        
    }
    return 0;
}

