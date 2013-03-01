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
#include <cctype>
#include <functional>

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
const int inf = 1<<29;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int ans1, ans2;
//int a[5];
char s[4500], str[80];
int n, st_len[5];
int can[4500], match[18];
int dp[4200][17][70];

int solve(bool is_max) {
    REP(i, n+2)
        REP(j, 16)
            REP(k, 64) dp[i][j][k] = (is_max ? -inf : inf);
    dp[0][0][0] = 0;
    int lim = (is_max ? -inf : inf);
    //cout <<is_max <<" "<<n <<" "<<lim <<endl;
    int nk;
    REP(i, n)
        REP(j, 16)
            REP(k, 64) {
                if (dp[i][j][k] == lim) continue;
                //cout <<i <<" : " <<endl;
                 nk = max(0, k - 1);
                if (is_max) dp[i+1][j][nk] = max(dp[i+1][j][nk], dp[i][j][k]);
                else dp[i+1][j][nk] = min(dp[i+1][j][nk], dp[i][j][k]);
                
                int now = ((j ^ 15) & can[i]);
                //cout <<now <<" "<<j <<"!" <<" "<<can[i] <<endl;
                for (int t = now; t; t = (t-1)&now) {
                     nk = max(0, max(k, match[t]) - 1);
                    //cout <<nk <<endl;
                    if (is_max) dp[i+1][(j|t)][nk] = max(dp[i+1][(j|t)][nk], dp[i][j][k] + max(0, match[t] - k));
                    else dp[i+1][(j|t)][nk] = min(dp[i+1][(j|t)][nk], dp[i][j][k] + max(0, match[t] - k));
                    //cout <<i+1 <<" " <<(j|t) <<" "<<nk <<" "<<dp[i+1][j|t][nk] <<endl;
                }
            }
    //cout <<dp[n][15][0] <<endl;
    return dp[n][15][0];
}
int main() {
    while (~sf("%s", s)) {
        n = strlen(s);
        memset(can, 0, sizeof(can));
        REP(i, 4) {
            sf("%s", str);
            int len = strlen(str);
            st_len[i] = len;
            for (int j = 0; j + len <= n; j++) {
                bool flag = true;
                for (int k = 0; k < len; k++)
                    if (s[j+k] != str[k]) {
                        flag = false;
                        break;
                    }
                if (flag) can[j] |= (1<<i);
            }
        }
        
        memset(match, 0, sizeof(match));
        REP(i, 16) {
            REP(j, 4)
                if ((1<<j)&i) match[i] = max(match[i], st_len[j]);
        }
        ans1 = solve(false);
        ans2 = solve(true);
        pf("%d %d\n", ans1, ans2);
    }
    return 0;
}

