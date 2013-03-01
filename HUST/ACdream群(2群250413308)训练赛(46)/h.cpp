/*
 * Author:  Troy
 * Created Time:  2012/7/28 21:30:57
 * File Name: h.cpp
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
#define ll long long
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<30;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, k;
ll sum[Maxn];
int m;
pii d[Maxn];
//int dp[Maxn][12], que[Maxn];
/*int work_dp()
{
    REP(i, m+1)
        REP(j, k+1)
        dp[i][j] = inf;
    dp[0][0] = 0;
    int head = 0, tail = 0;
    FOR(i, 1, k+1)
    {
        head = tail = 0;
        
    }
    
}*/
ll mi;
int next[Maxn];
void dfs(int dep, int loc, ll tot)
{
    if (tot >= mi) return;
    if (dep >= k-1)
    {
        tot += loc > m ? n : abs(sum[m] - sum[loc] - n);
        mi = min(mi, tot);
        return;        
    }
    int tmp = next[loc];
    //int next = lower_bound(sum+1, sum+1+m, tmp) - sum;
    dfs(dep+1, tmp, tot + abs(sum[tmp] - sum[loc] - n));
    dfs(dep+1, tmp-1, tot + abs(sum[tmp-1] - sum[loc] - n));
}
ll solve()
{
    sort(d, d+n);
    int i = 0, j = 0;
    m = 0;
    sum[0] = 0;
    while (i < n)
    {
        while (j < n && d[j].fi == d[i].fi) j++;
        m++;
        sum[m] = sum[m-1] + j - i;
        i = j;
    }
    sum[m+1] = inf;
    //REP(i, m+1) cout <<sum[i] <<" ";cout <<endl;
    FOR(i, 1, m+1) sum[i] *= k;
    for (i = 0, j = 0; i <= m; i++)
    {
        while (j <= m && sum[j] - sum[i] < n) j++;
        next[i] = j;
        //cout <<i<<" " <<j <<" "<<sum[j] - sum[i] <<endl;
        //cout <<next[i] <<endl;
    }
    //REP(i, m+1) cout <<sum[i] <<" ";cout <<endl;
    //REP(i, m+1) cout <<next[i] <<" ";cout <<endl;
    //cout <<"---------------------" <<endl;
    //return work_dp();<F4>
    mi = inf;
    dfs(0, 0, 0);
    return mi;
}

int main() 
{
    int ca = 0;
    while (~sf("%d%d", &n, &k), n+k)
    {
        REP(i, n) sf("%d%d", &d[i].fi, &d[i].se);
        ll ans = solve();
        REP(i, n) swap(d[i].fi, d[i].se);
        ans = min(ans, solve());
        ll v = __gcd(ans, 1LL*k*k);
        if (ans == 0)
        {
            pf("%d. 0/1\n", ++ca);
        }
        else
        {
            pf("%d. %lld/%lld\n", ++ca, ans/v, 1LL*k*k/v);
        }
        
    }
    return 0;
}

