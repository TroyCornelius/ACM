/*
 * Author:  Troy
 * Created Time:  2012/11/10 19:25:20
 * File Name: f.cpp
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

const long long mod = 10000000007LL;
int n;
long long k, num;
inline long long calc(long long x) {
    long long t = x % mod, ret = 1, b = k;
    while (b) {
        if (b & 1) ret = (ret * t) % mod;
        t = (t * t) % mod;
        b >>= 1;
    }
    return ret % mod;
}
int main() {
    int T;
    cin >>T;
    long long ans;
    long long f;
    while (T--) {
        cin >>n >>k;
        ans = 0;
        REP(i, n) {
            cin >>num;
            f = 1;
            if (num < 0) f = -1, num = -num;
            if (k%2==0) f = 1;
            long long tmp = calc(num);
            tmp *= f;
            ans = ((ans + tmp) % mod + mod) % mod;
        }
        if (ans < 0)  ans = (ans + mod) % mod; 
        cout <<ans <<endl;
    }
    return 0;
}

