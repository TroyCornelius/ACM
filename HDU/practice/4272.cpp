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
int n;
int a[1210];
int dp[1210][1210];
int dfs(int dep, int st) {
    if (dep < 0) {
        if (st == 0) return 1;
        else return 0;
    }
    if (dp[dep][st] != -1) return dp[dep][st];
    int &ret = dp[dep][st];
    ret = 0;
    if (!((1<<9)&st)) {
        int nst = (st << 1);   
        if (dep - 10 >= 0) nst |= 1;
        ret = dfs(dep - 1, nst);
    }
    else {
        ret = 0;
        int cnt = 0, t = 0;
        int nst = (st ^ (1<<9));
        FORD(i, 8, 0) {
            t++;
            if ((1<<i)&st) {
                cnt++;
                if (cnt > 5) break;
                if (a[dep-t] == a[dep]) {
                   int tmp = (nst ^ (1<<i)); 
                   tmp <<= 1;
                   if (dep - 10 >= 0) tmp |= 1;
                   ret |= dfs(dep - 1, tmp);
                   if (ret) break;
                }
            }
        }
    }
    return ret;
}
int main() {
    while (~sf("%d", &n)) {
        REP(i, n) sf("%d", &a[i]);
        if (n & 1) puts("0");
        else {
            memset(dp, -1, sizeof(dp));
            int tmp = 0, j = 0;
            for (int i = n-1; i >= 0 && j <= 9; --i, ++j) tmp = (tmp * 2) + 1;
            while (j <= 9) tmp <<= 1, j++;
            int ans = dfs(n-1, tmp);
            if (ans) puts("1");
            else puts("0");
        }
    }
    return 0;
}
