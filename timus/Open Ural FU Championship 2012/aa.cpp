/*
 * Author:  Troy
 * Created Time:  2012/11/10 16:01:50
 * File Name: aa.cpp
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
int n, val[100010];
int main() {
    while (~sf("%d", &n)) {
        for (int i = 1; i <= n; i++) sf("%d", &val[i]);
        int mx = 0, cur = 1, cnt = 0, ans_id = 1;
        for (int i = 2; i <= n; i++) {
            cnt++;
            if (cnt > mx) mx = cnt, ans_id = cur;
            if (val[i] < val[cur]) {
                cnt = 1;
                cur = i;
            }
        }
        pf("%d\n", ans_id);
    }
    return 0;
}

