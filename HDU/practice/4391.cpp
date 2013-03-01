/*
 * Author:  Troy
 * Created Time:  2012/8/23 22:40:57
 * File Name: 4391.cpp
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
#define Maxn 100010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
int val[Maxn];
int col[350], k;

const int MOD = 20023;
bool bhash[340][MOD];
int vhash[340][MOD];
int cnt[340][MOD];
bool find_hash(int idx, int & pos) {
    int val = pos;
    pos %= MOD;
    for (; bhash[idx][pos]; pos=(pos+1)%MOD) {
        if (vhash[idx][pos] == val)
            return true;
    }
    return false;
}
int make_hash(int idx, int val) {
    int pos = val;
    if (! find_hash(idx, pos)) {
        bhash[idx][pos] = true;
        vhash[idx][pos] = val;
        cnt[idx][pos] = 0;
    }
    cnt[idx][pos] ++;
    return pos;
}
int search(int idx, int val) {
    int pos = val;
    if (!find_hash(idx, pos)) return 0;
    else return cnt[idx][pos];
}
int tot;
 
int main() {
    int type, a, b, z;
    while (~sf("%d%d", &n, &m)) {
        REP(i, n) sf("%d", &val[i]);
        
        k = (int)(sqrt(1.0*n));
        tot = 0;
        for (int i = 0, j = -1; i < n; i++) {
            if (i % k == 0) {
                j++;
                tot = j;
                memset(bhash[j], false, sizeof(bhash[j]));
                memset(cnt[j], 0, sizeof(cnt[j]));
                col[j] = -1;
            }
            make_hash(j, val[i]);
        }
        while (m--) {
            sf("%d%d%d%d", &type, &a, &b, &z);
            if (type == 1) {
                for (int i = a / k, l = a/k*k; i <= tot; i++, l += k) {
                    if (l > b) break;
                    else
                        if (l < a || b < l+k-1) {
                            col[i] = -1;
                            memset(bhash[i], false, sizeof(bhash[i]));
                            memset(cnt[i], 0, sizeof(cnt[i]));
                            for (int j = l; j < a; j++) make_hash(i, val[j]);
                            for (int j = max(l, a); j <= min(l+k-1, b); j++) {
                                make_hash(i, z);
                                val[j] = z;
                            }
                        }
                        else
                            if (l + k - 1 <= b) col[i] = z;
                }
            }
            else {
                int ans = 0;
                for (int i = a / k, l = a/k*k; i <= tot; i++, l += k) {
                    if (l > b) break;
                    else
                        if (l < a || b < l+k-1) {
                            for (int j = l; j < a; j++)
                                if (val[j] == z) ans++;
                            for (int j = max(l, a); j <= min(l+k-1, b); j++)
                                if (val[j] == z) ans++;
                        }
                        else
                            if (l + k - 1 <= b) {
                                if (col[i] == z) ans += k;
                                else if (col[i] == -1) ans += search(i, z);
                            }
                    cout <<i <<" " <<l <<" "<<l+k-1 <<" -- " <<a <<" "<<b <<" "<<ans <<endl;
                }
                pf("%d\n", ans);
            }
        }
    }
    return 0;
}

