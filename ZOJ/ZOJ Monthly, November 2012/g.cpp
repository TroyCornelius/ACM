/*
 * Author:  Troy
 * Created Time:  2012/11/25 15:10:44
 * File Name: g.cpp
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
#define Maxn 10020
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n;
long long a[Maxn], b[Maxn];
int main() {
    while (~sf("%d", &n)) {
        ll sum = 0, mx = 0;
        REP(i, n) {
            sf("%lld%lld", &a[i], &b[i]);
            sum += a[i] - b[i];
            mx = max(mx, a[i] - b[i]);
        }
        if (sum % 2 == 0 && mx <= sum / 2) puts("YES");
        else puts("NO");
        /*
        if (sum & 1) puts("NO");
        else {
            ll res = 0;
            bool ans = true;
            for (int i = n-1; i >= 0; i--) {
                if (a[i] > b[i]) {
                    sum -= a[i] - b[i];
                    ll tmp = a[i] - b[i];
                    if (sum - res == tmp) {
                        break;
                    }
                    else {
                        if (tmp + res <= sum) {
                            res += tmp;
                            sum -= tmp;
                            a[i] -= tmp;
                        }
                        else {
                            if (tmp - res > sum) {
                                ans = false;
                                break;
                            }
                            else {
                                ll x = tmp + res - sum;
                                res -= x / 2; a[i] -= x/2;
                                res += a[i] - b[i];
                                a[i] = b[i];
                            }
                            if (res == sum) break;
                        }
                    }
                }
            }     
            */
            //if (res != 0) ans = false;
            //if (ans) puts("YES");
            //else puts("NO");
        //}
    }
    return 0;
}

