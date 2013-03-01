/*
 * Author:  Troy
 * Created Time:  2012/5/21 23:48:05
 * File Name: dd.cpp
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

int n, k, a[400010];
map<int,int> cnt;
int main() 
{
    sf("%d%d", &n, &k);
    REP(i, n) sf("%d", &a[i]);
    long long ans = 1LL * n * (n + 1) / 2;
    int j = n;
    FORD(i, n-1, 0)
    {
        cnt[a[i]]++;
        while (cnt[a[i]] >= k) cnt[a[--j]]--;
        ans -= j - i;
    }
    cout <<ans <<endl;
    return 0;
}

