/*
 * Author:  Troy
 * Created Time:  2012/4/2 12:31:56
 * File Name: 1004.cpp
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
#define Maxn 500100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
int a[Maxn];
bool check(int pop)
{
    int tot = m, tmp;
    REP(i, n)
    {
        tmp = a[i] / pop;
        if (a[i] % pop != 0) tmp++;
        tot -= tmp;
        if (tot < 0) return false;
    }
    return tot >= 0;
}
int main() 
{
    while (~sf("%d%d", &n, &m))
    {
        if (n == -1 && m == -1) break;
        REP(i, n) sf("%d", &a[i]);
        int lo = 0, hi = 5000001, mid;
        while (lo + 1 < hi)
        {
            mid = (lo + hi) >>1;
            if (check(mid)) hi = mid;
            else lo = mid;
        }
        if (check(lo)) pf("%d\n", lo);
        else if (check(mid)) pf("%d\n", mid);
        else pf("%d\n", hi);
        
    }
    return 0;
}

