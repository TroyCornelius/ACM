/*
 * Author:  Troy
 * Created Time:  2013/2/11 23:43:56
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

const int N = 565;
const int M = 112222;
const int inf = 1<<30;
int n, m;
int maz[N][N], cnt[N][N];
int prime[M], tot;
bool isPrime[M];

void init() {
    memset(isPrime, true, sizeof(isPrime));
    tot = 0;
    for (int i = 2; i < M; i++) {
        if (isPrime[i]) {
            prime[tot++] = i;
            for (ll j = 1LL * i * i; j < M; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int bs(int x) {
    int l = 0, r = tot - 1;
    int res = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if (prime[mid] >= x) {
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }
    return prime[res] - x;
}

int main() {
    init();
    cin >>n >>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maz[i][j];
            cnt[i][j] = bs(maz[i][j]);
        }
    }
    int ans = inf;
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        for (int j = 0; j < m; j++) {
            tmp += cnt[i][j];
        }
        ans = min(ans, tmp);
    }
    for (int j = 0; j < m; j++) {
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            tmp += cnt[i][j];
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}

