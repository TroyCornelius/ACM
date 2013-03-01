/*
 * Author:  Troy
 * Created Time:  2012/2/20 23:23:36
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
#define along long(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
long long n, m;
long long sx, sy;
long long x, y;
int k;
bool check(long long x, long long y)
{
    if(x > 0 && x <= n && y > 0 && y <= m) return true;
    return false;
}

long long solve() {
    long long lo = 0, ri = 10000000000LL;
    long long res = 0;
    while(lo <= ri) {
        long long mid = (lo + ri) / 2;
        if(check(sx + mid * x, sy + mid * y)) 
        {
            res = mid;
            lo = mid + 1;
        } 
        else ri = mid - 1;
    }
    return res;
}

int main() 
{
    cin >>n >>m;
    long long ans = 0;
    cin >> sx >> sy;
    cin >> k;
    REP(i, k)
    {
        cin >> x >> y;
        long long tmp = solve();
        sx += tmp * x, sy += tmp * y;
        ans += tmp;
    }
    cout << ans << endl;
    
    return 0;
}

