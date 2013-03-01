/*
 * Author:  Troy
 * Created Time:  2012/11/10 21:42:07
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

const int mod = 20121111;
int n;
int main() {
    int T, ca = 0;
    cin >>T;
    while (T--) {
        cin >>n;
        if (n & 1) {
            if (n == 1) pf("Case #%d: 0\n", ++ca);
            else if (n == 3) pf("Case #%d: 1\n", ++ca);
            else if (n == 5) pf("Case #%d: 33\n", ++ca);
            else pf("Case #%d: %d\n", ++ca, 5*n % mod);
        }
        else {
            if (n == 2) pf("Case #%d: 0\n", ++ca);
            else if (n == 4) pf("Case #%d: 8\n", ++ca);
            else if (n == 6) pf("Case #%d: 32\n", ++ca);
            else pf("Case #%d: %d\n", ++ca, 5*n % mod);
        }
    }
    return 0;
}

