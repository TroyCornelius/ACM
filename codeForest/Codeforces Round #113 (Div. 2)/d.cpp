/*
 * Author:  Troy
 * Created Time:  2012/3/24 0:26:51
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
#define Maxn 100100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
pii sho[Maxn], cus[Maxn];
pair<long long, int> dp[Maxn][3];
bool cmp(const pii &a, const pii &b)
{
    return a.se < b.se;
}
int main() 
{
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", &sho[i].fi, &sho[i].se);
    scanf("%d", &m);
    REP(i, m) scanf("%d%d", &cus[i].fi, &cus[i].se);
    sort(sho, sho+n, cmp);
    sort(cus, cus+m, cmp);
    int p = 0;
    REP(i, n)
    
    return 0;
}

