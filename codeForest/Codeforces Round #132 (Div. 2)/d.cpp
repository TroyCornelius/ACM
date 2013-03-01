/*
 * Author:  Troy
 * Created Time:  2012/8/7 0:20:34
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
#define Maxn 100100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
int t[Maxn], lim[Maxn], x[Maxn], cost[Maxn];
int main() 
{
    sf("%d%d", &n, &m);
    REP(i, n) sf("%d%d%d%d", &t[i], &lim[i], &x[i], &cost[i]);
    long long ans = 0;
    REP(i, n)
    {
        if (lim[i] <= t[i])
        {
            ans += 1LL * m * x[i] + cost[i];
        }
        else
        {
            int k = m / (lim[i] - t[i]);
            if (m % (lim[i] - t[i]) != 0) k++;
            long long s1 = 1LL * k * cost[i];
            long long s2 = cost[i] + 1LL * m * x[i];
            ans += min(s1, s2);
        }
    }
    cout <<ans <<endl;
    return 0;
}

