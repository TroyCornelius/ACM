/*
 * Author:  Troy
 * Created Time:  2012/4/25 0:14:46
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
const int mod = 1000000007;
int n, L;
int tot;
bool Link[250][250];
pii board[250];
int dp[3100][250];
int main() 
{
    ios::sync_with_stdio(false);
    int a, b;
    cin >>n >>L;
    memset(Link, false, sizeof(Link));
    FOR(i, 1, n+1)
    {
        cin >>a >>b;
        board[i] = mp(a, b);
        if (a != b) board[i+n] = mp(b, a);        
        else board[i+n] = mp(-1, -1);
    }
    FOR(i, 1, n+n+1)
        FOR(j, 1, n+n+1)
        if (i != j && i+n != j && j + n != i)
        {
            if (board[i].se == board[j].fi) Link[i][j] = true;
        }
    FOR(i, 1, n+n+1) Link[0][i] = true;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    int tmp;
    FOR(i, 1, L+1)
    {
        FOR(j, 1, n+n+1)
            if (board[j].fi > 0 && i - board[j].fi >= 0)
            {
                tmp = i - board[j].fi;
                FOR(k, 0, n+n+1)
                    if (Link[k][j] && dp[tmp][k] > 0) 
                    {
                        dp[i][j] += dp[tmp][k];
                        if (dp[i][j] >= mod) dp[i][j] -= mod;
                    }
            }
    }
    int ans = 0;
    FOR(i, 1, n+n+1)
        if (dp[L][i] > 0)
        {
            ans += dp[L][i];
            if (ans >= mod) ans -= mod;
        }
    cout <<ans <<endl;
    return 0;
}

