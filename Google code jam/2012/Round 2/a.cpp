/*
 * Author:  Troy
 * Created Time:  2012/5/26 22:11:51
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
#define Maxn 100010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, d[Maxn], len[Maxn], D;

int dp[Maxn];
int main() 
{
    //freopen("A-large.in", "r", stdin);
    //freopen("A-large.out", "w", stdout);
    int T, ca = 0;
    sf("%d", &T);
    while (T--)
    {
        sf("%d", &n);
        FOR(i, 1, n+1)
            sf("%d%d", &d[i], &len[i]);
        sf("%d", &D);
        /*
        while (now < n)
        {
            int mx = 0, k;
            for (int i = now+1; i <= n; i++)
            {
                if (d[i] > pos + p) break;
                int tmp = min(d[i] - d[now], len[i]);
                if (tmp > mx)
                {
                    mx = tmp;
                    k = i;
                }
            }
            
        }
        */
        
        memset(dp, 0, sizeof(dp));
        dp[1] = d[1];
        FOR(i, 1, n+1)
        {
            if (dp[i])
            {
                if (dp[i] > len[i]) dp[i] = len[i];
                FOR(j, i+1, n+1)
                {
                    int tmp = d[j] - d[i];
                    if (tmp > dp[i]) break;
                    if (!dp[j]) dp[j] = tmp;
                    else if (tmp > dp[j]) dp[j] = tmp;
                }
            }
        }
        
        FOR(i, 1, n+1)
            if (dp[i] > len[i]) dp[i] = len[i];
        bool flag = false;
        FOR(i, 1, n+1)
        {
            if (d[i] + dp[i] >= D)
            {
                flag = true;
                break;
            }
        }
        pf ("Case #%d: ", ++ca);
        if (flag) pf("YES\n");
        else pf("NO\n");
        
        
        
    }
    
    return 0;
}

