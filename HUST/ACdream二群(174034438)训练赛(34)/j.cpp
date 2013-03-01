/*
 * Author:  Troy
 * Created Time:  2012/5/25 20:36:35
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
#define Maxn 100010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, a[Maxn], ans;
int work()
{
    int ret = 0;
    if (n == 1) return 1;
    int p = 1;
    while (p < n)
    {
        ret++;
        //cout <<p <<" "<<a[p] <<endl;
        while (p < n && a[p] == a[p - 1]) p++;
        if (a[p] > a[p-1])
        {
            while (p < n && a[p] >= a[p-1]) p++;
            if (p == n-1) return ret + 1;
            p++;
        }
        else
        {
            while (p < n && a[p] <= a[p-1]) p++;
            if (p == n-1) return ret + 1;
            p++;
        }
    }
    return ret;
}
int main() 
{
    int a1, b;
    while (~sf("%d%d", &a1, &b))
    {
        n = b - a1 + 1;
        REP(i, n) sf("%d", &a[i]);
        ans = work();
        pf("%d\n", ans);
    }
    return 0;
}

