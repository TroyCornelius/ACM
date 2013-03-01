/*
 * Author:  Troy
 * Created Time:  2012/12/1 11:10:44
 * File Name: c.cpp
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
#define ll long long
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;


ll dp[1<<15][15];
bool vis[15][15];
int all, m;
ll dfs(int mask, int last) {
    if (mask == all) return dp[mask][last] = 1;
    ll &ret = dp[mask][last];
    if (ret != -1) return ret;
    ret = 0;
    REP(i, m) {
        if (vis[last][i] && !(mask&(1<<i))) ret += dfs(mask | (1<<i), i);
    }
    return ret;
}
class RandomOption {

    public:
    double getProbability(int n, vector <int> badLane1, vector <int> badLane2) {
        memset(vis, true, sizeof(vis));
        REP(i, badLane1.size()) {
            int x = badLane1[i], y = badLane2[i];
            vis[x][y] = vis[y][x] = false;
        }
        m = n;
        memset(dp, -1, sizeof(dp));
        all = (1<<n) - 1;
        double ans = 0;
        REP(i, n) ans += dfs((1<<i), i);
        for (int i = 1; i <= n; i++) ans /= 1.0 * i;
        return ans;
    }
};


int main() 
{
    return 0;
}

