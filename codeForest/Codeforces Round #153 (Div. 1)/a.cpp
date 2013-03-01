/*
 * Author:  Troy
 * Created Time:  2012/12/6 23:31:10
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
const int N = 100010;
int n;
ll d, x[N];

int bs(int idx) {
    int l = idx + 1, r = n - 1;
    int ret = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(x[mid] - x[idx] <= d) {
            ret = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ret;
}

int main() {
    cin >>n >>d;
    for(int i = 0; i < n; i++) cin >> x[i];
    sort(x, x + n);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int ret = bs(i);
        if(ret == -1) continue;
        ll tmp = ret - i;
        ans += tmp * (tmp - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}

