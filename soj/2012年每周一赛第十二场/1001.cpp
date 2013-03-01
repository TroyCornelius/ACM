/*
 * Author:  Troy
 * Created Time:  2012/11/3 19:50:06
 * File Name: 1001.cpp
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
#define Maxn 500010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, a[Maxn], b[Maxn];
int tot, ans[Maxn];
int main() {
    while (~sf("%d", &n)) {
        for (int i = 1; i <= n; i++) {
            sf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b+1, b+n+1);
        tot = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) ans[tot++] = i;
        }
    }
    return 0;
}

