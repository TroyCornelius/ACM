/*
 * Author:  Troy
 * Created Time:  2012/3/31 21:08:08
 * File Name: 1007.cpp
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
#define Maxn 100100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

const int mod = 1000000009;
int n, a[Maxn], sum[Maxn], m, ans;
int t[Maxn];
inline int bs(int val)
{
    return lower_bound(sum, sum + m, val) - sum;
}
void add(int idx, int val)
{
    for (int i = idx + 1; i <= m; i += i & -i)
        t[i] = (t[i] + val) % mod;
}
int query(int idx)
{
    int ret = 0;
    for (int i=idx+1; i>0; i-= i&-i) ret = (ret + t[i])%mod;
    return ret;
}
int main() 
{
    while (~sf("%d", &n))
    {
        memset(t, 0, sizeof(t));
        REP(i, n) sf("%d", &a[i]);
        sum[0] = 0;
        REP(i, n) sum[i+1] = sum[i] + a[i];
        sort(sum, sum + n + 1);
        m = unique(sum, sum + n + 1) - sum;
        add(bs(0), 1);
        ans = 0;
        int tmp = 0;
        REP(i, n)
        {
            tmp += a[i];
            ans = query(bs(tmp));
            add(bs(tmp), ans);
        }
        pf("%d\n", ans);
    }
    return 0;
}

