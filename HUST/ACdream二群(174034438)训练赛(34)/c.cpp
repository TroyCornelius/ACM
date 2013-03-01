/*
 * Author:  Troy
 * Created Time:  2012/5/25 20:27:50
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int a[800], ans, n;
int main() 
{
    int T;
    sf("%d", &T);
    while (T--)
    {
        sf("%d", &n);
        REP(i, n) sf("%d", &a[i]);
        ans = maxint;
        int sum;
        REP(i, n)
        {
            sum = 0;
            REP(j, n) sum += abs(a[i] - a[j]);
        if (sum < ans) ans = sum;
        }
        pf("%d\n", ans);
    }
    return 0;
}

