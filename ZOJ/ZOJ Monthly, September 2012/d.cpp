/*
 * Author:  Troy
 * Created Time:  2012/9/29 13:30:15
 * File Name: d.cpp
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

long long ans;
long long C(int n) {
    return 1LL*n*(n-1)*(n-2)/6;
}
int main() {
    int n, m;
    while (cin >>n >>m) {
        n++; m++;
        int sum = n * m;
        ans = C(sum);
        if (m >= 3) ans -= 1LL * n * C(m);
        if (n >= 3) ans -= 1LL * m * C(n);
        long long s = 0;
        for (int i = 2; i < m; i++) {
            int y = i, x = n-1, cnt = 0;
            while (x >= 0 && y >= 0) x--, y--, cnt++;
            if (cnt >= 3) s += C(cnt);
        }
        for (int i = n - 2; i >= 2; i--) {
            int x = i, y = m-1, cnt = 0;
            while (x >= 0 && y >= 0) x--, y--, cnt++;
            if (cnt >= 3) s += C(cnt);
        }
        ans -= 2LL * s;
        cout <<ans <<endl;
    }
    return 0;
}

