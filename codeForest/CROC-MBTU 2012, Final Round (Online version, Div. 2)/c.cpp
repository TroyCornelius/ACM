/*
 * Author:  Troy
 * Created Time:  2012/11/27 23:42:01
 * File Name: c.cpp
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
#define Maxn 100010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, k;
int a[Maxn], cnt[Maxn], bet[Maxn];
int main() {
    sf("%d%d", &n, &k);
    REP(i, n) sf("%d", &a[i]);
    n = unique(a, a+n) - a;
    memset(cnt, 0, sizeof(cnt));
    memset(bet, 0, sizeof(bet));
    REP(i, n) cnt[a[i]]++;
    for (int i = 1; i < n - 1; i++ ) 
        if (a[i-1] == a[i+1]) bet[a[i]]++;
    
    int mi = maxint, ans = -1;
    for (int i = 1; i <= k; i++) {
        int tmp = n - 1 - cnt[i] - bet[i];    
        if (tmp < mi) mi = tmp, ans = i;
    }
    pf("%d\n", ans);
    
    return 0;
}

