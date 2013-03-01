/*
 * Author:  Troy
 * Created Time:  2012/4/3 13:18:13
 * File Name: j.cpp
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

int n;
pii ans;
int main() 
{
    int T;
    sf("%d", &T);
    while (T--)
    {
        sf("%d", &n);
        ans.fi = ans.se = -1;
        for (int i=1; i*i<=n; i++)
        if (n % i == 0)
        {
            int j = n / i;
            if ( (i + j) % 2 != 0) continue;
            int b = (i+j)/2;
            int a = j - b;
            if (a > b) swap(a, b);
            if (ans.se == -1 || ans.se > b) ans = mp(a, b);
        }
        if (ans.fi == -1) pf("IMPOSSIBLE\n");
        else pf("%d %d\n", ans.fi, ans.se);
            
    }
    return 0;
}

