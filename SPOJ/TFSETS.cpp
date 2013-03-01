/*
 * Author:  Troy
 * Created Time:  2012/8/24 22:44:10
 * File Name: TFSETS.cpp
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

const int mod = 1000000001;
int n;

bool b[Maxn];
int pri[Maxn], pn;
void init() {
    memset(b, true, sizeof(b));
    pn = 0;
    for (int i = 2; i <= 100000; i++)
        if (b[i]) {
            pri[pn++] = i;
            for (int j = i+i; j<=100000; j+=i) b[j] = false;
        }
}
bool used[Maxn];

int dp[(1<<11)+10][18];
//int can[12][500], tot[12];
int can[500], tot;
bool check(int st) {
    REP(i, 11) {
        if (((1<<i)&st) && ((1<<(i+1))&st)) return false;
    }
    return true;
}
long long three[15];
void work_dp() {
    memset(dp, 0, sizeof(dp));
    
    int ret = 1;
    //int tmp = x, s = 3;
    tot = 0;
    //memset(tot, 0, sizeof(tot));
    three[0] = 1;
    for (int i = 1; i < 12; i++) three[i] = three[i-1] * 3;
    REP(i, 1<<11) {
        if (check(i)) can[tot++] = i;
    }
    //cout <<tot <<endl;
    long long s1 = 1, s2 = 1;
    for (int i = 0; i < tot; i++) dp[0][can[i]] = 1;
    for (int x = 1; x < 17; x++) {
        s2 = 1;
        for (int j = 0; j < tot; ++j) {
            for (int k = 0; k < tot; ++k) {
                if (can[j] & can[k]) continue;
                int &tmp = dp[x][can[j]];
                tmp += dp[x-1][can[k]];
                if (tmp >= mod) tmp -= mod;
            }
        }
    }
}

long long calc(int a) {
    long long ret = 0;
    long long sum = a;
    int t = 0;
    for (int i = 0; i < 17; ++i) {
        if (sum > n) break;
        used[sum] = true;
        t = 0;
        REP(j, tot) {
            if ((1<<(t+1)) <= can[j]) t++;
            if (sum * three[t] > n) break;
            cout <<i <<" "<<can[j] <<" "<<dp[i][can[j]] <<endl;
            used[sum*three[t]] = true;
            ret += dp[i][can[j]];
            if (ret >= mod) ret -= mod;
            
        }
        sum *= 2LL;
    } 
    cout <<a <<" "<<ret <<endl;
    return ret;
}
int main() 
{
    int T;
    sf("%d", &T);
    work_dp();
    long long ans;
    while (T--) {
        sf("%d", &n);
        REP(i, n+1) used[i] = false;
        ans = 1;
        for (int i = 1; i <= n; i++) 
            if (!used[i]) {
                ans *= calc(i);
                ans %= mod;
            }
        pf("%I64d\n", ans);
    }

    return 0;
}

