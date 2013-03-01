/*
 * Author:  Troy
 * Created Time:  2013/1/20 21:22:26
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
#define Maxn 100010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int a[Maxn];
int prime[Maxn], tot;
int n;
int id[Maxn];
int dp[Maxn];
vector<int> vec[Maxn];
void getPrime() {
    tot = 0;
    bool vis[Maxn];
    memset(vis, true, sizeof(vis));
    for (int i = 2; i < Maxn; i++) {
        if (vis[i]) {
            prime[tot++] = i;
            int b = id[i];
            for (ll j = i + i; j < Maxn; j += i) {
                if (id[j] != -1) {
                    if (b != -1) {
                        vec[b].pb(id[j]);
                    }
                    b = id[j];
                }
                vis[j] = false;
            }
        }
    }
}

void solve() {
    memset(id, -1, sizeof(id));
    for (int i = 0; i < n; i++) {
        vec[i].clear();
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        id[a[i]] = i;
        dp[i] = 1;
    } 
    getPrime();
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) continue;
        for (int j = 0; j < vec[i].size(); j++) {
            dp[vec[i][j]] = max(dp[vec[i][j]], dp[i] + 1);
        }
    }
}
int main() {
    cin >>n;
    solve();
    cout << *max_element(dp, dp + n) << endl;
    return 0;
}

