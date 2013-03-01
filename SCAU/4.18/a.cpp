/*
 * Author:  Troy
 * Created Time:  2012/4/18 21:17:05
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
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m, g[1010][1010];
int cnt, ans;
bool isrow, iscol;
int calc(vi &t, int k)
{
    int need = cnt / k;
    int ret = maxint;
    REP(i, k)
    {
        int tmp = 0, c = 0;
        for (int j = (i+1)%k; j != i; j = (j+1)%k)
        {
            if (t[j] + c >= need) 
            {
                tmp += t[j] + c - need;
                c = t[j] + c - need;
            }
            else
            {
                tmp += need - t[j] - c;
                c = t[j] + c - need;
            }
        }
        ret = min(ret, tmp);
    }
    reverse(all(t)); 
    REP(i, k)
    {
        int tmp = 0, c = 0;
        for (int j = (i+1)%k; j != i; j = (j+1)%k)
        {
            if (t[j] + c >= need) 
            {
                tmp += t[j] + c - need;
                c = t[j] + c - need;
            }
            else
            {
                tmp += need - t[j] - c;
                c = t[j] + c - need;
            }
        }
        ret = min(ret, tmp);
    }
    return ret;
}
int main() 
{
    int T, ca = 0;
    sf("%d", &T);
    while (T--)
    {
        sf("%d%d", &n, &m);
        cnt = 0;
        REP(i, n)
            REP(j, m)
            {
                sf("%1d", &g[i][j]);
                cnt += g[i][j];
            }
        ans = 0;
        isrow = iscol = false;
        vi t;
        if (cnt % n == 0)
        {
            isrow = true;
            t.clear();
            int sum = 0;
            REP(i, n)
            {
                sum = 0;
                REP(j, m) sum += g[i][j];
                t.pb(sum);
            }
            ans += calc(t, n);
        }
        if (cnt % m == 0)
        {
            iscol = true;
            t.clear();
            int sum = 0;
            REP(i, m)
            {
                sum = 0;
                REP(j, n) sum += g[j][i];
                t.pb(sum);
            }
            ans += calc(t, m);
        }
        if (isrow && iscol) pf("Case %d: both %d\n", ++ca, ans);
        else
            if (isrow) pf("Case %d: row %d\n",++ca, ans);
            else if (iscol) pf("Case %d: column %d\n", ++ca, ans);
            else pf("Case %d: impossible\n", ++ca);
        //pf("%d\n", ans);
    }
    return 0;
}

