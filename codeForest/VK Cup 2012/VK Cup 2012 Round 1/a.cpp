/*
 * Author:  Troy
 * Created Time:  2012/3/11 22:59:08
 * File Name: a.cpp
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

int n, m, x, y;
int a[Maxn], b[Maxn];
vector<pii> ans;
int main() 
{
    scanf("%d%d%d%d", &n, &m, &x, &y);
    REP(i, n) scanf("%d", &a[i]);
    REP(i, m) scanf("%d", &b[i]);
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (b[j] >= a[i]-x && b[j] <= a[i]+y)
        {
            ans.pb(mp(i+1, j+1));
            i++; j++;
        }
        else
        if (b[j] < a[i] - x) j++;
        else
        if (b[j] > a[i] + y) i++;        
    }
    printf("%d\n", ans.size());
    REP(i, ans.size()) printf("%d %d\n", ans[i].fi, ans[i].se);
    
    return 0;
}

