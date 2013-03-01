/*
 * Author:  Troy
 * Created Time:  2012/11/10 22:46:59
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
#define ll long long
#define ull unsigned long long
const int inf = 1 << 29;
const double dinf = 1e30;
const ll linf = 1LL << 55;
const int N = 1111;
int n, k, a[N];
int sum[1<<20];
int cnt[1<<20];
vector<pii> vec[N*20];

bool cmp(const pii &a, const pii &b) {
    return a.se > b.se;
}

void init() {
    for(int i = 0; i < 20001; i++) vec[i].clear();
    sum[0] = 0;
    cnt[0] = 0;
    for(int mask = 1; mask < (1 << n); mask++) {
        int i = 0;
        while(~mask >> i & 1) i++;
        sum[mask] = sum[mask ^ (1 << i)] + a[i];
        cnt[mask] = cnt[mask ^ (1 << i)] + 1;
        //cout << mask << " " << sum[mask] << endl;
        vec[sum[mask]].pb(mp(mask, cnt[mask]));
    }
}
double st;
bool dfs(int x, int num, int d, int mask) {
    if(num == k) {
        if(mask == (1 << n) - 1) {
            return true;
        } else return false;
    }
    //if (clock() - st > 0.7 * CLOCKS_PER_SEC) return false;
    for(int i = 0; i < vec[x].size(); i++) {
        if(!(mask & vec[x][i].fi)) 
            if(dfs(x - d, num + 1, d, mask | vec[x][i].fi)) return true;
    }
    return false;
}

bool check(int c, int d) {
    for(int i = 0; i < k; i++) {
        if(vec[c + i * d].size() == 0) return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    srand(12345);
    while(T--) {
        cin >> n >> k;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        random_shuffle(a, a+n);
        if (k == 1) {
            cout <<0 <<endl;
            continue;
        }
        bool found = false;
        if (sum * 2 % k == 0) {
            init();
            for(int i = 1; i < 20001; i++) {
                sort(vec[i].begin(), vec[i].end(), cmp);
            }
            for(int d = 0; !found; d++) {
                int c = sum - (k - 1) * k * d / 2;
                if(c < 0) break;
                if(c % k != 0) continue;
                c /= k;
                st = clock();
                if(!check(c, d)) continue;
                if(dfs(c + (k - 1) * d, 0, d, 0)) {
                    found = true;
                    cout << d << endl;
                    break;
                }
            }
        }
        if(!found) puts("Impossible");
    }
    return 0;
}

