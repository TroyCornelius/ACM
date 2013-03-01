/*
 * Author:  Teletubbies
 * Created Time:  2012年10月06日 星期六 19时26分17秒
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
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
#define ll long long
const int mod = 1000000007;
int n, k, d, ans;
const ll MOD = 1000000007LL;
ll dp[1111][1111][11];
ll sum[1111][1111][11];
const int N = 1000;
const int D = 10;
void init() {
    memset(dp, 0, sizeof(dp));
    memset(sum, 0, sizeof(sum));
    for(int i = 0; i <= N; i++)
        for(int j = 1; j <= D; j++)
            sum[i][0][j] = 1;
    for(int k = 1; k <= D; k++) {
        for(int i = 1; i <= N; i++) {
            dp[i][1][k] = 1;
            sum[i][1][k] = (sum[i-1][1][k] + dp[i][1][k]) % MOD;
        }
        for(int i = 2; i <= N; i++) {
            for(int j = 2; j <= N; j++) {
                if(i - k >= 1) dp[i][j][k] = sum[i-k][j-1][k] % MOD;
                sum[i][j][k] = (sum[i-1][j][k] + dp[i][j][k]) % MOD;
            }
        }
    }
    /*
    int k = 1;
    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++) {
            cout << dp[i][j][k] << " ";
        }
        cout << endl;
    }
    */
    cout << sum[3][0][2] << endl;
}

int main() {
    int T, ca = 0;
    init();
    cin >> T;
    while (T--) {
        cin >> n >> k >> d;
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            ans = (ans + dp[i][k][d]) % MOD;
            //cout << i << " " << k << " " << d << " " << dp[i][k][d] << endl;
        }
        cout << ans << endl;
        cout << sum[3][0][d] << endl;
        for(int i = 1; i < d; i++) {
            for(int j = n; j > i - d + n; j--) {
                int tmp = j - i - 1;
                cout << tmp << " " << k - 2 <<  endl;
                if(tmp >= 0 && k - 2 >= 0) {
                    cout << sum[tmp][k-2][d] << endl;
                    ans = ((ans - sum[tmp][k-2][d]) % MOD + MOD) % MOD;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

