/*
 * Author:  Troy
 * Created Time:  2012/8/3 0:22:29
 * File Name: 4328_最大矩阵周长.cpp
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
#define Maxn 1010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m, ans;
int dp[Maxn][Maxn];
char g[Maxn][Maxn];

int le[Maxn], ri[Maxn], col[Maxn][Maxn]; //le[], ri[]分别表示当前烈向左向右最多能走多少
void work(char ch)
{
    FOR(j, 1, m+1)
        FOR(i, 1, n+1)
            col[i][j] = (g[i][j] == ch ? col[i-1][j] + 1 : 0);
    
    int lp, rp;
    FOR(j, 1, m+1) le[j] = 1, ri[j] = m;
    FOR(i, 1, n+1)
    {
        lp = 1, rp = m;
        FOR(j, 1, m+1)
        if (g[i][j] == ch)
        {
            if (le[j] < lp) le[j] = lp;
        }
        else lp = j+1, le[j] = 1, ri[j] = m;
        FORD(j, m, 1)
        if (col[i][j])
        {
            if (ri[j] > rp) ri[j] = rp;
            ans = max(ans, 2 * (col[i][j] + ri[j] - le[j] + 1));
        }
        else rp = j - 1;
    }
}


int main() 
{
    int T, ca = 0;
    sf("%d", &T);
    while (T--)
    {
        sf("%d%d", &n, &m);
        FOR(i, 1, n+1)
            sf("%s", g[i]+1);
        ans = 0;
        FOR(i, 1, n+1)
            FOR(j, 1, m+1)
            {
                dp[i][j] = 1;
                if (g[i][j-1] != g[i][j] && g[i-1][j] != g[i][j])
                {
                    int tmp = min(dp[i-1][j], dp[i][j-1]);
                    if (dp[i][j-1] != dp[i-1][j-1] || g[i][j] == g[i-tmp][j-tmp])  tmp++;
                    dp[i][j] = max(dp[i][j], tmp);
                }
                ans = max(ans, 4*dp[i][j]);
            }
        work('B');
        work('R');
        pf("Case #%d: %d\n", ++ca, ans);
    }
    return 0;
}

