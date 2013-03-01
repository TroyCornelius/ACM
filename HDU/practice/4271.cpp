/*
 * Author:  Troy
 * Created Time:  2012/9/8 22:19:56
 * File Name: 4271.cpp
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

char s[Maxn+Maxn], str[12], out[12];
int n, m;
int ans;
int dp[Maxn][12];
void work_dp(int len1, int len2) {
    memset(dp, 0, sizeof(dp));
    REP(i, m+1) dp[i][0] = i;
    FOR(i, m+1, m+m+1) dp[i][0] = m;
    REP(i, len2+1) dp[0][i] = i;
    FOR(i, 1, len1+1)
        FOR(j, 1, len2+1)
        dp[i][j] = min(dp[i-1][j-1] + (s[i-1] == str[j-1] ? 0 : 1), min(dp[i-1][j] + 1, dp[i][j-1] + 1));    
}
int main() {
    while (~sf("%s", s)) {
        sf("%d", &n);
        ans = 100;
        m = strlen(s);
        for (int i = 0; i < m; ++i) s[m+i] = s[i];
        REP(i, n) {
            sf("%s", str);
            int len = strlen(str);
            if (m > 2*len) {
                work_dp(m+m, len);
                FOR(i, 1, m+m+1)
                    if (dp[i][len] < ans) {
                        ans = dp[i][len];
                        memcpy(out, str, sizeof(str));
                    }
                    else if (dp[i][len] == ans) {
                        if (strcmp(str, out) == -1) memcpy(out, str, sizeof(str));
                    }
                
            }
        }
        
    }
    return 0;
}

