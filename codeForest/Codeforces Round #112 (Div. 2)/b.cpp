/*
 * Author:  Troy
 * Created Time:  2012/3/17 0:28:14
 * File Name: 
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

long long n, k;
bool check(long long v)
{
    long long ret = 0, c = 1;
    while (v >= c)
    {
        ret += (v / c);
        c *= k;
    }
    return ret >= n;
}
int main() 
{
    cin >>n >>k;
    long long lo = 1, hi = n+1, mid;
    while (lo + 1 < hi)
    {
        mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    if (check(lo)) cout <<lo <<endl;
    else if (check(mid)) cout <<mid <<endl;
    else cout <<hi <<endl;
    return 0;
}

