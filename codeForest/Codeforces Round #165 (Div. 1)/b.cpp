/*
 * Author:  Troy
 * Created Time:  2013/2/1 23:50:57
 * File Name: b.cpp
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

int n, m, nn;
pair<int, double> p[5050];
int dp[5050];
bool vis[5050];
int main() {
    cin >>n >>m;
    memset(vis, false, sizeof(vis));
    REP(i, n) 
        cin >>p[i].fi >>p[i].se;
    int ans = 0;
    REP(i, n) {
        dp[i] = 1;
        REP(j, i) {
            if (p[j].fi <= p[i].fi) dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout <<n - ans <<endl;

    return 0;
}

/*
13 3
1 1
1 1
1 1
2 1
2 1
1 1
3 1
3 1
3 1
1 1
2 1
2 1
3 1

9 3
3 1
3 1
3 1
3 1
1 1
1 1
1 1
2 2
2 2

 */ 
