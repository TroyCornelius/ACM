/*
 * Author:  Troy
 * Created Time:  2012/9/15 21:04:21
 * File Name: 1005.cpp
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
#define Maxn 110
#define MaxT 26000
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
int a[Maxn], b[Maxn], t[Maxn];
int fun[Maxn][1100];
int ans[MaxT];
int main() {
    while (~sf("%d", &n)) {
        memset(fun, 0, sizeof(fun));
        REP(i, n) {
            sf("%d%d%d", &a[i], &b[i], &t[i]);
            fun[i][0] = a[i];
            for (int j = 1; j <= 35; ++j) {
                fun[i][j] = a[i] - (j - 1) * (j - 1) * b[i];
                if (fun[i][j] <= 0) {fun[i][j] = 0;break;}
                //cout <<fun[i][j] <<" ";
            }
            //cout <<endl;
        }
        memset(ans, 0, sizeof(ans));
        REP(i, n) {
            if (b[i] == 0) {
                for (int j = t[i]; j <= 25000; ++j) ans[j] = max(ans[j], ans[j-t[i]] + fun[i][0]); 
            }
            else {
                for (int k = 1; k <= 35 && fun[i][k] > 0; ++k) {
                    for (int j = 25000; j >= t[i]; --j)
                        ans[j] = max(ans[j], ans[j - t[i]] + fun[i][k]);
                }
            }
        }
        //REP(i, 20) cout <<ans[i] <<" ";
        //cout <<endl;
        int Q, x;
        sf("%d", &Q);
        while (Q--) {
            sf("%d", &x);
            pf("%d\n", ans[x]);
        }
    }
    return 0;
}

