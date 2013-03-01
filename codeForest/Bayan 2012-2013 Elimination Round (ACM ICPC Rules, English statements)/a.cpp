/*
 * Author:  Troy
 * Created Time:  2012/11/1 23:27:42
 * File Name: a.cpp
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

int n, k;
int d[1010], s[1010];
int main() {
    while (cin >>n >>k) {
        REP(i, n) cin >>d[i];
        REP(i, n) cin >>s[i];
        int ans = 0;
        int now = s[0], mx = s[0];
        int i = 0;
        while (i < n) {
            mx = max(mx, s[i]);
            if (now >= d[i]) {
                now -= d[i];
                ans += d[i];
                i++;
                now += s[i];
                continue;
            }
            else {
                ans += k;
                now += mx;
            }
        }
        cout <<ans <<endl;
    }
    return 0;
}

