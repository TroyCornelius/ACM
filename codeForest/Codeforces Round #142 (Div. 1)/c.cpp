/*
 * Author:  Troy
 * Created Time:  2012/10/2 0:08:50
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
#define sf scanf
#define pf printf
#define Maxn 1000010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m, cnt[Maxn];
long long ans;
int main() {
    int u, v;
    sf("%d%d", &n, &m);
    if (n < 3) {
        puts("0");
    }
    else {
        memset(cnt, 0, sizeof(cnt));
        ans = (1LL * n * (n - 1) / 2 )* (n - 2) / 3;
        REP(i, m) {
            sf("%d%d", &u, &v);
            cnt[u]++; cnt[v]++;
        }
        long long sum = 0;
        FOR(i, 1, n+1)
            sum += 1LL * cnt[i] * (n - 1 - cnt[i]);
        ans -= sum / 2;
        cout <<ans <<endl;
    }
    return 0;
}

